#ifndef LARUL_RGBSTRIPANIMATOR_H
#define LARUL_RGBSTRIPANIMATOR_H

#include "../../Timing/IntervalTimer.h"

#include "../../Util/Vector.h"

#include "../Color.h"

#include "IRGBStripAnimation.h"
#include "IRGBStrip.h"

/* RGBStripAnimator: An animation manager for IRGBStrips.
 *
 * Methods:
 * 
 *	RGBStripAnimator ( IRGBStrip * Strip, color_t BlankColor (OPTIONAL, Defaults to pure white) )
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Constructs an instance of RGBStripAnimator to animate <Strip>, using <BlankColor> as the color for un-animated regions of the strip.
 *	
 *	void AddAnimation ( const char * Name, IRGBStripAnimation * Animation, uint32_t Offset, uint32_t Length, double Speed (OPTIONAL, Defaults to 0), bool Enabled (OPTIONAL, Defaults to true) )
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Adds an animation to the internal list. The animation will start at pixel number <Offset>, span <Length> pixels, run at <Speed> speed, and only be enabled if <Enabled> is true. The <Name>
 *	passed to this function is the reference name used for changing properties of the animation which are managed by the animator, as well as removing the animation from the list.
 *
 *	void RemoveAnimation ( const char * Name )
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Removes the animation referenced by <Name>
 *
 *	void ChangeAnimationRange ( const char * Name, uint32_t Offset, uint32_t Length )
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Changes the range of pixels that the animation referenced by <Name> works on, such that it spans <Length> pixels starting form pixel <Offset>.
 *
 *	void ChangeAnimationSpeed ( const char * Name, double Speed )
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Changes the speed of the animation referenced by <Name> to <Speed>
 *	
 *	void ResetAnimationFrame ( const char * Name )
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Resets the frame of the animation referenced by <Name> to zero.
 *
 *	void ResetAnimationTime ( const char * Name )
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Resets the time that the animation referenced by <Name> has been running to zero.
 *
 *	void EnableAnimation ( const char * Name )
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Enables the animation referenced by <Name>.
 *
 *	void DisableAnimation ( const char * Name )
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Disables the animation referenced by <Name>.
 *
 *	void Update ()
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Animates the strip, but does not call Update () on it. Call this periodically above ~15 Hz for animations to look fluid.
 *
 *	void Disable ()
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * 	Completely disables the animator.
 *
 *	void Enable ()
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Enables the animator.
 *
 *	bool GetEnabled ()
 *	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *	Returns whether or not the animator is enabled.
 *
*/

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
