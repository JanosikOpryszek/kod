//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <Ethernetdriverserver.hpp>
/// @ingroup     <drv>
/// @brief       <receive msg from antoher ecu by ethernet>


#ifndef ETHERNETDRIVERSERVER_HPP
#define ETHERNETDRIVERSERVER_HPP

#include<pthread.h>
#include<stdint.h>
#include <arpa/inet.h> // inet_pton inet_addr
#include <sys/socket.h> // AF_UNIX
#include"IEthernetdriverserver.hpp"
#include"Iethernet.hpp"
//#include"pub/eEcuNum.h"
//#include"../MSGVerificator/MSGveryficator.hpp"
#include"eEcuNum.h"
#include"MSGveryficator.hpp"

namespace drv
{
    class Ethernetdriverserver:public pub::IEthernetdriverserver, public drv::Iethernet
    {
        public:
        Ethernetdriverserver();
        /// @brief destructor
        ~Ethernetdriverserver();
        /// @brief mutex and thread variables
        static pthread_mutex_t m_Mutexeth;           //mutex for pause & resume
        static pthread_t m_Thread_id;                //thread for main loop

        //========================================
        /// @brief     <init after deinit, its not initialization!>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum errorcode>
        /// @return    <errorcode>
        //========================================
        eErrorCodes mResume();

        //========================================
        /// @brief     <deinit on reset>
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
        /// @brief     <set pointer to logger>
        /// @param     [IN]  <logger pointer>
        /// @param     [OUT] <enum-errorcode>
        /// @return    <errorcode>
        //========================================
        eErrorCodes setLogger(srv::ILogger* a_pLogger);

        //========================================
        /// @brief     <set pointer to msgveryfikator>
        /// @param     [IN]  <msgveryficator pointer>
        /// @param     [OUT] <enum-errorcode>
        /// @return    <errorcode>
        //========================================
        eErrorCodes setMsgVeryficator(drv::MSGveryficator *a_pMSGv);

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

        //========================================
        /// @brief     <send msg to ethernet>
        /// @param     [IN]  <char array with msg>
        /// @param     [OUT] <enumerrorcode>
        /// @return    <errorcode>
        //========================================
        eErrorCodes send(std::string);

        private:
        /// @brief     error code variable
        static eErrorCodes m_eRetEr;
        /// @brief     variables to sockets
        static int32_t m_i32ServerSockfd;
        static int32_t m_i32ServerSockfd2;
        static char m_cBufferSS[ 4096 ];      //send
        static char m_cBufferRR[ 4096 ];      //recieve
        static struct sockaddr_in m_soServer;
        static struct sockaddr_in m_soClient1;
        static struct sockaddr_in m_soFrom ;
        static socklen_t m_Len;
        static socklen_t m_Len2;
        static char m_cIpAdd[];
        static uint16_t m_u16IpPort;
        /// @brief     for main loop, if false- stop
        static bool m_bIsWorking;
        /// @brief     pointers to antoher objects
        static drv::MSGveryficator *m_pMsgverpointer;
        static srv::ILogger *m_pLoggerPointer;



    };    //class prototypes

}     //namespace drv

#endif //ETHERNETDRIVERSERVER_HPP



