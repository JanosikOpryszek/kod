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
    eErrorCodes Sheduler::retEr;          //variable to return errorcode
    //add pointer to logger
    //add pointer to configurator


eErrorCodes Sheduler::mOnStateChange(eStates a_sNewState)
    {
    retEr=OK;
    //Init Deinit switching
    return retEr;
    }


eErrorCodes Sheduler::setconfigurator()
{
    retEr=OK;

    return retEr;
}


eErrorCodes Sheduler::setlogger()
{
    retEr=OK;

    return retEr;
}


eErrorCodes Sheduler::mRun()
    {
    retEr=OK;
    //use configurator interface  and read config,
    int EcuNr=1; //run configurathot methos to set Ecu number
    switch (EcuNr)
    {
    case 1:
    {
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
    //start in thread inicialize main loop:
    pthread_create(&Sheduler::thread_id,0,&Sheduler::initializess,this);

    return retEr;
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


