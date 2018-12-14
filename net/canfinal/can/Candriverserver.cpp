//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <Candriverserver.cpp>
/// @ingroup     <drv>
/// @brief       <receive msg from antoher ecu by can>
///
#include<stdlib.h>  //atoi
#include <stdio.h>  //sprintf
#include<pthread.h>
#include<string>
#include<iostream>
#include<unistd.h>  // sleep
#include<string.h> // memset strlen strcpy
//#include<arpa/inet.h> // inet_pton inet_addr
#include<sys/socket.h> // AF_UNIX
#include"Candriverserver.hpp"


char drv::Candriverserver::m_cBufferSS[ m_u16BuffSize ];      //send
char drv::Candriverserver::m_cBufferRR[ m_u16BuffSize ];      //recieve
char  drv::Candriverserver::m_cBufferTmp[m_u16BuffSize];
char drv::Candriverserver::m_soCanName[] = "can0";


drv::Candriverserver::Candriverserver(srv::ILogger &a_oLogger,drv::MSGveryficator &a_oMSGver ):
    m_bIsWorking(true),
    m_bWasRunned(false),
    m_bWasInit(false),
    m_LoggerRef(a_oLogger),
    m_MsgverRef(a_oMSGver)
{

}

drv::Candriverserver::~Candriverserver()
{

}

eErrorCodes drv::Candriverserver::init()
{
    m_eRetEr=OK;
    /// @brief checking if was init
    if(!m_bWasInit)
    {
        /// @brief checking if error
        if( (pthread_mutex_init ( &m_Mutexeth, 0))!=0)
        {
            m_LoggerRef.mLog_ERR(std::string("CANdriver ERR - init mutex init error - ERR"));
            m_eRetEr = RTE_ERROR;
        }
    }
    else
    {
        m_LoggerRef.mLog_ERR(std::string("CANdriver ERR- init() runed AGAIN!!!  "));
        m_eRetEr = RTE_ERROR;
    }
    m_bWasInit=true;

    return m_eRetEr;
}

eErrorCodes drv::Candriverserver::deinit()
{
    m_eRetEr=OK;
    return m_eRetEr;
}

eErrorCodes drv::Candriverserver::mStop()
{
    m_eRetEr=OK;
    m_bIsWorking=false;
    m_LoggerRef.mLog_DBG(std::string("CANdriver DBG - got mStop, main loop stooped, ready to close- OK"));
    return m_eRetEr;
}


eErrorCodes drv::Candriverserver::mResume()
{
    m_eRetEr=OK;
    pthread_mutex_unlock( &m_Mutexeth );
    m_LoggerRef.mLog_DBG(std::string("CANdriver DBG - got mResume, main loop unlocked - OK"));
    return m_eRetEr;
}


eErrorCodes drv::Candriverserver::mPause()
{
    m_eRetEr=OK;
    pthread_mutex_lock( &m_Mutexeth );
    m_LoggerRef.mLog_DBG(std::string("CANdriver DBG - got mPause, main loop locked - OK"));
    return m_eRetEr;
}


eErrorCodes drv::Candriverserver::mRun()
{
if(m_bWasRunned)
    {
        m_LoggerRef.mLog_ERR(std::string("CANdriver ERR - mRun runned second time - ERR"));
        m_eRetEr=DRIVER_ERROR;
    }
    else
    {
        m_eRetEr=OK;
        m_bWasRunned=true;
        m_LoggerRef.mLog_DBG(std::string("CANdriver DBG - got mRun, main loop started - OK"));
        if((pthread_create(&m_Thread_id,0,&RunWork,this))<0)
        {
            m_LoggerRef.mLog_ERR(std::string("CANdriver ERR - initializess pthreat create error - ERR"));
            m_eRetEr=DRIVER_ERROR;
        }   
    }
    return m_eRetEr;
}
    

