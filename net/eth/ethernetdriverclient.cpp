//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <ethernetdriverclient.cpp>
/// @ingroup     <drv>
/// @brief       <sending msg to antoher ecu by ethernet>

#include<pthread.h>
#include<iostream>
#include<unistd.h>  // sleep
#include"ethernetdriverclient.hpp"

namespace drv
{

pthread_mutex_t Ethernetdriverclient::mutexeth;

int Ethernetdriverclient::init()
    {
    //Init (back from deinit)
    return 0;
    } //Ethernetdriverclient::init()


int Ethernetdriverclient::deinit()
    {
    //deInit on reset demand
    return 0;
    } //Ethernetdriverclient::deinit()

void *Ethernetdriverclient::initialize()
    {
    while(1)
        {
        pthread_mutex_lock( &mutexeth ); 
        std::cout<<" CLIENT CLIENT"<<std::endl;
        sleep(1);
        pthread_mutex_unlock( &mutexeth ); 
        }
    
    return 0;
    } //Ethernetdriverclient::intialize()



void *Ethernetdriverclient::initializess(void *context)
    {
    return ((Ethernetdriverclient *)context)->Ethernetdriverclient::initialize();
    } //Ethernetdriverclient::initializess


} //namespace drv


