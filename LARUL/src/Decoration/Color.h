#ifndef LARUL_COLOR_H
#define LARUL_COLOR_H

#include <stdint.h>

typedef uint32_t color_t;

#define COLOR_BLACK 0x000000
#define COLOR_RED 0x0000FF
#define COLOR_GREEN 0x00FF00
#define COLOR_BLUE 0xFF0000
#define COLOR_WHITE 0xFFFFFF

#define ALPHA_FULL 0xFF000000
#define ALPHA_NONE 0x00000000

/* color_t is a generic type to represent a 32-bit ARGB color. Below are functoins for modification of color.
*/

inline color_t ColorFromRGB ( double R, double G, double B )
{
	
	return static_cast <color_t> ( static_cast <uint32_t> ( R * 0xFF ) | ( static_cast <uint32_t> ( G * 0xFF00 ) & 0xFF00 ) | ( static_cast <uint32_t> ( B * 0xFF0000 ) & 0xFF0000 ) );
	
};

inline color_t ColorFromRGBA ( double R, double G, double B, double A )
{
	
	return static_cast <color_t> ( static_cast <uint32_t> ( R * 0xFF ) | ( static_cast <uint32_t> ( G * 0xFF00 ) & 0xFF00 ) | ( static_cast <uint32_t> ( B * 0xFF0000 ) & 0xFF0000 ) | ( static_cast <uint32_t> ( A * 0xFF000000 ) & 0xFF000000 ) );
	
};

inline color_t ColorFromRGB ( uint8_t R, uint8_t G, uint8_t B )
{
	
	return static_cast <color_t> ( R | ( B << 8 ) | ( G << 16 ) );
	
};

inline color_t ColorFromRGBA ( uint8_t R, uint8_t G, uint8_t B, uint8_t A )
{
	
	return static_cast <color_t> ( R | ( B << 8 ) | ( G << 16 ) | ( A << 24 ) );
	
};

inline uint8_t RedFromColor ( color_t Color )
{
	
	return static_cast <uint8_t> ( Color & 0xFF );
	
};

inline uint8_t GreenFromColor ( color_t Color )
{
	
	return static_cast <uint8_t> ( ( Color >> 8 ) & 0xFF );
	
};

inline uint8_t BlueFromColor ( color_t Color )
{
	
	return static_cast <uint8_t> ( ( Color >> 16 ) & 0xFF );
	
};

inline uint8_t AlphaFromColor ( color_t Color )
{
	
	return static_cast <uint8_t> ( ( Color >> 24 ) & 0xFF );
	
};

inline double FRedFromColor ( color_t Color )
{
	
	return static_cast <double> ( Color & 0xFF ) / 255.0;
	
};

inline double FGreenFromColor ( color_t Color )
{
	
	return static_cast <double> ( Color & 0xFF00 ) / 65280.0;
	
};

inline double FBlueFromColor ( color_t Color )
{
	
	return static_cast <double> ( Color & 0xFF0000 ) / 16711680.0;
	
};

inline double FAlphaFromColor ( color_t Color )
{
	
	return static_cast <double> ( Color & 0xFF000000 ) / 4278190080.0;
	
};

color_t LerpColor ( color_t A, color_t B, double Mix );

#endif
