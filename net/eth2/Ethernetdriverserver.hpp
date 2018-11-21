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
#include"eEcuNum.h"
//#include"../MSGVerificator/MSGveryficator.hpp"
#include"MSGveryficator.hpp"


namespace drv
{


class Ethernetdriverserver:public pub::IEthernetdriverserver, public drv::Iethernet
    {
    public:
    ~Ethernetdriverserver(){}
    static pthread_mutex_t mutexeth;           //mutex for pause & resume
    static pthread_t thread_id;                //thread for main loop 

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
    /// @brief     <set pointer to configurator>
    /// @param     [IN]  <configurator pointer>
    /// @param     [OUT] <enum-errorcode>
    /// @return    <errorcode>
    //========================================
    eErrorCodes setConfigurator();

    //========================================
    /// @brief     <set pointer to logger>
    /// @param     [IN]  <logger pointer>
    /// @param     [OUT] <enum-errorcode>
    /// @return    <errorcode>
    //========================================
    eErrorCodes setLogger();

    //========================================
    /// @brief     <set pointer to msgveryfikator>
    /// @param     [IN]  <msgveryficator pointer>
    /// @param     [OUT] <enum-errorcode>
    /// @return    <errorcode>
    //========================================
    eErrorCodes setMsgVeryficator(drv::MSGveryficator*);

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
    static eErrorCodes retEr;
    static int32_t server_sockfd;
    static int32_t server_sockfd2;
    static int32_t server_sockfd3;
    static int32_t server_sockfd4;
    static char bufferSS[ 4096 ];      //send
    static char bufferRR[ 4096 ];      //recieve
    static struct sockaddr_in server; 
    static struct sockaddr_in client1;
    static struct sockaddr_in client2;
    static struct sockaddr_in client3;
    static struct sockaddr_in from ;
    static socklen_t len; 
    static socklen_t len2; 
    static char IpAdd1[];
    static char IpAdd2[];
    static char IpAdd3[];
    static char IpAdd4[];
    static uint16_t IpPort1;
    static uint16_t IpPort2;
    static uint16_t IpPort3;
    static uint16_t IpPort4;
    //add pointers declarations to config, logger, msgveryficator
    static MSGveryficator *msgverpointer;


    };    //class prototypes

}     //namespace drv

#endif //ETHERNETDRIVERSERVER_HPP



