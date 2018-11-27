//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <sheduler.cpp>
/// @ingroup     <rte>
/// @brief       <run and control rte and swc komponents>


#include"sheduler.hpp"

    pthread_mutex_t rte::Sheduler::m_Mutexeth;
    pthread_t rte::Sheduler::m_Thread_id;
    eErrorCodes rte::Sheduler::m_eRetEr;
    eStates rte::Sheduler::m_eMyState;
    bool rte::Sheduler::m_bIsWorking;
    uint16_t rte::Sheduler::m_u16Microseconds;
    uint16_t rte::Sheduler::m_u16CpuTicksRatio;
    pub::ISwC *rte::Sheduler::m_pSwCpointer;
    rte::ICommunicationMgr *rte::Sheduler::m_pCommPointer;
    rte::Ticks *rte::Sheduler::m_pTicks;


rte::Sheduler::Sheduler(srv::ILogger &a_oLogger,srv::IConfigurator &a_oConf): m_rLoggerRef(a_oLogger), m_rConfRef(a_oConf)
{
    rte::Sheduler::m_eMyState=PRE_START;
    rte::Sheduler::m_bIsWorking=true;
    rte::Sheduler::m_u16CpuTicksRatio=1000;
    rte::Sheduler::m_pCommPointer=new(std::nothrow) rte::CommunicationMgrImplementation(m_rConfRef);   //create obj of Commanager
    rte::Sheduler::m_pTicks=new(std::nothrow) rte::Ticks(m_u16CpuTicksRatio);                          //create obj of Ticker
    rte::Sheduler::m_u16Microseconds=100;


}

eErrorCodes rte::Sheduler::mOnStateChange(eStates a_sNewState)
{
    m_eRetEr=OK;
    switch (a_sNewState)
    {
        case PREPEARING_SYSTEM:
        {
            rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR - got PREPEARING_SYSTEM state - imposibl to got it! - ERR"));
            m_eRetEr=RTE_ERROR;
            break;
        }
        case PRE_START:               //Object creation
        {
            if(m_eMyState==PRE_START)
            {
                rte::Sheduler::objCreation(); //object creation (base on config information)
                rte::Sheduler::m_rLoggerRef.mLog_DBG(std::string("SHEDULER DEBUG: got PRE_START starting object creation - OK "));
                m_eMyState=IDLE;
            }
            else
            {
                rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR: got PRE_START but i was on leater state - ERR "));
                m_eRetEr=RTE_ERROR;
            }
            break;
        }
        case IDLE:               // Ready for INIT
        {
            if(m_eMyState==IDLE || m_eMyState==DEINIT)
            {
                rte::Sheduler::m_rLoggerRef.mLog_DBG(std::string("SHEDULER DEBUG: got IDLE state ready for INIT- OK "));
                m_eMyState=IDLE;
            }
            else
            {
                rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR: got IDLE but im not in IDLE or DEINIT - ERR "));
                m_eRetEr=RTE_ERROR;
            }
            break;
        }
        case INIT:  // back from DEINIT or ready for FULL_OPP
        {
            if(m_eMyState == IDLE || m_eMyState==INIT || m_eMyState == DEINIT)
            {
                pthread_mutex_unlock( &rte::Sheduler::m_Mutexeth); //unblock my own LOOP after deinit
                rte::Sheduler::m_rLoggerRef.mLog_DBG(std::string("SHEDULER DEBUG: got INIT in IDLE or INIT or DEINIT, unlock mutex - OK "));
                m_eMyState=INIT;
            }
            else
            {
                rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR: got IDLE but i was on leater state - ERR "));
                m_eRetEr=RTE_ERROR;
            }
            break;
         }
        case FULL_OP:   //start Main LOOP
        {
            if(m_eMyState<FULL_OP)
            {
                rte::Sheduler::m_rLoggerRef.mLog_DBG(std::string("SHEDULER DEBUG: got got FULL_OP, creating pthread ownl loop - OK "));
               if((pthread_create(&rte::Sheduler::m_Thread_id,0,&rte::Sheduler::initializess,this))<0)
               {
                   rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR:error create pthread initializess own loop - ERR "));
                   m_eRetEr=RTE_ERROR;
               }
                m_eMyState=FULL_OP;
            }
            else
            {
                rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR: got FULL_OP but my state is fullop or higher already  - ERR "));
                m_eRetEr=RTE_ERROR;
            }
            break;
        }
        case DEINIT:
        {
            pthread_mutex_lock( &rte::Sheduler::m_Mutexeth);  //block my own LOOP
            rte::Sheduler::m_rLoggerRef.mLog_DBG(std::string("SHEDULER DEBUG: got DEINIT, lock loop - OK "));
            m_eMyState=DEINIT;
            break;
        }
        case OFF:
        {
            m_eMyState=OFF;
            rte::Sheduler::m_rLoggerRef.mLog_DBG(std::string("SHEDULER DEBUG: got OFF, delete obj & stop LOOP - OK "));
            rte::Sheduler::m_bIsWorking=false;                  // stoop main loop
            delete(rte::Sheduler::m_pSwCpointer);              //delete obj of SwC
            delete(rte::Sheduler::m_pCommPointer);             //delete obj of CommunicationMgr
            pthread_mutex_destroy(&rte::Sheduler::m_Mutexeth);
            break;
        }
    }
    return m_eRetEr;
} //Sheduler::mOnStateChange(eStates a_sNewState)



