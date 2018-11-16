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

using namespace drv;
using namespace std;


int main ()
{
Ethernetdriverserver* myethserver=new Ethernetdriverserver();


//pthread_t thread_id;
//pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);

myethserver->mRun();


char tekst[]="wyslane z 191";


myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);


cout<<"                                 ,,,,,,,,,,,,,,,,,,blokuje odczyt ale wysylam"<<endl;
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

cout<<"                                ******************odblokowuje odczyt"<<endl;
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
cout<<"koniec"<<endl;
//pthread_join(thread_id, NULL);

pthread_mutex_destroy(&Ethernetdriverserver::mutexeth);

//delete myethserver;



return 0;
}



