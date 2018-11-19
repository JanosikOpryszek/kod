
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
    eErrorCodes MSGveryficator::mPutMessage(std::string comingMessage)
    {
    retEr=OK;
    
    std::cout<<comingMessage<<std::endl;


    return retEr;
    }










}

