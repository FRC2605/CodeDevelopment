#include "MecanumDriveTrain.h"

#include <math.h>

#define PI_Div_4 0.78539816339
#define SQRT_2 1.41421356237

MecanumDriveTrain :: MecanumDriveTrain ( IQuadRectangularDriveBase * DriveBase ):
	DriveBase ( DriveBase ),
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

void MecanumDriveTrain :: SetDriveBase ( IQuadRectangularDriveBase * DriveBase )
{
	
	if ( this -> DriveBase == DriveBase )
		return;

	if ( this -> DriveBase -> GetEnabled () )
		this -> DriveBase -> Disable ();

	this -> DriveBase = DriveBase;

	if ( ! Enabled )
		return;

	this -> DriveBase ->Enable ();

	PushTransform ();
	
};

void MecanumDriveTrain :: Enable ()
{
	
	Enabled = true;
	
	if ( DriveBase != NULL )
		DriveBase -> Enable ();
	
};

void MecanumDriveTrain :: Disable ()
{
	
	if ( DriveBase != NULL )
		DriveBase -> Disable ();
	
	Enabled = false;
	
};

bool MecanumDriveTrain :: GetEnabled ()
{
	
	return Enabled;
	
};

void MecanumDriveTrain :: Update ()
{
	
	if ( DriveBase != NULL )
		DriveBase -> Update ();
	
};

void MecanumDriveTrain :: PushTransform ()
{
	
	double ForceAngle;
	double ForceMagnitude;
	double SinCalc;
	double CosCalc;
	double LX;
	double LY;
	double LR;
	uint32_t i;
	
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
	
	if ( ( DriveBase != NULL ) && Enabled )
	{
		
		DriveBase -> SetMotor ( IQuadRectangularDriveBase :: kMotorPosition_FL, ( ( SineInverted ? CosCalc : SinCalc ) + LR ) * Scale );
		DriveBase -> SetMotor ( IQuadRectangularDriveBase :: kMotorPosition_FR, ( ( SineInverted ? SinCalc : CosCalc ) - LR ) * Scale );
		DriveBase -> SetMotor ( IQuadRectangularDriveBase :: kMotorPosition_RL, ( ( SineInverted ? SinCalc : CosCalc ) + LR ) * Scale );
		DriveBase -> SetMotor ( IQuadRectangularDriveBase :: kMotorPosition_RR, ( ( SineInverted ? CosCalc : SinCalc ) - LR ) * Scale );
		
	}
	
};

void MecanumDriveTrain :: DebugValues ()
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
	
	FL = ( ( SineInverted ? CosCalc : SinCalc ) + LR ) * Scale;
	FR = ( ( SineInverted ? SinCalc : CosCalc ) - LR ) * Scale;
	RL = ( ( SineInverted ? SinCalc : CosCalc ) + LR ) * Scale;
	RR = ( ( SineInverted ? CosCalc : SinCalc ) - LR ) * Scale;
	
	printf ( "[ Mecanum Drive Debug ]\n%s\nInput X: %4.4f\nInput Y: %4.4f\nInput R: %4.4f\n[%+4.4f]---[%+4.4f]\n   |         |   \n   |         |   \n   |         |   \n   |         |   \n   |         |   \n   |         |   \n[%+4.4f]---[%+4.4f]\n", ( Enabled ? "Enabled." : "Disabled." ), TX, TY, TR, FL, FR, RL, RR );
	
};

void MecanumDriveTrain :: SetMotorScale ( double S )
{
	
	Scale = S;
	
};

double MecanumDriveTrain :: GetMotorScale ()
{
	
	return Scale;
	
};

void MecanumDriveTrain :: SetPreScale ( double Translation, double Rotation )
{

	PrescaleT = Translation;
	PrescaleR = Rotation;
	
};

double MecanumDriveTrain :: GetPreScaleRotation ()
{
	
	return PrescaleR;
	
};

double MecanumDriveTrain :: GetPreScaleTranslation ()
{
	
	return PrescaleT;
	
};

void MecanumDriveTrain :: SetTranslation ( double X, double Y )
{
	
	TX = X * SQRT_2 * PrescaleT;
	TY = Y * PrescaleT;
	
};

void MecanumDriveTrain :: SetRotation ( double R )
{
	
	TR = R * PrescaleR;
	
};

void MecanumDriveTrain :: SetSineInversion ( bool SineInverted = false )
{
	
	this -> SineInverted = SineInverted;
	
};

void MecanumDriveTrain :: AddXYFilter ( DSPFilter_2_2 * XYFilter )
{
	
	if ( XYFilter != NULL )
		XYFilters.Push ( XYFilter );
	
};

void MecanumDriveTrain :: RemoveXYFilter ( DSPFilter_2_2 * XYFilter )
{
	
	int32_t Index = XYFilters.IndexOf ( XYFilter );
	
	if ( Index == - 1 )
		return;
	
	XYFilters.Remove ( Index, 1 );
	
};

void MecanumDriveTrain :: AddMagDirFilter ( DSPFilter_2_2 * MagDirFilter )
{
	
	if ( MagDirFilter != NULL )
		MDFilters.Push ( MagDirFilter );
	
};

void MecanumDriveTrain :: RemoveMagDirFilter ( DSPFilter_2_2 * MagDirFilter )
{
	
	int32_t Index = MDFilters.IndexOf ( MagDirFilter );
	
	if ( Index == - 1 )
		return;
	
	MDFilters.Remove ( Index, 1 );
	
};

void MecanumDriveTrain :: AddRotationFilter ( DSPFilter_1_1 * RotationFilter )
{
	
	if ( RotationFilter != NULL )
		RFilters.Push ( RotationFilter );
	
};

void MecanumDriveTrain :: RemoveRotationFilter ( DSPFilter_1_1 * RotationFilter )
{
	
	int32_t Index = RFilters.IndexOf ( RotationFilter );
	
	if ( Index == - 1 )
		return;
	
	RFilters.Remove ( Index, 1 );
	
};
