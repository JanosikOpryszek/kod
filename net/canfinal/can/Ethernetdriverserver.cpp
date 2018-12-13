//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <Ethernetdriverserver.cpp>
/// @ingroup     <drv>
/// @brief       <receive msg from antoher ecu by ethernet>
#include<stdlib.h>  //atoi
#include <stdio.h>  //sprintf

#include<pthread.h>
#include<string>
#include<iostream>
#include<unistd.h>  // sleep
#include<string.h> // memset strlen strcpy
#include<arpa/inet.h> // inet_pton inet_addr
#include<sys/socket.h> // AF_UNIX
#include"Ethernetdriverserver.hpp"

//Definition of mutex & pthread
pthread_mutex_t drv::Ethernetdriverserver::m_Mutexeth;           //mutex for pause & resume
pthread_t drv::Ethernetdriverserver::m_Thread_id;                //thread for main loop
//set buffer size of char array for sockets work.
char drv::Ethernetdriverserver::m_cBufferSS[ m_u16BuffSize ];      //send
char drv::Ethernetdriverserver::m_cBufferRR[ m_u16BuffSize ];      //recieve
//char drv::Ethernetdriverserver::m_cIpAdd[]="192.168.0.255";

char drv::Ethernetdriverserver::ifname[] = "can0";                                            // ifname can


drv::Ethernetdriverserver::Ethernetdriverserver(srv::ILogger &a_oLogger,drv::MSGveryficator &a_oMSGver ): m_LoggerRef(a_oLogger), m_MsgverRef(a_oMSGver)
{
  //  drv::Ethernetdriverserver::m_u16IpPort=9742;
    drv::Ethernetdriverserver::m_bIsWorking=true;
    drv::Ethernetdriverserver::m_bWasRunned=false;    
}

drv::Ethernetdriverserver::~Ethernetdriverserver()
{
pthread_mutex_destroy(&drv::Ethernetdriverserver::m_Mutexeth);
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
if(m_bWasRunned)
    {
        drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - mRun runned second time - ERR"));
        m_eRetEr=DRIVER_ERROR;
    }
    else
    {
        m_eRetEr=OK;
        m_bWasRunned=true;
        drv::Ethernetdriverserver::m_LoggerRef.mLog_DBG(std::string("ETHdriver DBG - got mRun, main loop started - OK"));
        if((pthread_create(&drv::Ethernetdriverserver::m_Thread_id,0,&drv::Ethernetdriverserver::initializess,this))<0)
        {
            drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - initializess pthreat create error - ERR"));
            m_eRetEr=DRIVER_ERROR;
        }   
    }
    return m_eRetEr;
}   //Ethernetdriverserver::mRun()
    

void *drv::Ethernetdriverserver::initialize()    //void using explanation: - used static wrapper class, to run pthreads
{
    //1 SOCKET CREATE for serwer
    m_i32ServerSockfd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (m_i32ServerSockfd <0 )
    {
        drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - serverSocked creation error  - ERR"));
    }
    //2 ACTIVATE STRUCTURE serwer -me

    strcpy(ifr.ifr_name, ifname);
    ioctl(m_i32ServerSockfd, SIOCGIFINDEX, &ifr);
    addr.can_family  = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;


    //3 BINDING socket
    if ((bind( m_i32ServerSockfd,reinterpret_cast<struct sockaddr*>(&addr),sizeof(addr))) <0)
    {
        drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked binding error  - ERR"));
    }
    //4 READING from network & PutMSG to MSGveryficator
    while(m_bIsWorking)                                                                   //M A I N  L O O P - reading network
    {
        pthread_mutex_unlock( &drv::Ethernetdriverserver::m_Mutexeth );             //mutex for pause & resume
        memset( m_cBufferRR, 0, sizeof( m_cBufferRR ) );
 /*       if(recv( m_i32ServerSockfd, m_cBufferRR, sizeof( m_cBufferRR ), 0)<0)
        {
            drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked reciving error  - ERR"));
        }
 */
        if(recv( m_i32ServerSockfd, &frame2, sizeof( struct can_frame ), 0)<0)
        {
            drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked reciving error  - ERR"));
        }



        std::cout<<"canID"<<frame2.can_id<<std::endl;
        int size = frame2.can_dlc;
        std::cout<<"canSize"<<size<<std::endl;
        int i=0;
        for (;i<size;i++)
        {
        std::cout<<"write from frame2.data ="<<frame2.data[i]<<std::endl;
        m_cBufferRR[i]=frame2.data[i];       //-'0';
        }
        m_cBufferRR[i]='\0';


        m_MsgverRef.mPutMessage(std::string(m_cBufferRR));  // CALL MSGVERYFICATOR INTERFACE HERE to pass MSG   (by string)
        pthread_mutex_lock( &drv::Ethernetdriverserver::m_Mutexeth );
    }
    return 0;
}   //Ethernetdriverserver::intialize()


void *drv::Ethernetdriverserver::initializess(void *context)
{
    return ( reinterpret_cast<drv::Ethernetdriverserver *>(context))->drv::Ethernetdriverserver::initialize();
}   //Ethernetdriverserver::initializess


eErrorCodes drv::Ethernetdriverserver::send(std::string a_strTab)                   //public interface method to let sending msg in network
{
    m_eRetEr=OK;
    //1 SOCKET CREATE for client
    m_i32ServerSockfd2 = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (m_i32ServerSockfd2<0)
    {
         drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked client create error  - ERR"));
         m_eRetEr=DRIVER_ERROR;
    }

    //2 ACTIVATE STRUCTURE client

                                  //powtornie ??

    //3 COPY string msg to Buffer

    strcpy (m_cBufferSS,a_strTab.c_str()  );    //copy string param to char array Buffer

    std::cout<<"BufferSS: "<<m_cBufferSS<<std::endl;
    char index1[2];
    index1[0]=m_cBufferSS[0];
    index1[1]='\0';
    uint32_t intindex1= atoi (index1);    //char array number to int
    intindex1*=100;
    std::cout<<"intindex1: "<<intindex1<<std::endl;

    char index2[3];
    index2[0]=m_cBufferSS[2];
    index2[1]=m_cBufferSS[3];
    index2[2]='\0';
    uint32_t intindex2= atoi (index2);
    std::cout<<"intindex2: "<<intindex2<<std::endl;

    intindex1+=intindex2;

    //char msg[8];
    //sprintf(msg,"%x",intindex1);    //converts int to hexadecimal base char array
    uint8_t size=a_strTab.length();
    size-=4;


    frame.can_id  = intindex1;         //zobaczyc jak wyglada msg
    frame.can_dlc = size;                 // liczyc po dlugosci dostarczonego stringa
    for (int i=0;i<size;i++)
    {
    std::cout<<"write to frame.data ="<<m_cBufferSS[i+4]<<std::endl;
    frame.data[i] = m_cBufferSS[i+4];
    }


    //4 SENDING

    if((sendto( m_i32ServerSockfd2, &frame, sizeof (struct can_frame ), 0,reinterpret_cast< struct sockaddr * >(& addr), sizeof(addr)))<0)
    {
        drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked client SENDTO error  - ERR"));
        m_eRetEr=DRIVER_ERROR;
    }
    /*                                                                              // albo
    if((write(m_i32ServerSockfd2, &frame, sizeof(struct can_frame)))<0)
    {
        drv::Ethernetdriverserver::m_LoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked client SENDTO error  - ERR"));
        m_eRetEr=DRIVER_ERROR;
    }

*/
    memset( m_cBufferSS, 0, sizeof( m_cBufferSS ) );
    return m_eRetEr;
}   //Ethernetdriverserver::send




