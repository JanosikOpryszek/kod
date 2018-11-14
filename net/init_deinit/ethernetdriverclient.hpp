//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <ethernetdriverclient.hpp>
/// @ingroup     <drv>
/// @brief       <sending msg to antoher ecu by ethernet>


#ifndef ETHERNETDRIVERCLIENT_HPP
#define ETHERNETDRIVERCLIENT_HPP

#include"interface.hpp"

namespace drv
{

class Ethernetdriverclient:public pub::Interface
    {
    public:

    //class variables
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

#endif //ETHERNETDRIVERCLIENT_HPP



