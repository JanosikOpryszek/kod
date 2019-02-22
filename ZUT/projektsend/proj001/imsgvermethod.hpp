/// @file        <MSGveryficator.hpp>
/// @ingroup     <drv>
/// @brief       <MSGveryficator class>

#ifndef MSGVERYFICATOR_H
#define MSGVERYFICATOR_H

//#include"imsgvermethod.h"
//#include"IMSGVerificator.h"
#include"eErrorCodes.h"
#include<string>

namespace drv
{

class ImsgmethodPut//:public drv::Imsgvermethod, public pub::IMSGVerificator
    {

    static eErrorCodes retEr;
    static int temp;
    static int fpreasure;
    static int rmp;
    static std::string spacee;
    static bool direction;
    public:
    eErrorCodes putMessage(std::string comingMessage);
    eErrorCodes show();

    };

}     //namespace drv


#endif







