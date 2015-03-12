#ifndef LARUL_RGBSTRIPANIMATOR_H
#define LARUL_RGBSTRIPANIMATOR_H

#include "../../Timing/IntervalTimer.h"

#include "../../Util/Vector.h"

#include "../Color.h"

#include "IRGBStripAnimation.h"
#include "IRGBStrip.h"

class RGBStripAnimator
{
public:
	
	RGBStripAnimator ( IRGBStrip * Strip, color_t BlankColor = 0xFFFFFFFF );
	~RGBStripAnimator ();
	
	void AddAnimation ( const char * Name, IRGBStripAnimation * Animation, uint32_t Offset, uint32_t Length, double Speed = 0.0, bool Enabled = true );
	void RemoveAnimation ( const char * Name );
	
	void ChangeAnimationRange ( const char * Name, uint32_t Offset, uint32_t Length );
	void ChangeAnimationSpeed ( const char * Name, double Speed );
	
	void ResetAnimationFrame ( const char * Name );
	void ResetAnimationTime ( const char * Name );
	
	void EnableAnimation ( const char * Name );
	void DisableAnimation ( const char * Name );
	
	void Update ();
	
	void Disable ();
	void Enable ();
	
	bool GetEnabled ();
	
private:
	
	typedef struct
	{
		
		IRGBStripAnimation * Animation;
		const char * Name;
		
		bool Enabled;
		double Speed;
		
		uint32_t Frame;
		
		uint32_t Offset;
		uint32_t Length;
		
		double Elapsed;
		
	} AnimationInfo;
	
	IRGBStrip * Strip;
	
	color_t BlankColor;
	
	Vector <AnimationInfo> Animations;
	
	bool Enabled;
	IntervalTimer Delta;
	
};


#endif
