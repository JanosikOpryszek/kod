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
#include<string>
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
    char Ethernetdriverserver::IpAdd1[14];
    char Ethernetdriverserver::IpAdd2[14];
    char Ethernetdriverserver::IpAdd3[14];
    char Ethernetdriverserver::IpAdd4[14];
    int Ethernetdriverserver::IpPort1;
    int Ethernetdriverserver::IpPort2;
    int Ethernetdriverserver::IpPort3;
    int Ethernetdriverserver::IpPort4;
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
    //use configurator interface  and read config, 
    int EcuNr=2; //run configurathot methos to set Ecu number

    switch (EcuNr)
    {
    case 1:
    {
    strcpy(Ethernetdriverserver::IpAdd1,"192.168.0.111");
    strcpy(Ethernetdriverserver::IpAdd2,"192.168.0.112");
    strcpy(Ethernetdriverserver::IpAdd3,"192.168.0.113");
    strcpy(Ethernetdriverserver::IpAdd4,"192.168.0.114");
    Ethernetdriverserver::IpPort1=9741;
    Ethernetdriverserver::IpPort2=9742;
    Ethernetdriverserver::IpPort3=9743;
    Ethernetdriverserver::IpPort4=9744;
    break;
    }
    case 2:
    {
    strcpy(Ethernetdriverserver::IpAdd1,"192.168.0.112");
    strcpy(Ethernetdriverserver::IpAdd2,"192.168.0.113");
    strcpy(Ethernetdriverserver::IpAdd3,"192.168.0.114");
    strcpy(Ethernetdriverserver::IpAdd4,"192.168.0.111");
    Ethernetdriverserver::IpPort1=9742;
    Ethernetdriverserver::IpPort2=9743;
    Ethernetdriverserver::IpPort3=9744;
    Ethernetdriverserver::IpPort4=9741;
    break;
    }
    case 3:
    {
    strcpy(Ethernetdriverserver::IpAdd1,"192.168.0.113");
    strcpy(Ethernetdriverserver::IpAdd2,"192.168.0.114");
    strcpy(Ethernetdriverserver::IpAdd3,"192.168.0.111");
    strcpy(Ethernetdriverserver::IpAdd4,"192.168.0.112");
    Ethernetdriverserver::IpPort1=9743;
    Ethernetdriverserver::IpPort2=9744;
    Ethernetdriverserver::IpPort3=9741;
    Ethernetdriverserver::IpPort4=9742;
    break;
    }
    case 4:
    {
    strcpy(Ethernetdriverserver::IpAdd1,"192.168.0.114");
    strcpy(Ethernetdriverserver::IpAdd2,"192.168.0.111");
    strcpy(Ethernetdriverserver::IpAdd3,"192.168.0.112");
    strcpy(Ethernetdriverserver::IpAdd4,"192.168.0.113");
    Ethernetdriverserver::IpPort1=9744;
    Ethernetdriverserver::IpPort2=9741;
    Ethernetdriverserver::IpPort3=9742;
    Ethernetdriverserver::IpPort4=9743;
    break;
    }
    default:
    {
    //Logging-  argument error configure ETHdriver
    }
 }
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
    server.sin_addr.s_addr = inet_addr(IpAdd1);
    server.sin_port        = htons(IpPort1); // port

    socklen_t len = sizeof( server );
    bind( server_sockfd,( struct sockaddr * ) & server, len);

    while(1)                                                                   //main loop reading network
        {
        pthread_mutex_unlock( &Ethernetdriverserver::mutexeth );             //mutex for pause & resume
        memset( bufferRR, 0, sizeof( bufferRR ) );
        sockaddr_in from={};
        recvfrom( server_sockfd, bufferRR, sizeof( bufferRR ), 0,( struct sockaddr * ) & from, & len);
        std::cout<<bufferRR<<std::endl;
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
    client1.sin_addr.s_addr = inet_addr(IpAdd2);
    client1.sin_port        = htons(IpPort2); // port
    //2 ACTIVATE STRUCTURE client2
    client2.sin_family      = AF_INET;
    client2.sin_addr.s_addr = inet_addr(IpAdd3);
    client2.sin_port        = htons(IpPort3); // port
    //2 ACTIVATE STRUCTURE client3
    client3.sin_family      = AF_INET;
    client3.sin_addr.s_addr = inet_addr(IpAdd4);
    client3.sin_port        = htons(IpPort4); // port

    socklen_t len2  = sizeof(client1 );
    strcpy (bufferSS,tab);

    sendto( server_sockfd2, bufferSS, strlen( bufferSS ), 0,( struct sockaddr * ) & client1, len2);
    sendto( server_sockfd3, bufferSS, strlen( bufferSS ), 0,( struct sockaddr * ) & client2, len2);
    sendto( server_sockfd4, bufferSS, strlen( bufferSS ), 0,( struct sockaddr * ) & client3, len2);
    memset( bufferSS, 0, sizeof( bufferSS ) );
    return retEr;
    } //Ethernetdriverserver::send


} //namespace drv


