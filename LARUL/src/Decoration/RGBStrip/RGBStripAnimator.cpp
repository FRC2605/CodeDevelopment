#include "RGBStripAnimator.h"

#include <string.h>

RGBStripAnimator :: RGBStripAnimator ( IRGBStrip * Strip, color_t BlankColor ):
	Strip ( Strip ),
	BlankColor ( BlankColor ),
	Animations (),
	Enabled ( false ),
	Delta ()
{	
};

RGBStripAnimator :: ~RGBStripAnimator ()
{	
};

void RGBStripAnimator :: AddAnimation ( const char * Name, IRGBStripAnimation * Animation, uint32_t Offset, uint32_t Length, double Speed, bool Enabled )
{
	
	for ( uint32_t i = 0; i < Animations.Length (); i ++ )
	{
		
		if ( strcmp ( Animations [ i ].Name, Name ) == 0 )
			return;
		
	}
	
	AnimationInfo Info;
	
	Info.Name = Name;
	Info.Animation = Animation;
	Info.Offset = Offset;
	Info.Length = Length;
	Info.Speed = Speed;
	Info.Enabled = Enabled;
	Info.Frame = 0;
	Info.Elapsed = 0.0;
	
	Animations.Push ( Info );
	
};

void RGBStripAnimator :: RemoveAnimation ( const char * Name )
{
	
	for ( uint32_t i = 0; i < Animations.Length (); i ++ )
	{
		
		if ( strcmp ( Animations [ i ].Name, Name ) == 0 )
		{
			
			Animations.Remove ( i, 1 );
			
			return;
			
		}
		
	}
	
};

void RGBStripAnimator :: ResetAnimationFrame ( const char * Name )
{
	
	for ( uint32_t i = 0; i < Animations.Length (); i ++ )
	{
		
		if ( strcmp ( Animations [ i ].Name, Name ) == 0 )
		{
			
			Animations [ i ].Frame = 0;
			
			return;
			
		}
		
	}
	
};

void RGBStripAnimator :: ResetAnimationTime ( const char * Name )
{
	
	for ( uint32_t i = 0; i < Animations.Length (); i ++ )
	{
		
		if ( strcmp ( Animations [ i ].Name, Name ) == 0 )
		{
			
			Animations [ i ].Elapsed = 0.0;
			
			return;
			
		}
		
	}
	
};

void RGBStripAnimator :: ChangeAnimationRange ( const char * Name, uint32_t Offset, uint32_t Length )
{
	
	for ( uint32_t i = 0; i < Animations.Length (); i ++ )
	{
		
		if ( strcmp ( Animations [ i ].Name, Name ) == 0 )
		{
			
			Animations [ i ].Offset = Offset;
			Animations [ i ].Length = Length;
			
			return;
			
		}
		
	}
	
};

void RGBStripAnimator :: ChangeAnimationSpeed ( const char * Name, double Speed )
{
	
	for ( uint32_t i = 0; i < Animations.Length (); i ++ )
	{
		
		if ( strcmp ( Animations [ i ].Name, Name ) == 0 )
		{
			
			Animations [ i ].Speed = Speed;
			
			return;
			
		}
		
	}
	
};

void RGBStripAnimator :: EnableAnimation ( const char * Name )
{
	
	for ( uint32_t i = 0; i < Animations.Length (); i ++ )
	{
		
		if ( strcmp ( Animations [ i ].Name, Name ) == 0 )
		{
			
			Animations [ i ].Enabled = true;
			
			return;
			
		}
		
	}
	
};

void RGBStripAnimator :: DisableAnimation ( const char * Name )
{
	
	for ( uint32_t i = 0; i < Animations.Length (); i ++ )
	{
		
		if ( strcmp ( Animations [ i ].Name, Name ) == 0 )
		{
			
			Animations [ i ].Enabled = false;
			
			return;
			
		}
		
	}
	
};

void RGBStripAnimator :: Update ()
{
	
	if ( ! Enabled )
		return;
	
	double DeltaTime = Delta.GetTimeS ();
	Delta.Restart ();
	
	size_t Length = Strip -> GetLength ();
	
	color_t Colors [ Length ];
	
	for ( uint32_t c = 0; c < Length; c ++ )
		Colors [ c ] = BlankColor;
	
	for ( uint32_t i = 0; i < Animations.Length (); i ++ )
	{
		
		if ( Animations [ i ].Enabled )
		{
			
			Animations [ i ].Frame ++;
			Animations [ i ].Elapsed += DeltaTime * Animations [ i ].Speed;
			
			Animations [ i ].Animation -> Draw ( Colors, Animations [ i ].Offset, Animations [ i ].Length, Animations [ i ].Frame, Animations [ i ].Elapsed );
			
		}
		
	}
	
	Strip -> SetPixels ( 0, Colors, Length );
	
};

void RGBStripAnimator :: Disable ()
{
	
	Enabled = false;
	
	Delta.Reset ();
	
};

void RGBStripAnimator :: Enable ()
{
	
	Enabled = true;
	
	Delta.Start ();
	
};


	
bool RGBStripAnimator :: GetEnabled ()
{
	
	return Enabled;
	
};
