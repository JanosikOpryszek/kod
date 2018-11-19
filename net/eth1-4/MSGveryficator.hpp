
//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <MSGveryficator.hpp>
/// @ingroup     <drv>
/// @brief       <fake  MSGveryficator class>

#ifndef MSGVEFYFICATOR_H       //fale clas file, oryginale bedzie w katalogu MSGver
#define MSGVERYFICATOR_H

#include"imsgvermethod.h"

namespace drv
{

class MSGveryficator:public Imsgvermethod
    {

    static eErrorCodes retEr;
    public:
    eErrorCodes mPutMessage(std::string comingMessage)=0;
    };    //class prototypes

}     //namespace drv


#endif







