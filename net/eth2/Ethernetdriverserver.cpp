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


    pthread_mutex_t Ethernetdriverserver::m_Mutexeth;     //mutex for pause & resume
    pthread_t Ethernetdriverserver::m_Thread_id;          //thread for main loop
    eErrorCodes Ethernetdriverserver::eRetEr;          //variable to return errorcode

    int32_t Ethernetdriverserver::m_i32ServerSockfd;
    int32_t Ethernetdriverserver::m_i32ServerSockfd2;

    char Ethernetdriverserver::m_cBufferSS[ 4096 ];      //send
    char Ethernetdriverserver::m_cBufferRR[ 4096 ];      //recieve
    sockaddr_in Ethernetdriverserver::m_soServer;
    sockaddr_in Ethernetdriverserver::m_soClient1;

    sockaddr_in Ethernetdriverserver::m_soFrom;
    socklen_t Ethernetdriverserver::m_Len;
    socklen_t Ethernetdriverserver::m_Len2;
    char Ethernetdriverserver::m_cIpAdd[14]="192.168.0.255";
    uint16_t Ethernetdriverserver::m_u16IpPort=9742;

    bool Ethernetdriverserver::m_bIsWorking=true;
    MSGveryficator *Ethernetdriverserver::m_pMsgverpointer;            // pointer to configurator
    //add pointer to logger
    //add pointer to msgveryfikator


Ethernetdriverserver::~Ethernetdriverserver()
{


}

eErrorCodes Ethernetdriverserver::mStop()
{
    eRetEr=OK;
    m_bIsWorking=false;
    return eRetEr;
}     //Ethernetdriverserver::Shutdown()


eErrorCodes Ethernetdriverserver::mResume()
{
    eRetEr=OK;
    pthread_mutex_unlock( &Ethernetdriverserver::m_Mutexeth );
    return eRetEr;
}    //Ethernetdriverserver::init()


eErrorCodes Ethernetdriverserver::mPause()
{
    eRetEr=OK;
    pthread_mutex_lock( &Ethernetdriverserver::m_Mutexeth );
    return eRetEr;
} //Ethernetdriverserver::deinit()


eErrorCodes Ethernetdriverserver::mRun()
{
    eRetEr=OK;
    //use configurator interface  and read config, 

    //start in thread inicialize main loop:
    pthread_create(&Ethernetdriverserver::m_Thread_id,0,&Ethernetdriverserver::initializess,this);
    return eRetEr;
}
    

eErrorCodes Ethernetdriverserver::setConfigurator()
{
    eRetEr=OK;
    //pass by methods argument pointer of pointer to configurator code...
    return eRetEr;
}


eErrorCodes Ethernetdriverserver::setLogger()
{
    eRetEr=OK;
    //pass by methods argument pointer of pointer to logger code...
    return eRetEr;
}


eErrorCodes Ethernetdriverserver::setMsgVeryficator(MSGveryficator *a_Obj)
{
    eRetEr=OK;
    Ethernetdriverserver::m_pMsgverpointer=a_Obj;
    //pass by methods argument pointer of pointer to msgveryficator code...
    return eRetEr;
}


void *Ethernetdriverserver::initialize()    //void explen: - used static wrapper class to run pthreads
{
    // (1) socket create for serwer
    m_i32ServerSockfd = socket(AF_INET,SOCK_DGRAM,0);
    if (m_i32ServerSockfd <0 )
    {
        //logger - Socket create error                L O G I N G E R R O R

    }

    //2 ACTIVATE STRUCTURE serwer me
    m_soServer.sin_family      = AF_INET;
    m_soServer.sin_addr.s_addr = static_cast<uint32_t>(INADDR_ANY);
    m_soServer.sin_port        = htons(m_u16IpPort); // port

    socklen_t len = sizeof( m_soServer );
    if ((bind( m_i32ServerSockfd,reinterpret_cast<struct sockaddr*>(&m_soServer),len)) <0)
    {
        //logger Socket binding  error                L O G I N G E R R O R
    }

    while(m_bIsWorking)                                                                   //main loop reading network
    {
        pthread_mutex_unlock( &Ethernetdriverserver::m_Mutexeth );             //mutex for pause & resume
        memset( m_cBufferRR, 0, sizeof( m_cBufferRR ) );
        if(recv( m_i32ServerSockfd, m_cBufferRR, sizeof( m_cBufferRR ), 0)<0)
        {
            //logger Socket recieving  error                L O G I N G E R R O R
        }

        //std::cout<<bufferRR<<std::endl;
        m_pMsgverpointer->mPutMessage(m_cBufferRR);  // CALL MSGVERYFICATOR INTERFACE HERE
                                               //-  to pass MSG from network 
        pthread_mutex_lock( &Ethernetdriverserver::m_Mutexeth );
    }
    return 0;
} //Ethernetdriverserver::intialize()


void *Ethernetdriverserver::initializess(void *context)
{
    return ( static_cast<Ethernetdriverserver *>(context))->Ethernetdriverserver::initialize();
} //Ethernetdriverserver::initializess


eErrorCodes Ethernetdriverserver::send(std::string a_strTab)                   //public interface method to let sending msg in network
{
    eRetEr=OK;

    // (1) socket create for client2
    m_i32ServerSockfd2 = socket(AF_INET,SOCK_DGRAM,0);
    if (m_i32ServerSockfd2<0)
    {
         //logger Socket 2 create error                L O G I N G E R R O R
    }
int broadcastEnable=1;
if((setsockopt(m_i32ServerSockfd2, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable)))<0)
    {   
        //logger Socket 2 set option error
    }

    //2 ACTIVATE STRUCTURE client1
    m_soClient1.sin_family      = AF_INET;
    m_soClient1.sin_addr.s_addr = inet_addr(m_cIpAdd);
    m_soClient1.sin_port        = htons(m_u16IpPort); // port

    socklen_t len2  = sizeof(m_soClient1 );
    strcpy (m_cBufferSS,a_strTab.c_str()  );

    if((sendto( m_i32ServerSockfd2, m_cBufferSS, strlen( m_cBufferSS ), 0,reinterpret_cast< struct sockaddr * >(& m_soClient1), len2))<0)
    {
        //logger Socket 2 create error                L O G I N G E R R O R
    }

    memset( m_cBufferSS, 0, sizeof( m_cBufferSS ) );
    return eRetEr;
} //Ethernetdriverserver::send


} //namespace drv


