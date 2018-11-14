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
Ethernetdriverserver* myethserver=new Ethernetdriverserver();
Ethernetdriverclient* myethclient=new Ethernetdriverclient();


pthread_t thread_id;
pthread_t thread_id2;

pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);
pthread_create(&thread_id2,NULL,&Ethernetdriverclient::initializess,myethclient);

//pthread_join(thread_id, NULL);

//pthread_join(thread_id2, NULL);

sleep(1);
pthread_mutex_lock( &Ethernetdriverclient::mutexeth );
sleep(10);


return 0;
}



