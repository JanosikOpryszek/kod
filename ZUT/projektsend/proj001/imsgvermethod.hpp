#ifndef MSGMETHODPUT_H
#define MSGMETHODPUT_H


#include"eErrorCodes.h"
#include<string>

namespace drv
{

class ImsgmethodPut
    {
public:
    eErrorCodes putMessage(std::string comingMessage);
    eErrorCodes show();
    bool checkdirection();
private:
    static eErrorCodes retEr;
    static unsigned long temp;
    static unsigned long  fpreasure;
    static unsigned long  rmp;
    static std::string spacee;
    static bool direction;


    };

}


#endif







