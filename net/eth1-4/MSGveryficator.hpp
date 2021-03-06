
//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <MSGveryficator.hpp>
/// @ingroup     <drv>
/// @brief       <MSGveryficator class>

#ifndef MSGVERYFICATOR_H       
#define MSGVERYFICATOR_H

#include"imsgvermethod.h"
#include"IMSGVerificator.h"

namespace drv
{

class MSGveryficator:public drv::Imsgvermethod, pub::IMSGVerificator
    {

    static eErrorCodes retEr;
    public:
    eErrorCodes mPutMessage(std::string comingMessage);
    eErrorCodes mRun();
    eErrorCodes mStop();
    eErrorCodes mPause();
    eErrorCodes mResume();
    };    //class prototypes

}     //namespace drv


#endif







