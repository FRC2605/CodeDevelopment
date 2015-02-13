#include "Nav6.h"
#include "Nav6Protocol.h"
#include "../../Timing/IntervalTimer.h"

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>

Nav6 :: Nav6 ( ISerialInterface * Serial, uint8_t UpdateRate ):
	StopRequested ( false ),
	Serial ( Serial ),
	UpdateRate ( UpdateRate ),
	Yaw ( 0 ),
	Pitch ( 0 ),
	Roll ( 0 ),
	Gravity ( 0.0, 0.0, 0.0 ),
	Acceleration ( 0.0, 0.0, 0.0 ),
	AFS ( 2 ),
	CompassHeading ( 0 ),
	Orientation (),
	SerialUpdateClosure ( & Nav6 :: SerialUpdate, this ),
	SerialThread ( & SerialUpdateClosure, false, 20, Thread :: kSchedulingPolicy_RoundRobin ),
	StoppedCondition ( true )
{
	
	SerialThread.SetName ( "FRC_NAV6" );
	
};

Nav6 :: ~Nav6 ()
{
	
	
	
};

void Nav6 :: Start ()
{
	
	StopRequested = false;
	
	StoppedCondition.PreLock ();
	StoppedCondition.Reset ();
	
	if ( SerialThread.GetState () == Thread :: kThreadState_Stopped )
		SerialThread.Start ();
	
	StoppedCondition.Unlock ();
	
};

void Nav6 :: Stop ( bool Wait )
{
	
	if ( SerialThread.GetState () == Thread :: kThreadState_Running )
		StopRequested = true;
	
	if ( Wait )
	{
		
		StoppedCondition.LockWait ();
		StoppedCondition.Reset ();
		StoppedCondition.Unlock ();
		
	}
	
};

double Nav6 :: GetYaw ()
{
	
	return Yaw;
	
};

double Nav6 :: GetPitch ()
{
	
	return Pitch;
	
};

double Nav6 :: GetRoll ()
{
	
	return Roll;
	
};

double Nav6 :: GetCompassHeading ()
{
	
	return CompassHeading;
	
};

void Nav6 :: SendStreamCommand ( uint8_t UpdateRate )
{
	
	std :: cout << "STREAM COMMAND!\n";
	
	uint8_t Buff [ 9 ];
	
	Buff [ 0 ] = PACKET_START_CHAR;
	Buff [ 1 ] = MSGID_STREAM_CMD;
	Buff [ 2 ] = STREAM_CMD_STREAM_TYPE_QUATERNION;
	SetStreamUint8 ( Buff, 3, UpdateRate );
	
	SetStreamTermination ( Buff, 5 );
	
	Serial -> Write ( Buff, 9 );
	Serial -> Flush ();
	Serial -> Reset ();
	
};

uint8_t Nav6 :: CalculateChecksum ( uint8_t * Buffer, uint32_t Length )
{
	
	uint8_t Sum = 0;
	
	for ( uint32_t i = 0; i < Length; i ++ )
		Sum += Buffer [ i ];
	
	return Sum;
	
};

void Nav6 :: SetStreamUint8 ( uint8_t * Buffer, uint32_t Index, uint8_t Value )
{
	
	const char * HexRef = "0123456789ABCDEF";
	
	Buffer [ Index + 1 ] = static_cast <uint8_t> ( HexRef [ Value & 0x0F ] );
	Buffer [ Index ] = static_cast <uint8_t> ( HexRef [ Value >> 4 ] );
	
};

void Nav6 :: SetStreamUint16 ( uint8_t * Buffer, uint32_t Index, uint16_t Value )
{
	
	const char * HexRef = "0123456789ABCDEF";
	
	Buffer [ Index + 3 ] = static_cast <uint8_t> ( HexRef [ Value & 0x000F ] );
	Buffer [ Index + 2 ] = static_cast <uint8_t> ( HexRef [ ( Value >> 4 ) & 0x000F ] );
	Buffer [ Index + 1 ] = static_cast <uint8_t> ( HexRef [ ( Value >> 8 ) & 0x000F ] );
	Buffer [ Index ] = static_cast <uint8_t> ( HexRef [ ( Value >> 12 ) & 0x000F ] );
	
};

