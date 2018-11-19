#include<iostream>
#include<string>
#include<pthread.h>
#include<unistd.h>  // sleep
#include"ethernetdriverclient.hpp"
#include"ethernetdriverserver.hpp"

using namespace drv;
using namespace std;


int main ()
{
Ethernetdriverserver* myethserver=new(std::nothrow) Ethernetdriverserver();
Ethernetdriverclient* myethclient=new(std::nothrow) Ethernetdriverclient();


pthread_t thread_id;
pthread_t thread_id2;

pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);
pthread_create(&thread_id2,NULL,&Ethernetdriverclient::initializess,myethclient);

sleep(3);
cout<<"                               ...................blokuje clienta"<<endl;
myethclient->deinit();
sleep(3);
cout<<"                            ++++++++++++++++++odblokowuje clienta"<<endl;
myethclient->init();
sleep(3);
cout<<"                                 ,,,,,,,,,,,,,,,,,,blokuje server"<<endl;
myethserver->deinit();
sleep(3);
cout<<"                                ******************odblokowuje server"<<endl;
myethserver->init();
sleep(3);
cout<<"koniec"<<endl;
//pthread_join(thread_id, NULL);
//pthread_join(thread_id2, NULL);

pthread_mutex_destroy(&Ethernetdriverclient::mutexeth);
pthread_mutex_destroy(&Ethernetdriverserver::mutexeth);

//delete myethclient;
//delete myethserver;



return 0;
}



