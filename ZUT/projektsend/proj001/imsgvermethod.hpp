/// @file        <MSGveryficator.hpp>
/// @ingroup     <drv>
/// @brief       <MSGveryficator class>

#ifndef MSGVERYFICATOR_H
#define MSGVERYFICATOR_H

#include"imsgvermethod.h"
#include"IMSGVerificator.h"

namespace drv
{

class ImsgvermethodPut:public drv::Imsgvermethod, public pub::IMSGVerificator
    {

    static eErrorCodes retEr;
    static int temp;
    static int fpreasure;
    static int rmp;
    public:
    eErrorCodes putMessage(std::string comingMessage);

    eErrorCodes show();
    /*
    eErrorCodes deinit();
    eErrorCodes mRun();
    eErrorCodes mStop();
    eErrorCodes mPause();
    eErrorCodes mResume();
    */
    };

}     //namespace drv


#endif







