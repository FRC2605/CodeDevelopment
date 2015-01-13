#ifndef LARUL_CANJAGUARCONFIGURATION_H
#define LARUL_CANJAGUARCONFIGURATION_H

#include <WPILib.h>

class CANJaguarConfiguration
{
public:
	
private:
	
	typedef enum
	{
		
		kFeedbackType_QuadEncoder,
		kFeedbackType_Encoder,
		kFeedbackType,Potentiometer
		
	} FeedbackType;
	
	CANSpeedController :: ControlMode Mode;
	FeedbackType Feedback;
	
	union
	{
		
		struct
		{
			
			
			
		} EncoderConf;
		
		struct
		{
			
			
			
		} PotConf;
		
	};
	
};


#endif