void *drv::Candriverserver::Work()
{
    //1 SOCKET CREATE for serwer
    m_i32ServerSockfd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (m_i32ServerSockfd <0 )
    {
        m_LoggerRef.mLog_ERR(std::string("CANdriver ERR - serverSocked creation error  - ERR"));
    }
    //2 ACTIVATE STRUCTURE serwer -me

    strcpy(m_soiFreq.ifr_name, m_soCanName);
    ioctl(m_i32ServerSockfd, SIOCGIFINDEX, &m_soiFreq);
    addr.can_family  = AF_CAN;
    addr.can_ifindex = m_soiFreq.ifr_ifindex;


    //3 BINDING socket
    if ((bind( m_i32ServerSockfd,reinterpret_cast<struct sockaddr*>(&addr),sizeof(addr))) <0)
    {
        m_LoggerRef.mLog_ERR(std::string("CANdriver ERR - socked binding error  - ERR"));
    }
    //4 READING from network & PutMSG to MSGveryficator
    while(m_bIsWorking)                                    //M A I N  L O O P - reading canMsg
    {
        pthread_mutex_unlock( &m_Mutexeth );             //mutex for pause & resume
        memset( m_cBufferRR, 0, sizeof( m_cBufferRR ) );

        if(recv( m_i32ServerSockfd, &m_soCanFrameRR, sizeof( struct can_frame ), 0)<0)
        {
            m_LoggerRef.mLog_ERR(std::string("CANdriver ERR - socked reciving error  - ERR"));
        }
        /// @brief     <change 3character canID to 4character MsgID>
        char msgTemp[3];
        sprintf(msgTemp,"%d",m_soCanFrameRR.can_id);    //converts int to decimal base char array
        m_cBufferRR[0]=msgTemp[0];
        m_cBufferRR[1]='0';
        m_cBufferRR[2]=msgTemp[1];
        m_cBufferRR[3]=msgTemp[2];
        /// @brief     <check size of canMsg to iterate>
        int size = m_soCanFrameRR.can_dlc;
        int i=0;
        for (;i<size;i++)
        {
            m_cBufferRR[i+4]=static_cast<char>(m_soCanFrameRR.data[i]);
        }
        m_cBufferRR[i+4]='\0';


        m_MsgverRef.mPutMessage(std::string(m_cBufferRR));  // CALL MSGVERYFICATOR INTERFACE HERE to pass MSG   (by string)
        pthread_mutex_lock( &m_Mutexeth );
    }
    return 0;
}



void *drv::Candriverserver::RunWork(void *context)
{
    return ( reinterpret_cast<drv::Candriverserver *>(context))->drv::Candriverserver::Work();
}



eErrorCodes drv::Candriverserver::send(std::string a_strTab)
{
    m_eRetEr=OK;
    //1 SOCKET CREATE for client
    m_i32ServerSockfd2 = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (m_i32ServerSockfd2<0)
    {
         drv::Candriverserver::m_LoggerRef.mLog_ERR(std::string("CANdriver ERR - socked client create error  - ERR"));
         m_eRetEr=DRIVER_ERROR;
    }

    //2 COPY string msg to Can Struct (ID + data)
    strcpy (m_cBufferSS,a_strTab.c_str()  );    //copy string param to char array Buffer
    /// @brief     <change 4character MsgID to 3character canID>
    char index1[2];
    index1[0]=m_cBufferSS[0];
    index1[1]='\0';
    uint32_t intindex1= static_cast<uint32_t>( atoi (index1));    //char array number to int
    intindex1*=100;
    char index2[3];
    index2[0]=m_cBufferSS[2];
    index2[1]=m_cBufferSS[3];
    index2[2]='\0';
    uint32_t intindex2= static_cast<uint32_t>(atoi (index2));    //char array number to int
    /// @brief     <intindex1=final 3character canID>
    intindex1+=intindex2;
    uint8_t size=static_cast<uint8_t>(a_strTab.length());
    size-=4;                             //4char=MsgID , -4=real size of pure DATA
    m_soCanFrameSS.can_id  = intindex1;
    /// @brief     <check size of canMsg to iterate>
    m_soCanFrameSS.can_dlc = size;
    for (int i=0;i<size;i++)
    {
        m_soCanFrameSS.data[i] = static_cast<uint8_t>(m_cBufferSS[i+4]);
    }

    //4 SENDING
    if((sendto( m_i32ServerSockfd2, &m_soCanFrameSS, sizeof (struct can_frame ), 0,reinterpret_cast< struct sockaddr * >(& addr), sizeof(addr)))<0)
    {
        m_LoggerRef.mLog_ERR(std::string("CANdriver ERR - socked client SENDTO error  - ERR"));
        m_eRetEr=DRIVER_ERROR;
    }
    memset( m_cBufferSS, 0, sizeof( m_cBufferSS ) );
    return m_eRetEr;
}




