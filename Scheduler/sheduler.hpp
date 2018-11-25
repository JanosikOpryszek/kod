//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <sheduler.hpp>
/// @ingroup     <drv>
/// @brief       <run and control rte and swc komponents>


#ifndef SHEDULER_HPP
#define SHEDULER_HPP

#include<pthread.h>
#include<iostream>
#include<unistd.h>  // sleep
#include"ISheduler.h"

namespace rte
{

class Sheduler:public pub::ISheduler
    {
    public:
    static pthread_mutex_t mutexeth;           //mutex for pause & resume
    static pthread_t thread_id;                //thread for main loop


    //========================================
    /// @brief     <init after deinit, its not initialization!>
    /// @param     [IN]  <void>
    /// @param     [OUT] <enum-int>
    /// @return    <errorcode>
    //========================================
    eErrorCodes mOnStateChange(eStates a_sNewState);



    //========================================
    /// @brief     <set pointer to configurator>
    /// @param     [IN]  <configurator pointer>
    /// @param     [OUT] <enum-errorcode>
    /// @return    <errorcode>
    //========================================
    eErrorCodes setconfigurator();

    //========================================
    /// @brief     <set pointer to logger>
    /// @param     [IN]  <logger pointer>
    /// @param     [OUT] <enum-errorcode>
    /// @return    <errorcode>
    //========================================
    eErrorCodes setlogger();

    //========================================
    /// @brief     <set conf and starts iner thread>
    /// @param     [IN]  <void>
    /// @param     [OUT] <enum-errorcode>
    /// @return    <errorcode>
    //========================================
    eErrorCodes mRun();


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

    private:
    static eErrorCodes eRetEr;
    //add pointers declarations to: config  logger


    };    //class prototypes

}     //namespace rte

#endif //SHEDULER_HPP



