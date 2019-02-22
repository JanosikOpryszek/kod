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
#include"ICandriverserver.hpp"
#include"imsgvermethod.hpp"
#include"eErrorCodes.h"
#include"ILogger.h"
#include"Loger.hpp"

using namespace drv;

void sendmsg(drv::ICandriverserver*);
static char msgTmp[3];
static int temp=23;
static int presure=100;
static int rpm=200;
static std::string tekst;





int main ()
{
    ImsgmethodPut* msgmetput=new ImsgmethodPut();
    srv::ILogger* loger=new Loger();

    drv::ICandriverserver* mycandrv=new Candriverserver(*loger,*msgmetput);
    mycandrv->init();


    bool version;
    std::cout<<"Sending (car emulation)       press 0"<<std::endl;
    std::cout<<"Receiving (tester emulation)  press 1: ";
    std::cin >> version;


    //jesli 1 tylko odczyt msg czyli mRun
    if(version)
    {
        mycandrv->mRun();
        std::cout<<"reading messages (tester emulation)"<<std::endl;
    }
    //jesli 0 tylko wysylanie msg
    else
    {
        sendmsg(mycandrv);
    }


    char c;
    std::cout<<"press x + enter to exit! "<<std::endl;
    std::cin>>c;
    mycandrv->mStop();

    return 0;
}


void sendmsg(drv::ICandriverserver* mycandrv)
{

    while(1)
    {
        //send coolant temp
        tekst="105#";
        sprintf(msgTmp,"%d",temp);    //sprintf - converts int to decimal base char array
        tekst+=msgTmp;
        mycandrv->send(tekst);
        tekst.clear();
        usleep(100000);
        //send fuler presure
        tekst="10a#";
        sprintf(msgTmp,"%d",presure);    //sprintf - converts int to decimal base char array
        tekst+=msgTmp;
        mycandrv->send(tekst);
        tekst.clear();
        usleep(100000);
        //send rpm
        tekst="10c#";
        sprintf(msgTmp,"%d",rpm);    //sprintf - converts int to decimal base char array
        tekst+=msgTmp;
        mycandrv->send(tekst);
        tekst.clear();
        usleep(100000);
    }

}

