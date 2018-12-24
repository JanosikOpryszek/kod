#include<iostream>
#include<string>
#include<pthread.h>
#include<unistd.h>  // sleep

#include <stdlib.h> // exit()             ??
#include <string.h> // memset strlen
#include <arpa/inet.h> // inet_pton inet_addr
#include <sys/socket.h> // AF_UNIX
#include <netinet/in.h> // sockaddr_in    ??
#include"Ethernetdriverserver.hpp"
#include"Iethernet.hpp"
#include"IEthernetdriverserver.hpp"
#include"MSGveryficator.hpp"
#include"eErrorCodes.h"
#include"ILogger.h"
//#include"Loger.hpp"
#include <sstream>   //ostringstream
#include<stdint.h>

using namespace drv;

std::string toString(u_int8_t i)
{
    std::ostringstream ostr;

        ostr << static_cast<uint8_t>(i);

    return ostr.str();
}


class Loger:public srv::ILogger
{

    eErrorCodes errRet;

    public:    
    Loger()
    {
    std::cout<<"Logger created"<<std::endl;
    }

    ~Loger()
    {

    }

    eErrorCodes init()
    {
        errRet=OK;    
        return errRet;
    }

    eErrorCodes deinit()
    {
        errRet=OK;    
        return errRet;
    }



    eErrorCodes mLog_ERR(std::string a_strInput)
    {
        std::cout<<a_strInput<<std::endl;
        errRet=OK;    
        return errRet;
    }


    eErrorCodes mLog_DBG(std::string a_strInput)
    {
        std::cout<<a_strInput<<std::endl;
        errRet=OK;    
        return errRet;
    }

    eErrorCodes mLog_INF(std::string a_strInput)
    {
        std::cout<<a_strInput<<std::endl;
        errRet=OK;    
        return errRet;
    }



    eErrorCodes mLog_WRN(std::string a_strInput)
    {
        std::cout<<a_strInput<<std::endl;
        errRet=OK;    
        return errRet;
    }


};









int main ()
{
drv::MSGveryficator* fakemsgveryficator=new MSGveryficator();
srv::ILogger* fakeloger=new Loger();
Ethernetdriverserver* myeth=new Ethernetdriverserver(*fakeloger,*fakemsgveryficator);

Iethernet* myethserver1=myeth;
pub::IEthernetdriverserver* myethserver2=myeth;

//pthread_t thread_id;
//pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);

myethserver2->mRun();
std::cout<<"mRun started"<<std::endl;

std::string tekst("1000100");
tekst+=toString(0);
tekst+="23";
sleep(1);
std::cout<<tekst<<std::endl;

while(1)
{
    myethserver1->send(tekst);
    std::cin>>tekst;
    sleep(1);
}

return 0;
}



