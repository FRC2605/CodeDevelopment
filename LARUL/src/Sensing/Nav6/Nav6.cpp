#include "Nav6.h"
#include "Nav6Protocol.h"

#include <stdlib.h>
#include <math.h>

Nav6 :: Nav6 ( ISerialInterface * Serial, uint8_t UpdateRate ):
	Serial ( Serial ),
	UpdateRate ( UpdateRate ),
	Yaw ( 0 ),
	Pitch ( 0 ),
	Roll ( 0 ),
	AX ( 0 ),
	AY ( 0 ),
	AZ ( 0 ),
	CompassHeading ( 0 ),
	SerialUpdateClosure ( & Nav6 :: SerialUpdate, this ),
	SerialThread ( & SerialUpdateClosure )
{
};

Nav6 :: ~Nav6 ()
{
	
	
	
};

void Nav6 :: Start ()
{
	
	
	
};

void Nav6 :: Stop ()
{
	
	
	
};

double Nav6 :: GetYaw ()
{
	
	
	
};

double Nav6 :: GetPitch ()
{
	
	
	
};

double Nav6 :: GetRoll ()
{
	
	
	
};

double Nav6 :: GetCompassHeading ()
{
	
	
	
};

void Nav6 :: SendStreamCommand ( uint8_t UpdateRate )
{
	
	uint8_t Buff [ 8 ];
	
	Buff [ 0 ] = PACKET_START_CHAR;
	Buff [ 1 ] = MSGID_STREAM_CMD;
	
	Buff [ 2 ] = STREAM_CMD_STREAM_TYPE_QUATERNION;
	
	
	
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
	
	Buffer [ MessageLength ] = CalculateChecksum ( Buffer, MessageLength );
	Buffer [ MessageLength + 1 ] = '\r';
	Buffer [ MessageLength + 2 ] = '\n';
	Buffer [ MessageLength + 3 ] = '\0';
	
};

void Nav6 :: SerialUpdate ( Thread * UpdateThread )
{
	
	
	
};
