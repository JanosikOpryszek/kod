//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <sheduler.cpp>
/// @ingroup     <drv>
/// @brief       <run and control rte and swc komponents>


#include"sheduler.hpp"

namespace rte
{

    pthread_mutex_t Sheduler::mutexeth;     //mutex for pause & resume
    pthread_t Sheduler::thread_id;          //thread for main loop
    eErrorCodes Sheduler::eRetEr;          //variable to return errorcode
    //add pointer to logger
    //add pointer to configurator


eErrorCodes Sheduler::mOnStateChange(eStates a_sNewState)
    {
    eRetEr=OK;
    //Init Deinit switching
    return eRetEr;
    }


eErrorCodes Sheduler::setconfigurator()
{
    eRetEr=OK;

    return eRetEr;
}


eErrorCodes Sheduler::setlogger()
{
    eRetEr=OK;

    return eRetEr;
}


eErrorCodes Sheduler::mRun()
    {
    eRetEr=OK;
    //use configurator interface  and read config,
    int EcuNr=1; //run configurathot methos to set Ecu number
    switch (EcuNr)
    {
    case 1:
    {
        std::cout<<"run case 1"<<std::endl;
      //object creation
    break;
    }
    case 2:
    {
      //object creation
    break;
    }
    case 3:
    {
      //object creation
    break;
    }
    case 4:
    {
      //object creation
    break;
    }

    default:
    {
    //Logging-  argument error configure Sheduler
    }
    }
    //start in thread inicialize main loop
    std::cout<<"runing pthread"<<std::endl;
    pthread_create(&Sheduler::thread_id,0,&Sheduler::initializess,this);

    return eRetEr;
    }

void *Sheduler::initialize()
    {
    //main loop of sheduler, run in thread by Starter
    while(1)
    {
        std::cout<<"main loop"<<std::endl;
    }

    } //Sheduler::intialize()


void *Sheduler::initializess(void *context)
    {
    return ((Sheduler *)context)->Sheduler::initialize();
    }






} //namespace drv


