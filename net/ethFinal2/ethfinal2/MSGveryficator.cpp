
//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <MSGveryficator.cpp>
/// @ingroup     <drv>
/// @brief       <fake  MSGveryficator class>



#include<string>
#include<iostream>
#include<unistd.h>  // sleep
#include"MSGveryficator.hpp"


namespace drv
{

    eErrorCodes MSGveryficator::retEr;          //variable to return errorcode
    eErrorCodes MSGveryficator::putMessage(std::string comingMessage)
    {
    retEr=OK;
    std::cout<<comingMessage<<std::endl;
    return retEr;
    }
    eErrorCodes MSGveryficator::mRun()
    {
    retEr=OK;
    return retEr;
    }
    eErrorCodes MSGveryficator::mStop()
    {
        retEr=OK;
        return retEr;
    }
    eErrorCodes MSGveryficator::mPause()
    {
        retEr=OK;
        return retEr;
    }
    eErrorCodes MSGveryficator::mResume()
    {
        retEr=OK;
        return retEr;
    }




}

