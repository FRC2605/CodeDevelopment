#include "Color.h"

color_t LerpColor ( color_t A, color_t B, double Mix )
{
	
	if ( Mix > 1.0 )
		Mix = 1.0;
	if ( Mix < 0.0 )
		Mix = 0.0;
	
	double RA = FRedFromColor ( A );
	double RB = FRedFromColor ( B );
	double GA = FGreenFromColor ( A );
	double GB = FGreenFromColor ( B );
	double BA = FBlueFromColor ( A );
	double BB = FBlueFromColor ( B );
	double AA = FAlphaFromColor ( A );
	double AB = FAlphaFromColor ( B );
	
	double OM = 1.0 - Mix;
	
	return ColorFromRGBA ( Mix * RA + OM * RB, Mix * GA + OM * GB, Mix * BA + OM * BB, Mix * AA + OM * AB );

};
