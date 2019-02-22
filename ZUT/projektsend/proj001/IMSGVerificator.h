
/// @file        <IMSGVeryficator.h>
/// @ingroup     <drv>
/// @brief       <interface for MSGveryficator
///
/// >
#ifndef IMSGVERIFICATOR_H
#define IMSGVERIFICATOR_H

//#include "pub/IDriver.h"
//#include "IDriver.h"
#include "eErrorCodes.h"



namespace pub
{

class IMSGVerificator//:public pub::IDriver
{
public:
    virtual ~IMSGVerificator(){}

    virtual eErrorCodes show()=0;
    /*
    virtual eErrorCodes mRun()=0;
    virtual eErrorCodes mStop()=0;
    virtual eErrorCodes mPause()=0;
    virtual eErrorCodes mResume()=0;
    virtual eErrorCodes deinit()=0;
    */

};

} //namespace pub
#endif // IMSGVERIFICATOR_H




