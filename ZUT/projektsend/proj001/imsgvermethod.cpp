/// @file        <MSGveryficator.cpp>
/// @ingroup     <drv>
/// @brief       <MSGveryficator class>


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
    switch (comingMessage[2] )
    {
    case 5:
        std::cout<<"id=5"<<std::endl;
        break;
    case 'b':
        std::cout<<"id=b"<<std::endl;
        break;
    case 'c':
        std::cout<<"id=c"<<std::endl;
        break;
    default:
        std::cout<<"default"<<std::endl;
        break;

    }


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

