#ifndef LARUL_IQUADRECTANGULARCANTALONDRIVEBASE_H
#define LARUL_IQUADRECTANGULARCANTALONDRIVEBASE_H

#include "../../LARULTuning.h"

#ifndef NO_WPILIB

#include "IQuadRectangularDriveBase.h"

class IQuadRectangularCANTalonDriveBase : public IQuadRectangularDriveBase
{
public:

	virtual ~IQuadRectangularCANTalonDriveBase () {};

	virtual CANTalon * GetCANTalon ( MotorPosition Motor ) = 0;


};

#endif
#endif
