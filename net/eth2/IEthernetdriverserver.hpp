//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <IEthernetdriverserver.hpp>
/// @ingroup     <pub>
/// @brief       <interface for LCM>


#ifndef IETHERNETDRIVERSERVER_HPP
#define IETHERNETDRIVERSERVER_HPP

//#include "pub/IDriver.h"
//#include "../MSGVerificator/MSGveryficator.hpp"
#include "IDriver.h"
#include "MSGveryficator.hpp"

namespace pub
{

class IEthernetdriverserver:public pub::IDriver
    {
    public:
    virtual eErrorCodes mRun() = 0;
    virtual eErrorCodes mStop() = 0;
    virtual eErrorCodes mPause() = 0;
    virtual eErrorCodes mResume() = 0;
    virtual eErrorCodes setConfigurator()=0;
    virtual eErrorCodes setLogger()=0;
    virtual eErrorCodes setMsgVeryficator(drv::MSGveryficator*)=0;
    };


}    //namespace pub

#endif // IETHERNETDRIVERSERVER_HPP

