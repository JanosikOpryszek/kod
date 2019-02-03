#include<iostream>
#include<string>
#include<pthread.h>
#include<unistd.h>  // sleep

#include <stdlib.h> // exit()             ??
#include <string.h> // memset strlen
#include <arpa/inet.h> // inet_pton inet_addr
#include <sys/socket.h> // AF_UNIX
#include <netinet/in.h> // sockaddr_in    ??
#include"Candriverserver.hpp"
#include"Iethernet.hpp"
#include"ICandriverserver.hpp"
#include"imsgvermethod.hpp"
#include"eErrorCodes.h"
#include"ILogger.h"
//#include"Loger.hpp"

using namespace drv;




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
ImsgvermethodPut* fakemsgveryficator=new ImsgvermethodPut();
srv::ILogger* fakeloger=new Loger();
Candriverserver* myeth=new Candriverserver(*fakeloger,*fakemsgveryficator);

//Iethernet* myethserver1=myeth;
drv::ICandriverserver* myethserver2=myeth;
myethserver2->init();
//pthread_t thread_id;
//pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);

myethserver2->mRun();
std::cout<<"mRun started"<<std::endl;

std::string tekst;
sleep(1);




while(1)
{
    std::cout <<" 05(05)-cooland tem=A-40, 12(0c)RMP (2568A+B)/4, 12(0d) speed\n";
    std::cout << " podaj message id#data 00c#12345678: ";
    std::cin >> tekst;
    std::cout << "\npodales: " << tekst <<std::endl;
    myethserver2->send(tekst);
    tekst.clear();
    sleep(1);
}

return 0;
}



