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
//#include"Iethernet.hpp"
#include"ICandriverserver.hpp"
#include"imsgvermethod.hpp"
#include"eErrorCodes.h"
#include"ILogger.h"
#include"Loger.hpp"

using namespace drv;





int main (int    argc,
          char **argv)
{



ImsgvermethodPut* fakemsgveryficator=new ImsgvermethodPut();
srv::ILogger* fakeloger=new Loger();

drv::ICandriverserver* myethserver2=new Candriverserver(*fakeloger,*fakemsgveryficator);
myethserver2->show();
//pthread_t thread_id;
//pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);

bool version;
std::cout<<"Sending (car emulation)       press 0"<<std::endl;
std::cout<<"Receiving (tester emulation)  press 1: ";
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
    char msgTmp[3];
    int temp=23;
    int presure=100;
    int rpm=200;

    while(1)
    {
        //send coolant temp
        tekst="105#";
        sprintf(msgTmp,"%d",temp);    //sprintf - converts int to decimal base char array
        tekst+=msgTmp;
        myethserver2->send(tekst);
        tekst.clear();
        usleep(100000);
        //send fuler presure
        tekst="10a#";
        sprintf(msgTmp,"%d",presure);    //sprintf - converts int to decimal base char array
        tekst+=msgTmp;
        myethserver2->send(tekst);
        tekst.clear();
        usleep(100000);
        //send rpm
        tekst="10c#";
        sprintf(msgTmp,"%d",rpm);    //sprintf - converts int to decimal base char array
        tekst+=msgTmp;
        myethserver2->send(tekst);
        tekst.clear();
        usleep(100000);



    }
}


    char c;
    std::cout<<"press enter to exit! "<<std::endl;
    std::cin>>c;

    std::cout<<"exited: "<<std::endl;


return 0;
}



