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
#include <sstream>   //ostringstream
#include<unistd.h>  // sleep
#include<string.h> // memset strlen
#include<arpa/inet.h> // inet_pton inet_addr
#include<sys/socket.h> // AF_UNIX
#include"Ethernetdriverserver.hpp"


/// @brief set buffer size of char array for sockets work.
static const uint16_t m_u16BuffSize=4096;
char drv::Ethernetdriverserver::m_cBufferSS[ m_u16BuffSize ];
char drv::Ethernetdriverserver::m_cBufferRR[ m_u16BuffSize ];
char drv::Ethernetdriverserver::m_cIpAdd[] = "192.168.0.255";


drv::Ethernetdriverserver::Ethernetdriverserver(srv::ILogger &a_oLogger,drv::MSGveryficator &a_oMSGver ):
    m_eRetEr(OK),
    m_u16IpPort(9742),
    m_bIsWorking(true),
    m_bWasRunned(false),
    m_rLoggerRef(a_oLogger),
    m_rMsgverRef(a_oMSGver)

{
    pthread_mutex_init ( &m_Mutexeth, 0);

} //Ethernetdriverserver Constructor


drv::Ethernetdriverserver::~Ethernetdriverserver()
{
    pthread_mutex_unlock( &m_Mutexeth);
    pthread_mutex_destroy(&m_Mutexeth);
} //Ethernetdriverserver Destructor


eErrorCodes drv::Ethernetdriverserver::mStop()
{
    m_eRetEr = OK;
    m_bIsWorking = false;
    m_rLoggerRef.mLog_INF(std::string("ETHdriver  - got mStop, main loop stooped, ready to close- OK"));
    return m_eRetEr;
}   //Ethernetdriverserver::mStop()


eErrorCodes drv::Ethernetdriverserver::mResume()
{
    m_eRetEr = OK;
    pthread_mutex_unlock( &m_Mutexeth );
    m_rLoggerRef.mLog_INF(std::string("ETHdriver  - got mResume, main loop unlocked - OK"));
    return m_eRetEr;
}   //Ethernetdriverserver::mResume()


eErrorCodes drv::Ethernetdriverserver::mPause()
{
    m_eRetEr = OK;
    pthread_mutex_lock( &m_Mutexeth );
    m_rLoggerRef.mLog_INF(std::string("ETHdriver  - got mPause, main loop locked - OK"));
    return m_eRetEr;
}   //Ethernetdriverserver::mPause


eErrorCodes drv::Ethernetdriverserver::mRun()  //starts main loop in initialize
{
    /// @brief  condition checking if mRun was runed before
    if(m_bWasRunned)
    {
        m_rLoggerRef.mLog_ERR(std::string("ETHdriver ERR - mRun runned second time - ERR"));
        m_eRetEr = DRIVER_ERROR;
    }
    else
    {
        m_eRetEr = OK;
        m_bWasRunned = true;
        m_rLoggerRef.mLog_INF(std::string("ETHdriver  - got mRun, main loop started - OK"));
        if((pthread_create(&m_Thread_id,0,&RunWork,this)) < 0)
        {
            m_rLoggerRef.mLog_ERR(std::string("ETHdriver ERR - got mRun, initializess pthreat create error - ERR"));
            m_eRetEr = DRIVER_ERROR;
        }
    }

    return m_eRetEr;
}//Ethernetdriverserver::mRun()

eErrorCodes drv::Ethernetdriverserver::deinit()
{
    eErrorCodes error = OK;

    return error;
}


