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
#include"ILogger.h"

namespace drv
{
    class Ethernetdriverserver:public pub::IEthernetdriverserver, public drv::Iethernet
    {
        public:
        Ethernetdriverserver(srv::ILogger &a_oLogger,drv::MSGveryficator &a_oMSGver);
        /// @brief destructor
        ~Ethernetdriverserver();
        /// @brief mutex and thread variables
        static pthread_mutex_t m_Mutexeth;           //mutex for pause & resume
        static pthread_t m_Thread_id;                //thread for main loop

        //========================================
        /// @brief     <init after deinit, its not initialization!>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum errorcode>
        /// @return    <eErrorCode>
        //========================================
        eErrorCodes mResume();

        //========================================
        /// @brief     <deinit on reset>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum errorcoed>
        /// @return    <eErrorCode>
        //========================================
        eErrorCodes mPause();

        //========================================
        /// @brief     <stop main loop and end thread>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum-errorcode>
        /// @return    <eErrorCode>
        //========================================
        eErrorCodes mStop();

        //========================================
        /// @brief     <set conf and starts iner thread>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum-errorcode>
        /// @return    <eErrorCode>
        //========================================
        eErrorCodes mRun();

        eErrorCodes deinit();
        //========================================
        /// @brief     <initialize pthread work method>
        /// @param     [IN]  <void>
        /// @param     [OUT] <void>
        /// @return    <void>
        //========================================
        static void *RunWork(void *);

        //========================================
        /// @brief     <send msg to ethernet>
        /// @param     [IN]  <std::string with msg>
        /// @param     [OUT] <enumerrorcode>
        /// @return    <eErrorCode>
        //========================================
        eErrorCodes send(std::string);

        private:
        //========================================
        /// @brief     <its main working loop, runed in thread>
        /// @param     [IN]  <void>
        /// @param     [OUT] <enum-int>
        /// @return    <eErrorCode>
        //========================================
        void *work(void);

        std::string toString(u_int8_t i);

        /// @brief     error code variable
        eErrorCodes m_eRetEr;
        /// @brief     variables to sockets
        int32_t m_i32ServerSockfd;
        int32_t m_i32ServerSockfd2;
        static char m_cBufferSS[ ];  //send
        static char m_cBufferRR[ ];  //recieve
        static char m_cIpAdd[ ];
        struct sockaddr_in m_soServer;
        struct sockaddr_in m_soClient1;
        struct sockaddr_in m_soFrom ;
        socklen_t m_Len;
        socklen_t m_Len2;
        uint16_t m_u16IpPort;
        /// @brief     for main loop, if false- stop
        bool m_bIsWorking;
        /// @brief     variable if mRun was runned
        bool m_bWasRunned;
        /// @brief     references to antoher objects
        srv::ILogger &m_rLoggerRef;
        drv::MSGveryficator &m_rMsgverRef;



    };    //class prototypes

}     //namespace drv

#endif //ETHERNETDRIVERSERVER_HPP



