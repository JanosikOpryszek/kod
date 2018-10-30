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

class InterfaceDep {
    public:
    virtual void pracuj()=0;
};


class Student: public InterfaceDep                       //interface dependency, student's method pracuj is runing by interface
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


class Profesor: public InterfaceDep                       //second interface dependency, Profesor's method pracuj is runing by interface
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



class Interface1 {                                       //Interface (remeber list of dependent object)

protected:
    std::list <InterfaceDep*> obserwatorzy;
public:
    void dodaj(InterfaceDep *o) {
        obserwatorzy.push_back (o);
    }
    void usun(InterfaceDep *o) {
        obserwatorzy.remove (o);
    }
};

class Komponent1:public Interface1                      //komponent with interface 
{
    public:
    void inform()
        {                            
        std::list<InterfaceDep *>::iterator it;
        for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) 
            (*it)->pracuj ();
        }
};



int main()
{

Komponent1* mojkomponent=new Komponent1();              //create ob Komponentu1 with interface

InterfaceDep* mojstudent=new Student();         //create ob Student in  InterfaceDep type
InterfaceDep* mojprofesor=new Profesor();         //create ob Profesor in  InterfaceDep type



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