void Nav6 :: SetStreamFloat ( uint8_t * Buffer, uint32_t Index, double Value )
{
	
	const char * DecRef = "0123456789";
	
	Buffer [ Index ] = Value > 0 ? '+' : '-';
	
	if ( Value < 0 )
		Value = - Value;
	
	Buffer [ Index + 1 ] = static_cast <uint8_t> ( DecRef [ static_cast <uint32_t> ( fmod ( Value * 100.0, 10.0 ) ) ] );
	Buffer [ Index + 2 ] = static_cast <uint8_t> ( DecRef [ static_cast <uint32_t> ( fmod ( Value * 10.0, 10.0 ) ) ] );
	Buffer [ Index + 3 ] = static_cast <uint8_t> ( DecRef [ static_cast <uint32_t> ( fmod ( Value, 10.0 ) ) ] );
	Buffer [ Index + 4 ] = static_cast <uint8_t> ( '.' );
	Buffer [ Index + 5 ] = static_cast <uint8_t> ( DecRef [ static_cast <uint32_t> ( fmod ( Value / 10.0, 10.0 ) ) ] );
	Buffer [ Index + 6 ] = static_cast <uint8_t> ( DecRef [ static_cast <uint32_t> ( fmod ( Value / 100.0, 10.0 ) ) ] );
	
};

uint8_t Nav6 :: GetStreamUint8 ( uint8_t * Buffer, uint32_t Index )
{
	
	const uint8_t ZeroRef = static_cast <uint8_t> ( '0' );
	const uint8_t NineRef = static_cast <uint8_t> ( '9' );
	const uint8_t ARef = static_cast <uint8_t> ( 'A' );
	
	uint8_t Value;
	
	if ( Buffer [ Index ] >= ZeroRef && Buffer [ Index ] <= NineRef )
		Value = ( Buffer [ Index ] - ZeroRef ) << 4;
	else
		Value = ( ( Buffer [ Index ] - ARef ) + 10 ) << 4;
	
	if ( Buffer [ Index ] >= ZeroRef && Buffer [ Index + 1 ] <= NineRef )
		Value += Buffer [ Index + 1 ] - ZeroRef;
	else
		Value += ( Buffer [ Index + 1 ] - ARef ) + 10;
	
	return Value;
	
};

int8_t Nav6 :: GetStreamInt8 ( uint8_t * Buffer, uint32_t Index )
{
	
	return static_cast <int8_t> ( GetStreamUint8 ( Buffer, Index ) );
	
};

uint16_t Nav6 :: GetStreamUint16 ( uint8_t * Buffer, uint32_t Index )
{
	
	uint16_t Value = GetStreamUint8 ( Buffer, Index ) << 8;
	Value += GetStreamUint8 ( Buffer, Index + 2 );
	
	return Value;
	
};

int16_t Nav6 :: GetStreamInt16 ( uint8_t * Buffer, uint32_t Index )
{
	
	return static_cast <int16_t> ( GetStreamUint16 ( Buffer, Index ) );
	
};

double Nav6 :: GetStreamNumber ( uint8_t * Buffer, uint32_t Index )
{
	
	const uint8_t ZeroRef = static_cast <uint8_t> ( '0' );
	const uint8_t MinusRef = static_cast <uint8_t> ( '-' );
	
	bool Sign = ( Buffer [ Index ] == MinusRef );
	
	double Value = ( Buffer [ Index + 6 ] - ZeroRef ) / 100;
	Value += ( Buffer [ Index + 5 ] - ZeroRef ) / 10;
	Value += ( Buffer [ Index + 3 ] - ZeroRef );
	Value += ( Buffer [ Index + 2 ] - ZeroRef ) * 10;
	Value += ( Buffer [ Index + 1 ] - ZeroRef ) * 100;
	
	if ( Sign )
		Value = - Value;
	
	return Value;
	
};

