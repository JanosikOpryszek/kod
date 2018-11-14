//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <ethernetdriverserver.hpp>
/// @ingroup     <drv>
/// @brief       <receive msg from antoher ecu by ethernet>


#ifndef ETHERNETDRIVERSERVER_HPP
#define ETHERNETDRIVERSERVER_HPP

#include"interface.hpp"

namespace drv
{


class Ethernetdriverserver:public pub::Interface
    {
    public:
    //static variable
    static pthread_mutex_t mutexeth;
//========================================
/// @brief     <init after deinit, its not initialization!>
/// @param     [IN]  <void>
/// @param     [OUT] <enum-int>
/// @return    <errorcode>
//========================================
    int init();

//========================================
/// @brief     <deinit on reset>
/// @param     [IN]  <void>
/// @param     [OUT] <enum-int>
/// @return    <errorcode>
//========================================
    int deinit();

//========================================
/// @brief     <run from DrvMenager in pthread, its main working loop>
/// @param     [IN]  <void>
/// @param     [OUT] <enum-int>
/// @return    <errorcode>
//========================================
    void *initialize(void);


//========================================
/// @brief     <initialize pthread run method>
/// @param     [IN]  <>
/// @param     [OUT] <>
/// @return    <>
//========================================
    static void *initializess(void *);


    };    //class prototypes

}     //namespace drv

#endif //ETHERNETDRIVERSERVER_HPP



