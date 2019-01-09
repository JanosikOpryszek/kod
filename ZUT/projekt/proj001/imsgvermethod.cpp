
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
#include"imsgvermethod.hpp"


namespace drv
{

    eErrorCodes ImsgvermethodPut::retEr;          //variable to return errorcode
    eErrorCodes ImsgvermethodPut::putMessage(std::string comingMessage)
    {
    retEr=OK;
    std::cout<<comingMessage<<std::endl;
    return retEr;
    }

    eErrorCodes ImsgvermethodPut::init()
    {
        return retEr;
    }

    eErrorCodes ImsgvermethodPut::deinit()
    {
        return retEr;
    }


    eErrorCodes ImsgvermethodPut::mRun()
    {
    retEr=OK;
    return retEr;
    }
    eErrorCodes ImsgvermethodPut::mStop()
    {
        retEr=OK;
        return retEr;
    }
    eErrorCodes ImsgvermethodPut::mPause()
    {
        retEr=OK;
        return retEr;
    }
    eErrorCodes ImsgvermethodPut::mResume()
    {
        retEr=OK;
        return retEr;
    }




}

