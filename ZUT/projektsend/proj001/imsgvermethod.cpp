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
    case '5': //coolant temp= A-40
    {
        std::cout<<"coolant temp=";
        int temp=std::stoul(comingMessage.substr(4,6),nullptr,10);   //stoul conver hex string to int, substring 0-2
        std::cout<<temp<<std::endl;
        break;
    }
    case 'a':
    {
        std::cout<<"fuel preasure=";
        int fpreasure=std::stoul(comingMessage.substr(4,6),nullptr,10);   //stoul conver hex string to int, substring 0-2
        std::cout<<fpreasure<<std::endl;
        break;
    }
    case 'c':
    {
        std::cout<<"engine RPM=";
        int rmp=std::stoul(comingMessage.substr(4,6),nullptr,10);   //stoul conver hex string to int, substring 0-2
        std::cout<<rmp<<std::endl;
        break;
    }
    default:
        break;

    }


    //std::cout<<comingMessage<<std::endl;
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

