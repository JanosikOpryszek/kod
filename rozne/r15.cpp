#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<stdlib.h>
//#include <thread>
#include<pthread.h>
#include <string>
#include<unistd.h>  // sleep

using namespace std;
//                                    Multithread wersja POSIX  dodanie STATYCZNEJ metody
//                         EXAMPLE   komponent - INTERFACE - dependency komponent + MULTITHREAD
//                          odwrotnie interface -> interfacedep  

class Interface {
    public:
    virtual void pracuj()=0;
};


class Student: public Interface                       //interface dependency, student's method pracuj is runing by interface
{
public:
    int id=0;
    void pracuj ()
    {
    int licz=10;
    while (licz--)
    {
    id+=1;
    cout<<id<<endl;                                    
//   std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    };
};


class Profesor: public Interface                       //second interface dependency, Profesor's method pracuj is runing by interface
{
public:
    int id=0;
    void pracuj ()
    {
    int licz=10;
    while (licz--)
    {
    id-=1;
    cout<<id<<endl;                                    
//   std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    };
};



class InterfaceDep {                                       //Interface (remeber list of dependent object)

protected:
    std::list <Interface*> obserwatorzy;
public:
    void dodaj(Interface *o) {
        obserwatorzy.push_back (o);
    }
    void usun(Interface *o) {
        obserwatorzy.remove (o);
    }
};

class Komponent1:public InterfaceDep                      //komponent with interface 
{
    public:
    void inform()
        {                            
        std::list<Interface *>::iterator it;
        for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) 
            (*it)->pracuj ();
        }

void *wyswietl()
{

int licz=48;
bool flag=1;
while(1)
{

if (flag)
    {
    if(licz<50)
        {
        licz++;
        if(licz==49)
            flag=0;
        }
    }
else
    {
    if(licz>0)
        {
        licz--;
        if(licz==1)
            flag=1;
        }
    }


for(int i=0;i<licz;i++)
    cout<<"XX";

cout<<endl;
//std::this_thread::sleep_for(std::chrono::milliseconds(100));
sleep(1);
}
}



    void *pracuj()
    {
    while(1)
        {
//   std::this_thread::sleep_for(std::chrono::milliseconds(100));
    sleep(1);
    inform();
        }
    }


// dodanie metod statycznych (i zamiana metod pracuj i wyswietl na wskaznikowe funkcje)
// https://stackoverflow.com/questions/1151582/pthread-function-from-a-class

static void *pracujss(void *context)
{
return ((Komponent1 *)context)->pracuj();
}


static void *wyswietlss (void *context)
{
return ((Komponent1 *)context)->wyswietl();
}


};



int main()
{

Komponent1* mojkomponent=new Komponent1();              //create ob Komponentu1 with interface

Interface* mojstudent=new Student();         //create ob Student in  InterfaceDep type
Interface* mojprofesor=new Profesor();         //create ob Profesor in  InterfaceDep type


mojkomponent->dodaj(mojstudent);                           //register next dependency object in komponent with interface list
mojkomponent->dodaj(mojprofesor);                           //register next dependency object in komponent with interface list




//zamiana watkow c++11  na  POSIX    STATYCZNE metody
//std::thread th(&Komponent1::pracuj, mojkomponent);
//std::thread th2(&Komponent1::wyswietl, mojkomponent);
pthread_t  thread_id;
pthread_t  thread_id2;

//POSIX nie potrafi wywolac metod obiektow, wiec wywoluje statyczne
pthread_create(&thread_id,NULL,&Komponent1::pracujss,mojkomponent);
pthread_create(&thread_id2,NULL,&Komponent1::wyswietlss,mojkomponent);

int licz=0;
bool flag=1;
while(1)
{

if (flag)
    {
    if(licz<50)
        {
        licz++;
        if(licz==49)
            flag=0;
        }
    }
else
    {
    if(licz>0)
        {
        licz--;
        if(licz==1)
            flag=1;
        }
    }


for(int i=0;i<licz;i++)
    cout<<"*";

cout<<endl;
//std::this_thread::sleep_for(std::chrono::milliseconds(100));
sleep(1);
}



return 0;
}

