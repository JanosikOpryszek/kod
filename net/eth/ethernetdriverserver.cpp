//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <ethernetdriverserver.cpp>
/// @ingroup     <drv>
/// @brief       <receive msg from antoher ecu by ethernet>


#include<iostream>
#include<unistd.h>  // sleep
#include"ethernetdriverserver.hpp"

namespace drv
{

int Ethernetdriverserver::init()
    {
    //Init (back from deinit)
    return 0;
    }    //Ethernetdriverserver::init()


int Ethernetdriverserver::deinit()
    {
    //deInit on reset demand
    return 0;
    } //Ethernetdriverserver::deinit()


void *Ethernetdriverserver::initialize()
    {
    while(1)
        {
        std::cout<<" SERVER SERVER"<<std::endl;
        sleep(2);
        }

    } //Ethernetdriverserver::intialize()



void *Ethernetdriverserver::initializess(void *context)
    {
    return ((Ethernetdriverserver *)context)->Ethernetdriverserver::initialize();
    } //Ethernetdriverserver::initializess





} //namespace drv


