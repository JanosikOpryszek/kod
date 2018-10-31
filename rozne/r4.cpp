#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<stdlib.h>
#include <thread>
#include <string>

using namespace std;

//                         EXAMPLE   komponent - INTERFACE - dependency komponent 
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
   std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    };
};


class Profesor: public Interface                       //second obj. with interface
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
   std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    };
};



class InterfaceDep {                                       //DepInterface (remeber list of obiect with inter.)

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

class Komponent1:public InterfaceDep                      //komponent  Dependent from interface 
{
    public:
    void inform()
        {                            
        std::list<Interface *>::iterator it;
        for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) 
            (*it)->pracuj ();
        }
};



int main()
{

Komponent1* mojkomponent=new Komponent1();              //create ob Komponentu1 with interface

Interface* mojstudent=new Student();         //create ob Student in  InterfaceDep type
Interface* mojprofesor=new Profesor();         //create ob Profesor in  InterfaceDep type



mojkomponent->dodaj(mojstudent);                           //register next dependency object in komponent with interface list
mojkomponent->dodaj(mojprofesor);                           //register next dependency object in komponent with interface list

//watki w c++
//std::thread th(&Student::pracuj, mojstudent);
//th.join();




while(1)
{
cout<<"odliczanie:" <<endl;

   std::this_thread::sleep_for(std::chrono::milliseconds(100));
   mojkomponent->inform();
}


return 0;
}

