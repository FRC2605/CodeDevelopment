#ifndef LARUL_H
#define LARUL_H

// General include file for LARUL

#include "LARULTuning.h"

#include "Util/Delegate.h"
#include "Util/MethodClosure.h"
#include "Util/DefaultParameterClosure.h"
#include "Util/LError.h"
#include "Util/Vector.h"
#include "Util/Unused.h"

#include "Timing/Clock.h"
#include "Timing/IntervalTimer.h"
#include "Timing/TimedIncrementer.h"

#include "Threading/Mutex.h"
#include "Threading/Thread.h"
#include "Threading/Condition.h"
#include "Threading/MessageQueue.h"
#include "Threading/ObjectLock.h"

#include "Sensing/IAngularInput.h"
#include "Sensing/IBooleanInput.h"
#include "Sensing/IScalarInput.h"
#include "Sensing/IXInput.h"
#include "Sensing/IXYInput.h"
#include "Sensing/IMotionLimit.h"
#include "Sensing/Nav6/Nav6.h"
#include "Sensing/Nav6/Nav6YawAngularInput.h"
#ifndef NO_WPILIB
	#include "Sensing/CANTalon/CANTalonSwitchMotionLimit.h"
	#include "Sensing/DIO/DIOSwitchLimit.h"
#endif

#include "Networking/TCP.h"
#include "Networking/TCPSocket.h"
#include "Networking/TCPServer.h"
#include "Networking/TCPServerSocket.h"
#include "Networking/UDP.h"
#include "Networking/UDPSocket.h"

#include "Motion/IActuatorDrive.h"
#include "Motion/IMotionSource.h"
#include "Motion/IOffsetDrive.h"
#include "Motion/IOffsetSource.h"
#include "Motion/IPositionDrive.h"
#include "Motion/IPositionSource.h"
#include "Motion/IRateDrive.h"
#include "Motion/IRateSource.h"

#include "Memory/AlignOf.h"
#include "Memory/CachingAllocator.h"
#include "Memory/IAllocSpec.h"
#include "Memory/SingleAllocSpec.h"

#include "Math/Matrix33.h"
#include "Math/Quaternion.h"
#include "Math/Range.h"
#include "Math/Vector3.h"

#include "Logging/Logger.h"

#include "Hardware/HWSystem.h"
#include "Hardware/Power/PowerUsageSpec.h"
#include "Hardware/Drive/IDriveBase.h"
#include "Hardware/Drive/IDriveTrain.h"
#include "Hardware/Drive/IQuadRectangularDriveBase.h"
#include "Hardware/Drive/LinearSlide.h"
#include "Hardware/Drive/MecanumDriveTrain.h"
#include "Hardware/Drive/Filters/RotationFilter.h"
#include "Hardware/Drive/Filters/MecanumXYSlewFilter.h"
#include "Hardware/Drive/Filters/MecanumVelocityProfile.h"
#include "Hardware/Drive/Filters/MecanumMagDirOrientationOffset.h"
#ifndef NO_WPILIB
	#include "Hardware/Power/IPowerScalable.h"
	#include "Hardware/Power/Power.h"
	#include "Hardware/Power/PowerManager.h"
	#include "Hardware/Power/PowerProfile.h"
	#include "Hardware/Motors/CANJaguarConfiguration.h"
	#include "Hardware/Motors/CANTalonConfiguration.h"
	//#include "Hardware/Drive/CANJaguarMecanumDriveBase.h"
	#include "Hardware/Drive/CANTalonPositionServo.h"
	#include "Hardware/Drive/CANTalonQuadDriveBase.h"
#endif

#include "Events/IEvent.h"
#include "Events/EventController.h"

#include "DSP/DSPFilter.h"
#include "DSP/LookbackLowpassFilter.h"

#ifndef NO_WPILIB
	#include <DriverStation/JoystickButtonInput.h>
	#include <DriverStation/JoystickXYInput.h>
	#include <DriverStation/NumericStepper.h>
#endif

//#include "Debug/LARULDebug.h"
//#include "Debug/LDebugServer.h"

#include "Config/ConfigFile.h"
#include "Config/ConfigSection.h"

#include "COM/ISerialInterface.h"
#ifndef NO_WPILIB
	#include "COM/WPICom.h"
#endif

#include "Behaviors/IBehavior.h"
#include "Behaviors/BehaviorController.h"

#endif