void Nav6 :: SetStreamTermination ( uint8_t * Buffer, uint32_t MessageLength )
{
	
	SetStreamUint8 ( Buffer, MessageLength, CalculateChecksum ( Buffer, MessageLength ) );
	
	Buffer [ MessageLength + 2 ] = '\r';
	Buffer [ MessageLength + 3 ] = '\n';
	Buffer [ MessageLength + 4 ] = '\0';
	
};

#define SERIAL_BUFF 256

void Nav6 :: SerialUpdate ( Thread * UpdateThread )
{
	
	IntervalTimer Timeout;
	
	uint8_t Buffer [ SERIAL_BUFF ];
	int32_t Offset = 0;
		
	Serial -> SetTimeoutMS ( 20000 );
	
	Serial -> Open ();
	Serial -> Reset ();
	
	SendStreamCommand ( UpdateRate );
	
	Timeout.Start ();
	
	while ( ! StopRequested )
	{
		
		if ( Timeout.GetTimeMS () > 3000 )
		{
			
			SendStreamCommand ( UpdateRate );
			
			Timeout.Restart ();
			
			Offset = 0;
			
		}
		
		Offset += Serial -> Read ( & Buffer [ Offset ], SERIAL_BUFF - Offset, - 1, false );
		
		int32_t i = 0;
		
		while ( i < Offset )
		{
			
			int DecodeOffset;
			
			DecodeOffset = DecodeQuaternionResponse ( & Buffer [ i ], Offset - i );
			
			if ( DecodeOffset != - 1 )
			{
				
				for ( int32_t o = i; o < Offset - ( i + DecodeOffset ); o ++ )
					Buffer [ o ] = Buffer [ o + DecodeOffset ];
				
				Offset -= DecodeOffset;
				
				Timeout.Restart ();
				
				continue;
				
			}
			
			DecodeOffset = DecodeRegularResponse (  & Buffer  [ i ], Offset - i );
			
			if ( DecodeOffset != - 1 )
			{
				
				for ( int32_t o = i; o < Offset - ( i + DecodeOffset ); o ++ )
					Buffer [ o ] = Buffer [ o + DecodeOffset ];
				
				Offset -= DecodeOffset;
				
				Timeout.Restart ();
				
				continue;
			
			}
			
			i ++;
			
			if ( i == SERIAL_BUFF - 1 )
				Serial -> Reset ();
			
		}
		
	}
	
	StopRequested = false;
	
	StoppedCondition.Signal ();
	
};

int32_t Nav6 :: DecodeRegularResponse ( uint8_t * Buffer, int32_t Length )
{
	
	if ( Length < STREAM_RESPONSE_MESSAGE_LENGTH )
		return - 1;
	
	if ( ( Buffer [ 0 ] != PACKET_START_CHAR ) || ( Buffer [ 1 ] != MSG_ID_STREAM_RESPONSE ) )
		return - 1;
	
	if ( CalculateChecksum ( Buffer, STREAM_RESPONSE_CHECKSUM_INDEX ) != GetStreamUint8 ( Buffer, STREAM_RESPONSE_CHECKSUM_INDEX ) )
		return - 1;
	
	AFS = static_cast <double> ( GetStreamInt16 ( Buffer, STREAM_RESPONSE_ACCEL_FULL_SCALE_G_RANGE ) ) / 16384.0;
	
	// TODO: FINISH
	
	return STREAM_RESPONSE_MESSAGE_LENGTH;
	
};

