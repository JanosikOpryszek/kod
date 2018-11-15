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

    //========================================
    /// @brief     <send msg to ethernet>
    /// @param     [IN]  <char array with msg>
    /// @param     [OUT] <void>
    /// @return    <void>
    //========================================
    void send(char []);

private:
    static int server_sockfd;          
    static int server_sockfd2;          
    static char bufferSS[ 4096 ];      //send
    static char bufferRR[ 4096 ];      //recieve
    static struct sockaddr_in server; 
    static struct sockaddr_in client1;
    static struct sockaddr_in client2;
    static struct sockaddr_in client3;
    static struct sockaddr_in from ;
    static socklen_t len; 
    static socklen_t len2; 


    //========================================
    /// @brief     <reading udp from eth, runed in loop>
    /// @param     [IN]  <void>
    /// @param     [OUT] <void>
    /// @return    <void>
    //========================================
    void read();


    };    //class prototypes

}     //namespace drv

#endif //ETHERNETDRIVERSERVER_HPP