void *drv::Ethernetdriverserver::work()    //void using explanation: - used static wrapper class, to run pthreads
{
    //Socket setup for sending (using in send method)
    //1 SOCKET CREATE for client
    m_i32ServerSockfd2 = socket(AF_INET,SOCK_DGRAM,0);
    /// @brief checking if error
    if (m_i32ServerSockfd2 < 0)
    {
        m_rLoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked client create error  - ERR"));
        m_eRetEr = DRIVER_ERROR;
    }
    int broadcastEnable = 1;
    /// @brief checking if error
    if ((setsockopt(m_i32ServerSockfd2, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable))) < 0)
    {
        m_rLoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked client SETOPTION error  - ERR"));
        m_eRetEr = DRIVER_ERROR;
    }
    //2 ACTIVATE STRUCTURE client
    m_soClient1.sin_family      = AF_INET;
    m_soClient1.sin_addr.s_addr = inet_addr(m_cIpAdd);
    m_soClient1.sin_port        = htons(m_u16IpPort); // port


    //Socket setup for recieviwng
    //1 SOCKET CREATE for serwer
    m_i32ServerSockfd = socket(AF_INET,SOCK_DGRAM,0);
    /// @brief checking if error
    if (m_i32ServerSockfd < 0)
    {
        m_rLoggerRef.mLog_ERR(std::string("ETHdriver ERR - serverSocked creation error  - ERR"));
    }
    //2 ACTIVATE STRUCTURE serwer -me
    m_soServer.sin_family      = AF_INET;
    m_soServer.sin_addr.s_addr = static_cast<uint16_t>(INADDR_ANY);
    m_soServer.sin_port        = htons(m_u16IpPort); // port
    //3 BINDING socket
    socklen_t len = sizeof( m_soServer );
    /// @brief checking if error
    if ((bind( m_i32ServerSockfd,reinterpret_cast<struct sockaddr*>(&(m_soServer)),len)) < 0)
    {
        m_rLoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked binding error  - ERR"));
    }
    //4 READING from network & PutMSG to MSGveryficator
    /// @brief MAIN LOOP
    while(m_bIsWorking)
    {
        pthread_mutex_unlock( &m_Mutexeth );             //mutex for pause & resume
        memset( m_cBufferRR, 0, sizeof( m_cBufferRR ) );
        int Received = recv( m_i32ServerSockfd, m_cBufferRR, sizeof( m_cBufferRR ), 0);
        std::cout<<"recieved: "<<Received<<std::endl;
        /// @brief checking if error
        if( Received < 0)
        {
            m_rLoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked reciving error  - ERR"));
        }

        //m_rMsgverRef.putMessage(std::string(m_cBufferRR));  // CALL MSGVERYFICATOR INTERFACE HERE to pass MSG   (by string)

        std::string msg;
        /// @brief iterate to create std::string with char=0
        for (int i=0;i < Received; i++)
        {
            msg += toString(static_cast<u_int8_t>( m_cBufferRR[ i ]) );
        }
        m_rMsgverRef.putMessage(msg);

        pthread_mutex_lock( &m_Mutexeth );
    }
    return 0;
}



void *drv::Ethernetdriverserver::RunWork(void *context)
{
    return ( reinterpret_cast<drv::Ethernetdriverserver *>(context))->work();
}   //Ethernetdriverserver::initializess



eErrorCodes drv::Ethernetdriverserver::send(std::string a_strTab)                   //public interface method to let sending msg in network
{
    m_eRetEr = OK;

    // COPY string msg to Buffer
    socklen_t len  = sizeof(m_soClient1 );
    //strcpy (m_cBufferSS,a_strTab.c_str()  );    //copy string param to char array Buffer
    memcpy(m_cBufferSS, a_strTab.data(), a_strTab.length());
    std::cout<<"got str length"<<a_strTab.length()<<std::endl;

    //4 SENDING
    /// @brief checking if error
    if((sendto( m_i32ServerSockfd2, m_cBufferSS, strlen( m_cBufferSS ), 0,reinterpret_cast< struct sockaddr * >(&(m_soClient1)), len)) < 0)
    {
        m_rLoggerRef.mLog_ERR(std::string("ETHdriver ERR - socked client SENDTO error  - ERR"));
        m_eRetEr = DRIVER_ERROR;
    }
    memset( m_cBufferSS, 0, sizeof( m_cBufferSS ) );
    return m_eRetEr;
}   //Ethernetdriverserver::send


std::string drv::Ethernetdriverserver::toString(u_int8_t i)
{
    std::ostringstream ostr;

        ostr << static_cast<uint8_t>(i);

    return ostr.str();
}


