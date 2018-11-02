#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<stdlib.h>
#include <thread>
#include <string>

using namespace std;

//                         EXAMPLE   komponent - INTERFACE - dependency komponent 

class Interface01 {
    public:
    virtual void pracuj()=0;
};


class DrStudent: public Interface01                       //interface dependency, student's method pracuj is runing by interface
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


class DrProfesor: public Interface01                       //second interface dependency, Profesor's method pracuj is runing by interface
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
    std::list <Interface01*> obserwatorzy;
public:
    void dodaj(Interface01 *o) {
        obserwatorzy.push_back (o);
    }
    void usun(Interface01 *o) {
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

Interface01* mojstudent=new DrStudent();         //create ob Student in  InterfaceDep type
Interface01* mojprofesor=new DrProfesor();         //create ob Profesor in  InterfaceDep type



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

