//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <Ethernetdriverserver.cpp>
/// @ingroup     <drv>
/// @brief       <receive msg from antoher ecu by ethernet>

#include<pthread.h>
#include<iostream>
#include<unistd.h>  // sleep
#include <string.h> // memset strlen
#include <arpa/inet.h> // inet_pton inet_addr
#include <sys/socket.h> // AF_UNIX
#include"Ethernetdriverserver.hpp"

namespace drv
{

    pthread_mutex_t Ethernetdriverserver::mutexeth;     //mutex for pause & resume
    pthread_t Ethernetdriverserver::thread_id;          //thread for main loop
    eErrorCodes Ethernetdriverserver::retEr;          //variable to return errorcode
    int Ethernetdriverserver::server_sockfd;          
    int Ethernetdriverserver::server_sockfd2;          
    int Ethernetdriverserver::server_sockfd3;          
    int Ethernetdriverserver::server_sockfd4;          
    char Ethernetdriverserver::bufferSS[ 4096 ];      //send
    char Ethernetdriverserver::bufferRR[ 4096 ];      //recieve
    sockaddr_in Ethernetdriverserver::server;
    sockaddr_in Ethernetdriverserver::client1;
    sockaddr_in Ethernetdriverserver::client2;
    sockaddr_in Ethernetdriverserver::client3;
    sockaddr_in Ethernetdriverserver::from;
    socklen_t Ethernetdriverserver::len;
    socklen_t Ethernetdriverserver::len2;
    //add pointer to configurator
    //add pointer to logger
    //add pointer to msgveryfikator




eErrorCodes Ethernetdriverserver::mStop()
    {
    retEr=OK;
    //stop for shutdown code...
    return retEr;
    }


eErrorCodes Ethernetdriverserver::mResume()
    {
    retEr=OK;
    pthread_mutex_unlock( &Ethernetdriverserver::mutexeth );
    return retEr;
    }    //Ethernetdriverserver::init()


eErrorCodes Ethernetdriverserver::mPause()
    {
    retEr=OK;
    pthread_mutex_lock( &Ethernetdriverserver::mutexeth );
    return retEr;
    } //Ethernetdriverserver::deinit()


eErrorCodes Ethernetdriverserver::mRun()
    {
    retEr=OK;
    //use configurator interface  and read config, set it code...
    //
    //start in thread inicialize main loop:
    pthread_create(&Ethernetdriverserver::thread_id,NULL,&Ethernetdriverserver::initializess,this);
    return retEr;
    }


eErrorCodes Ethernetdriverserver::setconfigurator()
    {
    retEr=OK;
    //pass by methods argument pointer of pointer to configurator code...
    return retEr;
    }


eErrorCodes Ethernetdriverserver::setlogger()
    {
    retEr=OK;
    //pass by methods argument pointer of pointer to logger code...
    return retEr;
    }


eErrorCodes Ethernetdriverserver::setmsgveryficator()
    {
    retEr=OK;
    //pass by methods argument pointer of pointer to msgveryficator code...
    return retEr;
    }


void *Ethernetdriverserver::initialize()    //void explen: - used static wrapper class to run pthreads
    {
    // (1) socket create for serwer
    server_sockfd = socket(AF_INET,SOCK_DGRAM,0);       

    //2 ACTIVATE STRUCTURE serwer me
    server.sin_family      = AF_INET;
    server.sin_addr.s_addr = inet_addr("192.168.230.128");
    server.sin_port        = htons(9748); // port

    socklen_t len = sizeof( server );
    bind( server_sockfd,( struct sockaddr * ) & server, len);

    while(1)                                                                   //main loop reading network
        {
        pthread_mutex_unlock( &Ethernetdriverserver::mutexeth );             //mutex for pause & resume
        memset( bufferRR, 0, sizeof( bufferRR ) );
        sockaddr_in from={};
        recvfrom( server_sockfd, bufferRR, sizeof( bufferRR ), 0,( struct sockaddr * ) & from, & len);
        std::cout<<"Odczytane: "<<bufferRR<<std::endl;
        // CALL MSGVERYFICATOR INTERFACE HERE -  to pass MSG from network to ecu
        pthread_mutex_lock( &Ethernetdriverserver::mutexeth );
        }
    } //Ethernetdriverserver::intialize()


void *Ethernetdriverserver::initializess(void *context)
    {
    return ((Ethernetdriverserver *)context)->Ethernetdriverserver::initialize();
    } //Ethernetdriverserver::initializess


eErrorCodes Ethernetdriverserver::send(char tab[])                   //public interface method to let sending msg in network
    {
    retEr=OK;
    // (1) socket create for client2
    server_sockfd2 = socket(AF_INET,SOCK_DGRAM,0);       
    // (1) socket create for client3
    server_sockfd3 = socket(AF_INET,SOCK_DGRAM,0);       
    // (1) socket create for client4
    server_sockfd4 = socket(AF_INET,SOCK_DGRAM,0);       
 
    //2 ACTIVATE STRUCTURE client1
    client1.sin_family      = AF_INET;
    client1.sin_addr.s_addr = inet_addr("10.0.2.15");
    client1.sin_port        = htons(9745); // port
    //2 ACTIVATE STRUCTURE client2
    client2.sin_family      = AF_INET;
    client2.sin_addr.s_addr = inet_addr("192.168.0.192");
    client2.sin_port        = htons(9742); // port
    //2 ACTIVATE STRUCTURE client3
    client3.sin_family      = AF_INET;
    client3.sin_addr.s_addr = inet_addr("192.168.0.193");
    client3.sin_port        = htons(9743); // port

    socklen_t len2  = sizeof(client1 );
    strcpy (bufferSS,tab);

    sendto( server_sockfd2, bufferSS, strlen( bufferSS ), 0,( struct sockaddr * ) & client1, len2);
    sendto( server_sockfd3, bufferSS, strlen( bufferSS ), 0,( struct sockaddr * ) & client2, len2);
    sendto( server_sockfd4, bufferSS, strlen( bufferSS ), 0,( struct sockaddr * ) & client3, len2);
    memset( bufferSS, 0, sizeof( bufferSS ) );
    return retEr;
    } //Ethernetdriverserver::send


} //namespace drv


