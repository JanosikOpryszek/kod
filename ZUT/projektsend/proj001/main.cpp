#include<iostream>
#include <gtk/gtk.h>
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









int main (int    argc,
          char **argv)
{



ImsgvermethodPut* fakemsgveryficator=new ImsgvermethodPut();
srv::ILogger* fakeloger=new Loger();
Candriverserver* myeth=new Candriverserver(*fakeloger,*fakemsgveryficator);

//Iethernet* myethserver1=myeth;
drv::ICandriverserver* myethserver2=myeth;
myethserver2->init();
//pthread_t thread_id;
//pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);

bool version;
std::cout<<"Sending (car emulation) press 0, receiving (tester emulation) press 1: ";
std::cin >> version;

std::string tekst;
sleep(1);

if(version)
{
myethserver2->mRun();
std::cout<<"reading messages (tester emulation)"<<std::endl;
}
else
{
    while(1)
    {
        //send coolant temp
        tekst="105#";
        tekst+="023";
        myethserver2->send(tekst);
        tekst.clear();
        usleep(100000);
        //send fuler presure
        tekst="10a#";
        tekst+="100";
        myethserver2->send(tekst);
        tekst.clear();
        usleep(100000);
        //send rpm
        tekst="10c#";
        tekst+="200";
        myethserver2->send(tekst);
        tekst.clear();
        usleep(100000);



    }
}



while(1)
{

}



return 0;
}



