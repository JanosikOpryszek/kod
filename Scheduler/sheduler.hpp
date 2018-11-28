//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <sheduler.hpp>
/// @ingroup     <rte>
/// @brief       <run and control rte and swc komponents>


#ifndef SHEDULER_HPP
#define SHEDULER_HPP

#include<pthread.h>
#include<iostream>
#include<unistd.h>  // sleep
#include"ISheduler.h"
//#include"pub/ISwC.h"
//#include"pub/eStates.h"
#include"swc/ISwC.h"
#include"eStates.h"

//#include"swc/TMSwC/timemaster.h"
//#include"swc/SMSwC/SensorMasterImpl.h"
//#include"swc/IPCSwC/IPCSwC.hpp"
//#include"rte/CommunicationMgr/CommunicationMgrImplementation.h"
//#include"swc/HUSwC/HUSwC.hpp"

#include"swc/timemaster.h"
#include"swc/SensorMasterImpl.h"
#include"swc/IPCSwC.hpp"
#include"rte/CommunicationMgrImplementation.h"
#include"swc/HUSwC.hpp"

#include<new>
#include<stdint.h>
#include"Ticks.hpp"
#include"Loger.hpp"

namespace rte
{

class Sheduler:public rte::ISheduler
    {
    public:
    /// @brief Constructor
    Sheduler(srv::ILogger &a_oLogger);
    /// @brief Destructor
    ~Sheduler();

    //========================================
    /// @brief     <react on state changes>
    /// @param     [IN]  <void>
    /// @param     [OUT] <enum-int>
    /// @return    <errorcode>
    //========================================
    eErrorCodes mOnStateChange(eStates a_sNewState);

    //========================================
    /// @brief     <create object using config data>
    /// @param     [IN]  <void>
    /// @param     [OUT] <enum-errorcode>
    /// @return    <errorcode>
    //========================================
    eErrorCodes objCreation();

    //========================================
    /// @brief     <run on FULOPP its main working loop>
    /// @param     [IN]  <void>
    /// @param     [OUT] <void>
    /// @return    <void>
    //========================================
    void *initialize(void);

    //========================================
    /// @brief     <initialize pthread run method>
    /// @param     [IN]  <void>
    /// @param     [OUT] <void>
    /// @return    <void>
    //========================================
    static void *initializess(void *);

    private:
    /// @brief     mutex and pthread variables mutex for pause & resume, thread for main loop
    static pthread_mutex_t m_Mutexeth;
    static pthread_t m_Thread_id;
    /// @brief     error code variable
    eErrorCodes m_eRetEr;
    /// @brief     my state variable
    eStates m_eMyState;
    /// @brief     variable for main loop
    bool m_bIsWorking;
    /// @brief     variable for sheduling time
    uint16_t m_u16Microseconds;
    uint16_t m_u16CpuTicksRatio;
    /// @brief     variable for ref &pointers to: Config,Lgger,Communication,ISwC
    srv::ILogger &m_rLoggerRef;

    static rte::CommunicationMgrImplementation *m_pCommPointer;
    static pub::ISwC *m_pSwCpointer;
    static rte::Ticks *m_pTicks;

    };    //class prototypes

}     //namespace rte

#endif //SHEDULER_HPP



