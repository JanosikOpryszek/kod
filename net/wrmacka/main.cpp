#include<iostream>
#include<string>
#include"Thread.hpp"
#include<pthread.h>
#include<unistd.h>  // sleep
#include"ethernetdriverclient.hpp"
#include"ethernetdriverserver.hpp"

using namespace drv;
using namespace std;


class MyRunnable:public Runnable    //potrzebna tyle dopisac takich klas 
{                                   //ile wraper uruchamia roznych obiektow klas
    Ethernetdriverclient &myClass;
    public:
    MyRunnable(Ethernetdriverclient &myClass):myClass(myClass) {}

    void run() {
        std::cout<<myClass.initialize() <<std::endl;
    }
};



int main ()
{
Ethernetdriverserver* myethserver=new Ethernetdriverserver();
Ethernetdriverclient* myethclient=new Ethernetdriverclient();


cout<<"zaczynaj oba, client i server, client - wraperem, server tradycyjnie uruchomiony"<<endl<<endl;

pthread_t thread_id;
//pthread_t thread_id2;              //tradycyjny sposob
pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);
//pthread_create(&thread_id2,NULL,&Ethernetdriverclient::initializess,myethclient);


MyRunnable mr (*myethclient);         //WRAPER 
Thread t1(&mr);


sleep(4);
cout<<"                               ......DEINIT....blokuje clienta"<<endl;
myethclient->deinit();
sleep(4);
cout<<"                            +++++++++INIT+++++++++odblokowuje clienta"<<endl;
myethclient->init();
sleep(4);
cout<<"                                 ,,,,,,DEINIT,,,,,,,blokuje server"<<endl;
myethserver->deinit();
sleep(4);
cout<<"                                *******INIT******odblokowuje server"<<endl;
myethserver->init();
sleep(4);
cout<<"koniec"<<endl;

pthread_mutex_destroy(&Ethernetdriverclient::mutexeth);
pthread_mutex_destroy(&Ethernetdriverserver::mutexeth);



return 0;
}