int32_t Nav6 :: DecodeQuaternionResponse ( uint8_t * Buffer, int32_t Length )
{
	
	if ( Length < QUATERNION_UPDATE_MESSAGE_LENGTH )
		return - 1;
	
	if ( ( Buffer [ 0 ] != PACKET_START_CHAR ) || ( Buffer [ 1 ] != MSGID_QUATERNION_UPDATE ) )
		return - 1;
	
	if ( CalculateChecksum ( Buffer, QUATERNION_UPDATE_CHECKSUM_INDEX ) != GetStreamUint8 ( Buffer, QUATERNION_UPDATE_CHECKSUM_INDEX ) )
		return - 1;
	
	Orientation.W = static_cast <double> ( GetStreamInt16 ( Buffer, QUATERNION_UPDATE_QUAT1_VALUE_INDEX ) ) / 16384.0;
	Orientation.X = static_cast <double> ( GetStreamInt16 ( Buffer, QUATERNION_UPDATE_QUAT2_VALUE_INDEX ) ) / 16384.0;
	Orientation.Y = static_cast <double> ( GetStreamInt16 ( Buffer, QUATERNION_UPDATE_QUAT3_VALUE_INDEX ) ) / 16384.0;
	Orientation.Z = static_cast <double> ( GetStreamInt16 ( Buffer, QUATERNION_UPDATE_QUAT4_VALUE_INDEX ) ) / 16384.0;
	
	if ( Orientation.W >= 2.0 )
		Orientation.W -= 4.0;
	
	if ( Orientation.X >= 2.0 )
		Orientation.X -= 4.0;
	
	if ( Orientation.Y >= 2.0 )
		Orientation.Y -= 4.0;
	
	if ( Orientation.Z >= 2.0 )
		Orientation.Z -= 4.0;
	
	Gravity.X = 2.0 * ( Orientation.X * Orientation.Z - Orientation.W * Orientation.Y );
	Gravity.Y = 2.0 * ( Orientation.W * Orientation.X + Orientation.Y * Orientation.Z );
	Gravity.Z = Orientation.W * Orientation.W - Orientation.X * Orientation.X - Orientation.Y * Orientation.Y + Orientation.Z * Orientation.Z;
	
	Yaw = atan2 ( 2 * ( Orientation.X * Orientation.Y - Orientation.W * Orientation.Z ), 2 * ( Orientation.W * Orientation.W + Orientation.X * Orientation.X ) - 1 );
	Pitch = atan ( Gravity.X / sqrt ( Gravity.Y * Gravity.Y + Gravity.Z * Gravity.Z ) );
	Roll = atan ( Gravity.Y / sqrt ( Gravity.X * Gravity.X + Gravity.Z * Gravity.Z ) );
	
	if ( Yaw > M_PI )
		Yaw -= M_PI * 2.0;
	if ( Yaw < - M_PI )
		Yaw += M_PI * 2.0;
	
	Acceleration.X = static_cast <double> ( GetStreamInt16 ( Buffer, QUATERNION_UPDATE_ACCEL_X_VALUE_INDEX ) ) * AFS / 32768.0 - Gravity.X;
	Acceleration.Y = static_cast <double> ( GetStreamInt16 ( Buffer, QUATERNION_UPDATE_ACCEL_Y_VALUE_INDEX ) ) * AFS / 32768.0 - Gravity.Y;
	Acceleration.Z = static_cast <double> ( GetStreamInt16 ( Buffer, QUATERNION_UPDATE_ACCEL_Z_VALUE_INDEX ) ) * AFS / 32768.0 - Gravity.Z;
	
	Vector3 Magneto;
	
	Magneto.X = static_cast <double> ( GetStreamInt16 ( Buffer, QUATERNION_UPDATE_MAG_X_VALUE_INDEX ) );
	Magneto.Y = static_cast <double> ( GetStreamInt16 ( Buffer, QUATERNION_UPDATE_MAG_Y_VALUE_INDEX ) );
	Magneto.Z = static_cast <double> ( GetStreamInt16 ( Buffer, QUATERNION_UPDATE_MAG_Z_VALUE_INDEX ) );
	
	double RollCos = cos ( Roll );
	double RollSin = sin ( Roll );
	double PitchCos = cos ( Pitch );
	double PitchSin = sin ( Pitch );
	
	//mag_x * sin_roll * sin_pitch + mag_y * cos_roll - mag_z * sin_roll * cos_pitch;
	CompassHeading = atan2 ( Magneto.X * PitchCos + Magneto.Z * PitchSin, Magneto.X * RollSin * PitchSin + Magneto.Y * RollCos - Magneto.Z * RollSin * PitchCos );
	
	CompassHeading -= M_PI * 0.5;
	if ( CompassHeading < M_PI )
		CompassHeading += M_PI * 2.0;
	
	return QUATERNION_UPDATE_MESSAGE_LENGTH;
	
};
