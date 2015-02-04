#include <Hardware/Drive/MecanumDrive.h>
#include <math.h>

/*
* Copyright (C) 2015 Liam Taylor
* WheelFRC Team Sehome Semonsters 2605
*/

MecanumDrive :: MecMotorStruct :: MecMotorStruct ( SpeedController * Motor ):
	Motor ( Motor ),
	Inverted ( false )
{
};

MecanumDrive :: MecanumDrive ( SpeedController * WheelFL, SpeedController * WheelFR, SpeedController * WheelRL, SpeedController * WheelRR ):
	MotorFL ( WheelFL ),
	MotorFR ( WheelFR ),
	MotorRL ( WheelRL ),
	MotorRR ( WheelRR ),
	TX ( 0 ),
	TY ( 0 ),
	TR ( 0 ),
	Scale ( 1 ),
	PrescaleR ( 1 ),
	PrescaleT ( 1 ),
	Enabled ( false ),
	SineInverted ( false ),
	XYFilters (),
	MDFilters (),
	RFilters ()
{
};

MecanumDrive :: ~MecanumDrive () {};

void MecanumDrive :: SetMotors ( SpeedController * WheelFL, SpeedController * WheelFR, SpeedController * WheelRL, SpeedController * WheelRR )
{
	
	if ( Enabled )
		return;

	MotorFL.Motor = WheelFL;
	MotorFR.Motor = WheelFR;
	MotorRL.Motor = WheelRL;
	MotorRR.Motor = WheelRR;
	
};

void MecanumDrive :: SetInverted ( bool WheelFL, bool WheelFR, bool WheelRL, bool WheelRR )
{
	
	if ( Enabled )
		return;

	MotorFL.Inverted = WheelFL;
	MotorFR.Inverted = WheelFR;
	MotorRL.Inverted = WheelRL;
	MotorRR.Inverted = WheelRR;
	
};

bool MecanumDrive :: Enable ()
{
	
	if ( MotorFL.Motor == NULL || MotorFR.Motor == NULL || MotorRL.Motor == NULL || MotorRR.Motor == NULL )
		return false;
	
	uint32_t i;
	
	for ( i = 0; i < XYFilters.Length (); i ++ )
		RFilters [ i ] -> Reset ();
	
	for ( i = 0; i < RFilters.Length (); i ++ )
		XYFilters [ i ] -> Reset ();
	
	for ( i = 0; i < MDFilters.Length (); i ++ )
		MDFilters [ i ] -> Reset ();

	Enabled = true;
	return true;
	
};

void MecanumDrive :: Disable ()
{
	
	Enabled = false;
	
	TX = 0;
	TY = 0;
	TR = 0;
	
	PushTransform ();
	
};

bool MecanumDrive :: GetEnabled ()
{
	
	return Enabled;
	
};

void MecanumDrive :: PushTransform ()
{
	
	double ForceAngle;
	double ForceMagnitude;
	double SinCalc;
	double CosCalc;
	double LX;
	double LY;
	double LR;
	uint32_t i;
	
	if ( ! Enabled )
	{

		MotorFL.Motor -> Set ( 0 );
		MotorFR.Motor -> Set ( 0 );
		MotorRL.Motor -> Set ( 0 );
		MotorRR.Motor -> Set ( 0 );
		
		return;
	
	}
	
	LX = TX;
	LY = TY;
	LR = TR;
	
	for ( i = 0; i < XYFilters.Length (); i ++ )
	{
		
		DSPFilter_2_2 * XYFilter = XYFilters [ i ];
		
		XYFilter -> Compute ( LX, LY );
		LX = XYFilter -> ReadA ();
		LY = XYFilter -> ReadB ();
		
	}
	
	for ( i = 0; i < RFilters.Length (); i ++ )
	{
		
		DSPFilter_1_1 * RFilter = RFilters [ i ];
		
		RFilter -> Compute ( LR );
		LR = RFilter -> Read ();
		
	}
		
	ForceMagnitude = sqrt ( LX * LX + LY * LY );
	
	ForceAngle = atan2 ( LX, LY );
	ForceAngle += PI_Div_4;
	
	for ( i = 0; i < MDFilters.Length (); i ++ )
	{
		
		DSPFilter_2_2 * MagDirFilter = MDFilters [ i ];
		
		MagDirFilter -> Compute ( ForceMagnitude, ForceAngle );
		ForceMagnitude = MagDirFilter -> ReadA ();
		ForceAngle = MagDirFilter -> ReadB ();
		
	}
	
	SinCalc = sin ( ForceAngle ) * ForceMagnitude;
	CosCalc = cos ( ForceAngle ) * ForceMagnitude;

	MotorFL.Motor -> Set ( ( ( SineInverted ? CosCalc : SinCalc ) + LR ) * ( MotorFL.Inverted ? - Scale : Scale ) );
	MotorFR.Motor -> Set ( ( ( SineInverted ? SinCalc : CosCalc ) - LR ) * ( MotorFR.Inverted ? - Scale : Scale ) );
	MotorRL.Motor -> Set ( ( ( SineInverted ? SinCalc : CosCalc ) + LR ) * ( MotorRL.Inverted ? - Scale : Scale ) );
	MotorRR.Motor -> Set ( ( ( SineInverted ? CosCalc : SinCalc ) - LR ) * ( MotorRR.Inverted ? - Scale : Scale ) );
	
};

