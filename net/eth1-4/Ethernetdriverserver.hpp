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

#include"IEthernetdriverserver.hpp"
#include"Iethernet.hpp"

namespace drv
{

class Ethernetdriverserver:public pub::IEthernetdriverserver, drv::Iethernet 
    {
    public:
//    ~Ethernetdriverserver(){};
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
    eErrorCodes setconfigurator();

    //========================================
    /// @brief     <set pointer to logger>
    /// @param     [IN]  <logger pointer>
    /// @param     [OUT] <enum-errorcode>
    /// @return    <errorcode>
    //========================================
    eErrorCodes setlogger();

    //========================================
    /// @brief     <set pointer to msgveryfikator>
    /// @param     [IN]  <msgveryficator pointer>
    /// @param     [OUT] <enum-errorcode>
    /// @return    <errorcode>
    //========================================
    eErrorCodes setmsgveryficator();

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
    eErrorCodes send(char []);

private:
    static eErrorCodes retEr;
    static int server_sockfd;          
    static int server_sockfd2;          
    static int server_sockfd3;          
    static int server_sockfd4;          
    static char bufferSS[ 4096 ];      //send
    static char bufferRR[ 4096 ];      //recieve
    static struct sockaddr_in server; 
    static struct sockaddr_in client1;
    static struct sockaddr_in client2;
    static struct sockaddr_in client3;
    static struct sockaddr_in from ;
    static socklen_t len; 
    static socklen_t len2; 
    //add pointers declarations to config, logger, msgveryficator

    };    //class prototypes

}     //namespace drv

#endif //ETHERNETDRIVERSERVER_HPP



