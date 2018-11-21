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

using namespace drv;



int main ()
{
Ethernetdriverserver* myethserver=new Ethernetdriverserver();
MSGveryficator *fakemsgveryficator=new MSGveryficator();

//pthread_t thread_id;
//pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);

myethserver->setMsgVeryficator(fakemsgveryficator);

myethserver->mRun();


char tekst[]="wyslane z moj ";



myethserver->send(tekst);
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

pthread_mutex_destroy(&Ethernetdriverserver::mutexeth);

//delete myethserver;



return 0;
}



