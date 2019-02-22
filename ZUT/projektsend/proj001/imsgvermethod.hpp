#ifndef MSGMETHODPUT_H
#define MSGMETHODPUT_H


#include"eErrorCodes.h"
#include<string>

namespace drv
{

class ImsgmethodPut
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







