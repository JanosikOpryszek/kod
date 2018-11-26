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
#include<string.h> // memset strlen
#include<arpa/inet.h> // inet_pton inet_addr
#include<sys/socket.h> // AF_UNIX
#include"Ethernetdriverserver.hpp"


pthread_mutex_t drv::Ethernetdriverserver::m_Mutexeth;           //mutex for pause & resume
pthread_t drv::Ethernetdriverserver::m_Thread_id;                //thread for main loop
char drv::Ethernetdriverserver::m_cIpAdd[]="192.168.255";
char drv::Ethernetdriverserver::m_cBufferSS[ 4096 ];      //send
char drv::Ethernetdriverserver::m_cBufferRR[ 4096 ];      //recieve


drv::Ethernetdriverserver::Ethernetdriverserver(srv::ILogger &a_oLogger,drv::MSGveryficator &a_oMSGver ): m_LoggerRef(a_oLogger), m_MsgverRef(a_oMSGver)
{
    drv::Ethernetdriverserver::m_u16IpPort=9742;
    drv::Ethernetdriverserver::m_bIsWorking=true;
    
}

drv::Ethernetdriverserver::~Ethernetdriverserver()
{

}

eErrorCodes drv::Ethernetdriverserver::mStop()
{
    m_eRetEr=OK;
    m_bIsWorking=false;
    drv::Ethernetdriverserver::m_LoggerRef.mLog_DBG(std::string("ETHdriver DBG - got mStop, main loop stooped, ready to close- OK"));
    return m_eRetEr;
}   //Ethernetdriverserver::mStop()


eErrorCodes drv::Ethernetdriverserver::mResume()
{
    m_eRetEr=OK;
    pthread_mutex_unlock( &drv::Ethernetdriverserver::m_Mutexeth );
    drv::Ethernetdriverserver::m_LoggerRef.mLog_DBG(std::string("ETHdriver DBG - got mResume, main loop unlocked - OK"));
    return m_eRetEr;
}   //Ethernetdriverserver::mResume()


eErrorCodes drv::Ethernetdriverserver::mPause()
{
    m_eRetEr=OK;
    pthread_mutex_lock( &drv::Ethernetdriverserver::m_Mutexeth );
    drv::Ethernetdriverserver::m_LoggerRef.mLog_DBG(std::string("ETHdriver DBG - got mPause, main loop locked - OK"));
    return m_eRetEr;
}   //Ethernetdriverserver::mPause


eErrorCodes drv::Ethernetdriverserver::mRun()  //starts main loop in initialize
{
    m_eRetEr=OK;
    drv::Ethernetdriverserver::m_LoggerRef.mLog_DBG(std::string("ETHdriver DBG - got mRun, main loop started - OK"));
    if((pthread_create(&drv::Ethernetdriverserver::m_Thread_id,0,&drv::Ethernetdriverserver::initializess,this))<0)
    {
        drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - initializess pthreat create error - ERR"));
        m_eRetEr=DRIVER_ERROR;
    }
    return m_eRetEr;
}   //Ethernetdriverserver::mRun()
    

void *drv::Ethernetdriverserver::initialize()    //void using explanation: - used static wrapper class, to run pthreads
{
    //1 SOCKET CREATE for serwer
    m_i32ServerSockfd = socket(AF_INET,SOCK_DGRAM,0);
    if (m_i32ServerSockfd <0 )
    {
        drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - serverSocked creation error  - ERR"));
    }
    //2 ACTIVATE STRUCTURE serwer -me
    m_soServer.sin_family      = AF_INET;
    m_soServer.sin_addr.s_addr = static_cast<uint32_t>(INADDR_ANY);
    m_soServer.sin_port        = htons(m_u16IpPort); // port
    //3 BINDING socket
    socklen_t len = sizeof( m_soServer );
    if ((bind( m_i32ServerSockfd,reinterpret_cast<struct sockaddr*>(&m_soServer),len)) <0)
    {
        drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked binding error  - ERR"));
    }
    //4 READING from network & PutMSG to MSGveryficator
    while(m_bIsWorking)                                                                   //M A I N  L O O P - reading network
    {
        pthread_mutex_unlock( &drv::Ethernetdriverserver::m_Mutexeth );             //mutex for pause & resume
        memset( m_cBufferRR, 0, sizeof( m_cBufferRR ) );
        if(recv( m_i32ServerSockfd, m_cBufferRR, sizeof( m_cBufferRR ), 0)<0)
        {
            drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked reciving error  - ERR"));
        }
        m_MsgverRef.mPutMessage(std::string(m_cBufferRR));  // CALL MSGVERYFICATOR INTERFACE HERE to pass MSG   (by string)
        pthread_mutex_lock( &drv::Ethernetdriverserver::m_Mutexeth );
    }
    return 0;
}   //Ethernetdriverserver::intialize()


void *drv::Ethernetdriverserver::initializess(void *context)
{
    return ( static_cast<drv::Ethernetdriverserver *>(context))->drv::Ethernetdriverserver::initialize();
}   //Ethernetdriverserver::initializess


eErrorCodes drv::Ethernetdriverserver::send(std::string a_strTab)                   //public interface method to let sending msg in network
{
    m_eRetEr=OK;
    //1 SOCKET CREATE for client
    m_i32ServerSockfd2 = socket(AF_INET,SOCK_DGRAM,0);
    if (m_i32ServerSockfd2<0)
    {
         drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked client create error  - ERR"));
         m_eRetEr=DRIVER_ERROR;
    }
    int broadcastEnable=1;
    if ((setsockopt(m_i32ServerSockfd2, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable)))<0)
    {
        drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked client SETOPTION error  - ERR"));
        m_eRetEr=DRIVER_ERROR;
    }
    //2 ACTIVATE STRUCTURE client
    m_soClient1.sin_family      = AF_INET;
    m_soClient1.sin_addr.s_addr = inet_addr(m_cIpAdd);
    m_soClient1.sin_port        = htons(m_u16IpPort); // port
    //3 COPY string msg to Buffer
    socklen_t len2  = sizeof(m_soClient1 );
    strcpy (m_cBufferSS,a_strTab.c_str()  );    //copy string param to char array Buffer
    //4 SENDING
    if((sendto( m_i32ServerSockfd2, m_cBufferSS, strlen( m_cBufferSS ), 0,reinterpret_cast< struct sockaddr * >(& m_soClient1), len2))<0)
    {
        drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked client SENDTO error  - ERR"));
        m_eRetEr=DRIVER_ERROR;
    }
    memset( m_cBufferSS, 0, sizeof( m_cBufferSS ) );
    return m_eRetEr;
}   //Ethernetdriverserver::send




