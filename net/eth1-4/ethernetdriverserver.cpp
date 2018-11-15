//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <ethernetdriverserver.cpp>
/// @ingroup     <drv>
/// @brief       <receive msg from antoher ecu by ethernet>

#include<pthread.h>
#include<iostream>
#include<unistd.h>  // sleep

#include <stdlib.h> // exit()             ??
#include <string.h> // memset strlen
#include <arpa/inet.h> // inet_pton inet_addr
#include <sys/socket.h> // AF_UNIX
#include <netinet/in.h> // sockaddr_in    ??

#include"ethernetdriverserver.hpp"
namespace drv
{

    pthread_mutex_t Ethernetdriverserver::mutexeth;

    int Ethernetdriverserver::server_sockfd;          
    int Ethernetdriverserver::server_sockfd2;          
    char Ethernetdriverserver::bufferSS[ 4096 ];      //send
    char Ethernetdriverserver::bufferRR[ 4096 ];      //recieve
    sockaddr_in Ethernetdriverserver::server;
    sockaddr_in Ethernetdriverserver::client1;
    sockaddr_in Ethernetdriverserver::client2;
    sockaddr_in Ethernetdriverserver::client3;
    sockaddr_in Ethernetdriverserver::from;
    socklen_t Ethernetdriverserver::len;
    socklen_t Ethernetdriverserver::len2;

int Ethernetdriverserver::init()
    {
    pthread_mutex_unlock( &Ethernetdriverserver::mutexeth );
    return 0;
    }    //Ethernetdriverserver::init()


int Ethernetdriverserver::deinit()
    {
    pthread_mutex_lock( &Ethernetdriverserver::mutexeth );
    return 0;
    } //Ethernetdriverserver::deinit()


void *Ethernetdriverserver::initialize()
    {
    
    // (1) socket create for serwer
    server_sockfd = socket(AF_INET,SOCK_DGRAM,0);       

    //2 ACTIVATE STRUCTURE serwer JA
    server.sin_family      = AF_INET;
    server.sin_addr.s_addr = inet_addr("192.168.0.193");
    server.sin_port        = htons(9743); // port

    socklen_t len = sizeof( server );

    bind( server_sockfd,( struct sockaddr * ) & server, len);

    while(1)
        {
        //read();
    memset( bufferRR, 0, sizeof( bufferRR ) );
    sockaddr_in from={};
    recvfrom( server_sockfd, bufferRR, sizeof( bufferRR ), 0,( struct sockaddr * ) & from, & len);
    std::cout<<"Odczytane: "<<bufferRR<<std::endl;
    // tu bedzie wywolywal metode msgmenagera zeby mu przekazac do kolejki
        }
    /*    
    while(1)
        {
        pthread_mutex_lock( &mutexeth );
        std::cout<<" SERVER "<<std::endl;
        pthread_mutex_unlock( &mutexeth );
        sleep(1);
        }
    */

    } //Ethernetdriverserver::intialize()



void *Ethernetdriverserver::initializess(void *context)
    {
    return ((Ethernetdriverserver *)context)->Ethernetdriverserver::initialize();
    } //Ethernetdriverserver::initializess



void Ethernetdriverserver::send(char tab[])
    {

    // (1) socket create for client
    server_sockfd2 = socket(AF_INET,SOCK_DGRAM,0);       

    //2 ACTIVATE STRUCTURE client1
    client1.sin_family      = AF_INET;
    client1.sin_addr.s_addr = inet_addr("192.168.0.190");
    client1.sin_port        = htons(9740); // port

    //2 ACTIVATE STRUCTURE client2
    client2.sin_family      = AF_INET;
    client2.sin_addr.s_addr = inet_addr("192.168.0.191");
    client2.sin_port        = htons(9741); // port

    //2 ACTIVATE STRUCTURE client3
    client3.sin_family      = AF_INET;
    client3.sin_addr.s_addr = inet_addr("192.168.0.192");
    client3.sin_port        = htons(9742); // port


    socklen_t len2  = sizeof(client1 );
    strcpy (bufferSS,tab);

    sendto( server_sockfd2, bufferSS, strlen( bufferSS ), 0,( struct sockaddr * ) & client1, len2);
    sendto( server_sockfd2, bufferSS, strlen( bufferSS ), 0,( struct sockaddr * ) & client2, len);
    sendto( server_sockfd2, bufferSS, strlen( bufferSS ), 0,( struct sockaddr * ) & client3, len);
    memset( bufferSS, 0, sizeof( bufferSS ) );
    } //Ethernetdriverserver::send



void Ethernetdriverserver::read()
    {
//    memset( bufferRR, 0, sizeof( bufferRR ) );
//    recvfrom( server_sockfd, bufferRR, sizeof( bufferRR ), 0,( struct sockaddr * ) & from, & len);
//    std::cout<<"Odczytane: "<<bufferRR<<std::endl;
    // tu bedzie wywolywal metode msgmenagera zeby mu przekazac do kolejki
    } //Ethernetdriverserver::read


} //namespace drv


