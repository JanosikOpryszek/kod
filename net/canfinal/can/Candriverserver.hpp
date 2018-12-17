//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <Candriverserver.hpp>
/// @ingroup     <drv>
/// @brief       <receive msg from antoher ecu by Can>


#ifndef CANDRIVERSERVER_HPP
#define CANDRIVERSERVER_HPP

#include <net/if.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include<pthread.h>
#include<stdint.h>
#include <sys/socket.h>
#include"ICandriverserver.hpp"
//#include"Iethernet.hpp"
//#include"pub/eEcuNum.h"
//#include"../MSGVerificator/imsgvermethod.hpp"
#include"eEcuNum.h"
#include"imsgvermethod.hpp"
#include"ILogger.h"

namespace drv
{
    class Candriverserver:public drv::ICandriverserver
    {
        public:
        Candriverserver(srv::ILogger &a_oLogger,drv::ImsgvermethodPut &a_oMSGver);
        /// @brief destructor
        ~Candriverserver();
        /// @brief mutex and thread variables
        pthread_mutex_t m_Mutexeth;
        pthread_t m_Thread_id;

        //========================================
        /// @brief     <initialization!>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum errorcode>
        /// @return    <errorcode>
        //========================================
        eErrorCodes init();

        //========================================
        /// @brief     <deinitialization!>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum errorcode>
        /// @return    <errorcode>
        //========================================
        eErrorCodes deinit();

        //========================================
        /// @brief     <Resume after Pause, its not initialization!>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum errorcode>
        /// @return    <errorcode>
        //========================================
        eErrorCodes mResume();

        //========================================
        /// @brief     <Pause on reset>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum errorcoed>
        /// @return    <errorcode>
        //========================================
        eErrorCodes mPause();

        //========================================
        /// @brief     <deinit>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum-errorcode>
        /// @return    <errorcode>
        //========================================
        eErrorCodes mStop();

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
        void *Work(void);

        //========================================
        /// @brief     <initialize pthread run method>
        /// @param     [IN]  <>
        /// @param     [OUT] <>
        /// @return    <>
        //========================================
        static void *RunWork(void *);

        //========================================
        /// @brief     <send msg to ethernet>
        /// @param     [IN]  <char array with msg>
        /// @param     [OUT] <enumerrorcode>
        /// @return    <errorcode>
        //========================================
        eErrorCodes send(std::string);

        private:
        /// @brief  <Candriverserver copy constructor>
        Candriverserver(const Candriverserver &arg);
        /// @brief  <Candriverserver assignment constructor>
        Candriverserver& operator=(const Candriverserver &arg);
        /// @brief     buffer size variable
        static const uint16_t m_u16BuffSize=1024;

        /// @brief     error code variable
        eErrorCodes m_eRetEr;
        /// @brief     variables for sockets
        int32_t m_i32ServerSockfd;
        int32_t m_i32ServerSockfd2;
        static char m_cBufferSS[ ];      //send
        static char m_cBufferRR[ ];      //recieve
        struct sockaddr_can addr;
        struct can_frame m_soCanFrameSS;
        struct can_frame m_soCanFrameRR;
        struct ifreq m_soiFreq;
        static char  m_cBufferTmp[];
        static char m_soCanName[];

        /// @brief     for main loop, if false- stop
        bool m_bIsWorking;
        /// @brief     variable- if mRun was runned
        bool m_bWasRunned;
        /// @brief     variable- if Init was runned
        bool m_bWasInit;

        /// @brief     references to antoher objects
        srv::ILogger &m_LoggerRef;
        drv::ImsgvermethodPut &m_MsgverRef;

    };    //class prototypes

}     //namespace drv

#endif //CANDRIVERSERVER_HPP



