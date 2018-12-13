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
//#include <arpa/inet.h> // inet_pton inet_addr      //???????
#include <sys/socket.h> // AF_UNIX
#include"IEthernetdriverserver.hpp"
#include"Iethernet.hpp"
//#include"pub/eEcuNum.h"
//#include"../MSGVerificator/MSGveryficator.hpp"
#include"eEcuNum.h"
#include"MSGveryficator.hpp"
#include"ILogger.h"

namespace drv
{
    class Candriverserver:public pub::IEthernetdriverserver, public drv::Iethernet
    {
        public:
        Candriverserver(srv::ILogger &a_oLogger,drv::MSGveryficator &a_oMSGver);
        /// @brief destructor
        ~Candriverserver();
        /// @brief mutex and thread variables
        static pthread_mutex_t m_Mutexeth;           //mutex for pause & resume
        static pthread_t m_Thread_id;                //thread for main loop

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
        /// @brief     <deinit on reset>
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
        /// @brief     error code variable
        eErrorCodes m_eRetEr;
        /// @brief     variables to sockets
        int32_t m_i32ServerSockfd;                 //socked s1
        int32_t m_i32ServerSockfd2;                //socked s2
        static char m_cBufferSS[ ];      //send
        static char m_cBufferRR[ ];      //recieve

        struct sockaddr_can addr;
        struct can_frame frame;
        struct can_frame frame2;
        struct ifreq ifr;

        char  buff[20];
        static char ifname[];




        /// @brief     for main loop, if false- stop
        bool m_bIsWorking;
        /// @brief     variable if mRun was runned
        bool m_bWasRunned;
        /// @brief     buffer size variable
        static const uint16_t m_u16BuffSize=4096;
        /// @brief     pointers to antoher objects
        srv::ILogger &m_LoggerRef;
        drv::MSGveryficator &m_MsgverRef;



    };    //class prototypes

}     //namespace drv

#endif //CANDRIVERSERVER_HPP



