#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<stdlib.h>
#include <thread>
#include<pthread.h>
#include <string>
#include<unistd.h>  // sleep

using namespace std;
//                                    Multithread wersja POSIX  dodanie rzutowania zamiast statycznych
//                         EXAMPLE   komponent - INTERFACE - dependency komponent + MULTITHREAD
//                          odwrotnie interface -> interfacedep  

class Interface {
    public:
    virtual void pracuj()=0;
};


class Student: public Interface        //interface obserwator, student's method pracuj is runing by interface
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


class Profesor: public Interface       //interface obserwator, Profesor's method pracuj is runing by interface
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



class InterfaceDep {                          //InterfaceDep (remeber list of obserwator object)

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

class Komponent1:public InterfaceDep                      //komponent with interfaceDep
{
    public:
    void inform()
        {                            
        std::list<Interface *>::iterator it;
        for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) 
            (*it)->pracuj ();
        }

void *wyswietl();



    void *pracuj()
    {
    while(1)
        {
   std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    sleep(1);
    inform();
        }
    return NULL;
    }

};



void * Komponent1::wyswietl()
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
std::this_thread::sleep_for(std::chrono::milliseconds(100));
//sleep(1);
}
return NULL;
}




// zamiast metod statycznych tworzymy typ (rzutujemy wskaznik na funkcje na obiekt)
// https://thispointer.com/c-how-to-pass-class-member-function-to-pthread_create/
typedef void * (*THREADFUNCPTR)(void *);

//zamiast tego typu mozna rzutowac  (void *(*)(void*)) 




int main()
{

Komponent1* mojkomponent=new Komponent1();              //create ob Komponentu1 with interface

Interface* mojstudent=new Student();         //create ob Student in  InterfaceDep type
Interface* mojprofesor=new Profesor();         //create ob Profesor in  InterfaceDep type


mojkomponent->dodaj(mojstudent);              //register next dependency object in komponent with interface list
mojkomponent->dodaj(mojprofesor);            //register next dependency object in komponent with interface list




//zamiana watkow c++11  na  POSIX    RZUTOWANIE
//std::thread th(&Komponent1::pracuj, mojkomponent);
//std::thread th2(&Komponent1::wyswietl, mojkomponent);
pthread_t thread_id;
pthread_t thread_id2;

//POSIX nie potrafi wywolac metod obiektow, wiec wywoluje statyczne
pthread_create(&thread_id,NULL,(void*(*)(void*))&Komponent1::pracuj,mojkomponent);

pthread_create(&thread_id2,NULL,(void*(*)(void*))&Komponent1::wyswietl,mojkomponent);

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
std::this_thread::sleep_for(std::chrono::milliseconds(100));
//sleep(1);
}


return 0;
}

