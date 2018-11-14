//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <ethernetdriverserver.cpp>
/// @ingroup     <drv>
/// @brief       <receive msg from antoher ecu by ethernet>

#include<pthread.h>
#include<iostream>
#include<unistd.h>  // sleep
#include"ethernetdriverserver.hpp"

namespace drv
{

pthread_mutex_t Ethernetdriverserver::mutexeth;

int Ethernetdriverserver::init()
    {
    pthread_mutex_unlock( &Ethernetdriverserver::mutexeth );
    return 0;
    }    //Ethernetdriverserver::init()


int Ethernetdriverserver::deinit()
    {
    pthread_mutex_lock( &Ethernetdriverserver::mutexeth );
    return 0;
    } //Ethernetdriverserver::deinit()


void *Ethernetdriverserver::initialize()
    {
    while(1)
        {
        pthread_mutex_lock( &mutexeth );
        std::cout<<" SERVER "<<std::endl;
        pthread_mutex_unlock( &mutexeth );
        sleep(1);
        }

    } //Ethernetdriverserver::intialize()



void *Ethernetdriverserver::initializess(void *context)
    {
    return ((Ethernetdriverserver *)context)->Ethernetdriverserver::initialize();
    } //Ethernetdriverserver::initializess




} //namespace drv


