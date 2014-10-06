#include "LookbackLowpassFilter.h"

LookbackLowpassFilter :: LookbackLowpassFilter ( double MaximumSlew, uint32_t LookbackSize, LookbackLowpassFilter :: LookbackLowpassFilterMode Mode ):
	MaxSlew ( MaximumSlew ),
	Mode ( Mode ),
	LookbackSize ( LookbackSize ),
	Offset ( 0 )
{
	
	Lookback = new double [ LookbackSize ];
	
};

LookbackLowpassFilter :: ~LookbackLowpassFilter ()
{
	
	delete Lookback;
	
};

void LookbackLowpassFilter :: Compute ( double Feed )
{
	
	if ( Mode == LookbackLowpassFilter :: kMode_BypassNoCompute )
	{
		
		if ( Offset != 0 )
			Lookback [ Offset - 1 ] = Feed;
		
		Lookback [ LookbackSize - 1 ] = Feed;
		return;
		
	}
	
	if ( Mode == LookbackLowpassFilter :: kMode_BypassCompute )
	{
		
		Lookback [ Offset ] = Feed;
		Offset ++;
		
		if ( Offset >= LookbackSize )
			Offset = 0;
		
		return;
		
	}
	
	double Total = 0;
	
	for ( uint32_t i = 0; i < LookbackSize; i ++ )
		Total += Lookback [ i ];
	
	Total /= LookbackSize;
	
	if ( Mode == kMode_ComputeSlew )
	{
		
		double Delta = Feed - Total;
		
		if ( Delta < 0 )
		{
			
			if ( - Delta > MaxSlew )
				Delta = - MaxSlew;
			
		}
		else
		{
			
			if ( Delta > MaxSlew )
				Delta = MaxSlew;
			
		}
		
		Feed = Total + Delta;
		
	}
	
	Lookback [ Offset ] = Feed;
	Offset ++;
	
	if ( Offset >= LookbackSize )
			Offset = 0;
	
};

double LookbackLowpassFilter :: Read ()
{
	
	if ( Offset != 0 )
		return Lookback [ Offset - 1 ];
	
	return Lookback [ LookbackSize - 1 ];
	
};

void LookbackLowpassFilter :: Reset ()
{
	
	for ( uint32_t i = 0; i < LookbackSize; i ++ )
		Lookback [ i ] = 0;
	
};

void LookbackLowpassFilter :: SetLookbackSize ( uint32_t LookbackSize )
{
	
	double * NewLookback = new double [ LookbackSize ];
	
	uint32_t CopySize = ( LookbackSize < this -> LookbackSize ) ? LookbackSize : this -> LookbackSize;
		
	for ( uint32_t i = 0; i < CopySize; i ++ )
		NewLookback [ i ] = Lookback [ ( i + Offset ) % this -> LookbackSize ];
	
	Offset = CopySize % LookbackSize;
	
	delete Lookback;
	Lookback = NewLookback;
	
	this -> LookbackSize = LookbackSize;
	
};

void LookbackLowpassFilter :: SetMaximumSlewrate ( double MaxSlew )
{
	
	this -> MaxSlew = MaxSlew;
	
};

void LookbackLowpassFilter :: SetFilterMode ( LookbackLowpassFilterMode Mode )
{
	
	this -> Mode = Mode;
	
};
