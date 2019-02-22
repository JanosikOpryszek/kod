
/// @file        <Idriver.h>
/// @ingroup     <pub>
/// @brief       <interface for all obserwers of LCM>


#ifndef IDRIVER_H
#define IDRIVER_H

#include"eErrorCodes.h"

namespace pub
{

class IDriver
    {
    public:

    virtual eErrorCodes show()=0;
    virtual eErrorCodes mRun()=0;
    virtual eErrorCodes mStop()=0;
    virtual eErrorCodes mPause()=0;
    virtual eErrorCodes mResume()=0;
    virtual eErrorCodes deinit()=0;
    };

}  //namespace pub


#endif // IDRIVER_H
