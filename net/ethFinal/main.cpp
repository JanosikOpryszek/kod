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
#include"MSGveryficator.hpp"
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
Ethernetdriverserver* myethserver=new Ethernetdriverserver();
MSGveryficator* fakemsgveryficator=new MSGveryficator();
srv::ILogger* fakeloger=new Loger();

//pthread_t thread_id;
//pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);

myethserver->setLogger(fakeloger);

std::cout<<"Logger pointer set"<<std::endl;
myethserver->setMsgVeryficator(fakemsgveryficator);
std::cout<<"msgver pointer set"<<std::endl;
myethserver->mRun();

std::cout<<"mRun started"<<std::endl;

//char tekst[]="wyslane z moj ";
std::string tekst("wyslane z mojego");



myethserver->send(tekst);

std::cout<<"send msg"<<std::endl;
sleep(1);
myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);


std::cout<<"                                 ,,,,,,,,,,,,,,,,,,blokuje odczyt ale wysylam"<<std::endl;
myethserver->mPause();

sleep(2);
myethserver->send(tekst);
sleep(2);
myethserver->send(tekst);
sleep(2);
myethserver->send(tekst);
sleep(2);
myethserver->send(tekst);
sleep(2);
myethserver->send(tekst);

std::cout<<"                                ******************odblokowuje odczyt"<<std::endl;
myethserver->mResume();


myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);
while(1)
{
myethserver->send(tekst);
sleep(1);
}
std::cout<<"koniec"<<std::endl;
//pthread_join(thread_id, NULL);

//pthread_mutex_destroy(&Ethernetdriverserver::mutexeth);

//delete myethserver;



return 0;
}



