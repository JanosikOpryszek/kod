//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <ICandriverserver.hpp>
/// @ingroup     <drv>
/// @brief       <interface of Can>


#ifndef IETHERNETDRIVERSERVER_HPP
#define IETHERNETDRIVERSERVER_HPP

//#include "pub/IDriver.h"
//#include"srv/Logger/ILogger.h"
//#include "../MSGVerificator/MSGveryficator.hpp"

#include <string>
#include "IDriver.h"
#include "ILogger.h"
#include "MSGveryficator.hpp"
namespace drv
{

    class ICandriverserver:public pub::IDriver
    {
        public:
        /// @brief     <destructor>
        virtual ~ICandriverserver(){}
        virtual eErrorCodes init() = 0;
        virtual eErrorCodes mRun() = 0;
        virtual eErrorCodes mStop() = 0;
        virtual eErrorCodes mPause() = 0;
        virtual eErrorCodes mResume() = 0;
        virtual eErrorCodes deinit() = 0;
        virtual eErrorCodes send(std::string)=0;
    };


}    //namespace drv

#endif
