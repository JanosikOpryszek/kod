#include<iostream>
#include<string>
#include<pthread.h>
#include<unistd.h>  // sleep

#include <stdlib.h> // exit()             ??
#include <string.h> // memset strlen
#include <arpa/inet.h> // inet_pton inet_addr
#include <sys/socket.h> // AF_UNIX
#include <netinet/in.h> // sockaddr_in    ??
#include"ethernetdriverserver.hpp"

using namespace drv;
using namespace std;


int main ()
{
Ethernetdriverserver* myethserver=new Ethernetdriverserver();

pthread_t thread_id;
pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);




char tekst[]="wyslane z 193";
while(1)
{
myethserver->send(tekst);
sleep(1);
}

myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);
myethserver->send(tekst);
sleep(1);



/*
cout<<"                                 ,,,,,,,,,,,,,,,,,,blokuje server"<<endl;
myethserver->deinit();
sleep(3);
cout<<"                                ******************odblokowuje server"<<endl;
myethserver->init();
sleep(3);
cout<<"koniec"<<endl;
//pthread_join(thread_id, NULL);
*/
pthread_mutex_destroy(&Ethernetdriverserver::mutexeth);

//delete myethserver;



return 0;
}