eErrorCodes rte::Sheduler::objCreation()
{
    m_eRetEr=OK;
    eEcuNum EcuNr=rte::Sheduler::m_rConfRef.getECU(); //run configurathot methos to set Ecu number C O N F I G R E A D I N G

    switch (EcuNr)
    {
        case TM150:
        {
            //object creation ecu1
            if ((rte::Sheduler::m_pSwCpointer=new(std::nothrow) swc::TimeMaster(&(rte::Sheduler::m_rLoggerRef),rte::Sheduler::m_pCommPointer))==0)                //logger & commanager obj by constructor
            {
                rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR:Timemaster obj creation error - ERR "));
                m_eRetEr=RTE_ERROR;
            }
            break;
        } //case TM150

        case HU151:
        {
            //object creation ecu2
            if ((rte::Sheduler::m_pSwCpointer=new(std::nothrow) swc::HUSwC(rte::Sheduler::m_rLoggerRef,*rte::Sheduler::m_pCommPointer))==0)                //logger & commanager obj by constructor
            {
                rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR:Timemaster obj creation error - ERR "));
                m_eRetEr=RTE_ERROR;
            }
            break;
        } //case HU151

        case SM152:
        {
            //object creation ecu3
            if((rte::Sheduler::m_pSwCpointer=new(std::nothrow) swc::SensorMasterImpl(rte::Sheduler::m_rLoggerRef,*rte::Sheduler::m_pCommPointer))==0)
            {
                rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR:SensorMaster obj creation error - ERR "));
                m_eRetEr=RTE_ERROR;
            }
            break;
        } //case SM152

        case IPC153:
        {
            //object creation ecu4
            if((rte::Sheduler::m_pSwCpointer=new(std::nothrow) swc::IPCSwC(rte::Sheduler::m_rLoggerRef,*rte::Sheduler::m_pCommPointer))==0)
            {
                rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR:IPCSwC  obj creation error - ERR "));
                m_eRetEr=RTE_ERROR;
            }
            break;
        } //case IPC153
    }
    return m_eRetEr;
}  //Sheduler::objCreation()



void *rte::Sheduler::initialize()            //  Main L O O P  run in thread on FULL_OP state
{
    while(rte::Sheduler::m_bIsWorking)
    {
        pthread_mutex_lock( &rte::Sheduler::m_Mutexeth);  //block my own LOOP if DEINIT

        if((pthread_create(&rte::Sheduler::m_Thread_id,0,&pub::ISwC::run,m_pSwCpointer))<0)
        {
            rte::Sheduler::m_rLoggerRef.mLog_ERR(std::string("SHEDULER ERR:error in initialize, ISwC.run pthread creation- ERR "));
        }

        //usleep(rte::Sheduler::microseconds);
        m_pTicks->ticks(m_u16Microseconds);    // T I  C  K  S

        pthread_mutex_unlock( &rte::Sheduler::m_Mutexeth);
    }
    return 0;
} //Sheduler::intialize()



void *rte::Sheduler::initializess(void *context)
{
    return ( static_cast<rte::Sheduler *>(context))->rte::Sheduler::initialize();
}  //Sheduler::initializess