void MecanumDrive :: DebugValues ()
{
	
	double ForceAngle;
	double ForceMagnitude;
	double SinCalc;
	double CosCalc;
	uint32_t i;
	
	double FL, FR, RL, RR;
	
	double LX = TX;
	double LY = TY;
	double LR = TR;
	
	for ( i = 0; i < XYFilters.Length (); i ++ )
	{
		
		DSPFilter_2_2 * XYFilter = XYFilters [ i ];
		
		XYFilter -> Compute ( LX, LY );
		LX = XYFilter -> ReadA ();
		LY = XYFilter -> ReadB ();
		
	}
	
	for ( i = 0; i < RFilters.Length (); i ++ )
	{
		
		DSPFilter_1_1 * RFilter = RFilters [ i ];
		
		RFilter -> Compute ( LR );
		LR = RFilter -> Read ();
		
	}
		
	ForceMagnitude = sqrt ( LX * LX + LY * LY );
	
	ForceAngle = atan2 ( LX, LY );
	ForceAngle += PI_Div_4;
	
	for ( i = 0; i < MDFilters.Length (); i ++ )
	{
		
		DSPFilter_2_2 * MagDirFilter = MDFilters [ i ];
		
		MagDirFilter -> Compute ( ForceMagnitude, ForceAngle );
		ForceMagnitude = MagDirFilter -> ReadA ();
		ForceAngle = MagDirFilter -> ReadB ();
		
	}
	
	SinCalc = sin ( ForceAngle ) * ForceMagnitude;
	CosCalc = cos ( ForceAngle ) * ForceMagnitude;
	
	FL = ( ( SineInverted ? CosCalc : SinCalc ) + LR ) * ( MotorFL.Inverted ? - Scale : Scale );
	FR = ( ( SineInverted ? SinCalc : CosCalc ) - LR ) * ( MotorFR.Inverted ? - Scale : Scale );
	RL = ( ( SineInverted ? SinCalc : CosCalc ) + LR ) * ( MotorRL.Inverted ? - Scale : Scale );
	RR = ( ( SineInverted ? CosCalc : SinCalc ) - LR ) * ( MotorRR.Inverted ? - Scale : Scale );
	
	printf ( "[ Mecanum Drive Debug ]\n%s\nInput X: %4.4f\nInput Y: %4.4f\nInput R: %4.4f\n[%+4.4f]---[%+4.4f]\n   |         |   \n   |         |   \n   |         |   \n   |         |   \n   |         |   \n   |         |   \n[%+4.4f]---[%+4.4f]\n", ( Enabled ? "Enabled." : "Disabled." ), TX, TY, TR, FL, FR, RL, RR );
	
};

void MecanumDrive :: SetMotorScale ( double s )
{
	
	Scale = s;
	
};

double MecanumDrive :: GetMotorScale ()
{
	
	return Scale;
	
};

void MecanumDrive :: SetPreScale ( double Translation, double Rotation )
{

	PrescaleT = Translation;
	PrescaleR = Rotation;
	
};

double MecanumDrive :: GetPreScaleRotation ()
{
	
	return PrescaleR;
	
};

double MecanumDrive :: GetPreScaleTranslation ()
{
	
	return PrescaleT;
	
};

void MecanumDrive :: SetTranslation ( double X, double Y )
{
	
	TX = X * SQRT_2 * PrescaleT;
	TY = Y * PrescaleT;
	
};

void MecanumDrive :: SetRotation ( double R )
{
	
	TR = R * PrescaleR;
	
};

void MecanumDrive :: SetSineInversion ( bool SineInverted = false )
{
	
	this -> SineInverted = SineInverted;
	
};

void MecanumDrive :: AddXYFilter ( DSPFilter_2_2 * XYFilter )
{
	
	if ( XYFilter != NULL )
		XYFilters.Push ( XYFilter );
	
};

void MecanumDrive :: RemoveXYFilter ( DSPFilter_2_2 * XYFilter )
{
	
	int32_t Index = XYFilters.IndexOf ( XYFilter );
	
	if ( Index == - 1 )
		return;
	
	XYFilters.Remove ( Index, 1 );
	
};

void MecanumDrive :: AddMagDirFilter ( DSPFilter_2_2 * MagDirFilter )
{
	
	if ( MagDirFilter != NULL )
		MDFilters.Push ( MagDirFilter );
	
};

void MecanumDrive :: RemoveMagDirFilter ( DSPFilter_2_2 * MagDirFilter )
{
	
	int32_t Index = MDFilters.IndexOf ( MagDirFilter );
	
	if ( Index == - 1 )
		return;
	
	MDFilters.Remove ( Index, 1 );
	
};

void MecanumDrive :: AddRotationFilter ( DSPFilter_1_1 * RotationFilter )
{
	
	if ( RotationFilter != NULL )
		RFilters.Push ( RotationFilter );
	
};

void MecanumDrive :: RemoveRotationFilter ( DSPFilter_1_1 * RotationFilter )
{
	
	int32_t Index = RFilters.IndexOf ( RotationFilter );
	
	if ( Index == - 1 )
		return;
	
	RFilters.Remove ( Index, 1 );
	
};

