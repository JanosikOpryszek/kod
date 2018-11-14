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

    pthread_mutex_unlock( &Ethernetdriverclient::mutexeth );
    return 0;
    } //Ethernetdriverclient::init()


int Ethernetdriverclient::deinit()
    {

    pthread_mutex_lock( &Ethernetdriverclient::mutexeth );
    return 0;
    } //Ethernetdriverclient::deinit()

void *Ethernetdriverclient::initialize()
    {
    while(1)
        {
        pthread_mutex_lock( &mutexeth ); 
        std::cout<<"              CLIENT"<<std::endl;
        pthread_mutex_unlock( &mutexeth ); 
        sleep(1);
        }
    
    return 0;
    } //Ethernetdriverclient::intialize()



void *Ethernetdriverclient::initializess(void *context)
    {
    return ((Ethernetdriverclient *)context)->Ethernetdriverclient::initialize();
    } //Ethernetdriverclient::initializess



} //namespace drv


