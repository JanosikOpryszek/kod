#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<stdlib.h>
#include <thread>
#include <string>

using namespace std;

//                         EXAMPLE   komponent - INTERFACE - dependency komponent 
//                               wzajemne rejestrowanie obserwatora i obserwowanego podczas dodawania


class Interface1;                                       //Obserwowany Interface Forward declaration dla pointera

class Interface01 {                          //obserwator interface
    public:
    Interface1 *Ob;                         //pointer do obserwowanego
    virtual void pracuj()=0;
};


class Interface1 {                                       //Obserwowany Interface (remeber list of obserwing object)

protected:
    std::list <Interface01*> obserwatorzy;
public:
    virtual void spiewaj()=0;                        //wirtualna metoda wywolywana przez obserwatora
    void dodaj(Interface01 *o) {
        obserwatorzy.push_back (o);
        o->Ob=this;                                     //wpisuje adres obserwatora i podaje mu swoj adres do jego  zmiennej Ob
    }
    void usun(Interface01 *o) {
        obserwatorzy.remove (o);
    }
};

class DrStudent: public Interface01                       //Obserwator with interface , student's method pracuj is runing by interface
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
    Ob->spiewaj();
    };
};


class DrProfesor: public Interface01                       //Obserwator with second interface , Profesor's method pracuj is runing by interface
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
    Ob->spiewaj();
    };
};




class Komponent1:public Interface1                      //komponent obserwowany with interface 
{
    public:
    void spiewaj()
    {
cout<<"TRALALALLALALALALALLA"<<endl;
    }
        
    void inform()
        {                            
        std::list<Interface01 *>::iterator it;
        std::vector<std::thread> myThreads;

        for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) 
            {
            (*it)->pracuj ();
            //       myThreads.push_back(std::thread(&Interface01::pracuj, *it));     //nie dziala
            }
        }
};



int main()
{

Komponent1* mojkomponent=new Komponent1();              //create obserwowany

Interface01* mojstudent=new DrStudent();         //create obserwator Student in 
Interface01* mojprofesor=new DrProfesor();         //create obserwator Profesor in 



mojkomponent->dodaj(mojstudent);                           //register next obserwator object in  obserwiowany list
mojkomponent->dodaj(mojprofesor);                           //register next obserwator object in  obserwowany list

//watki w c++
//std::thread th(&Student::pracuj, mojstudent);
//th.join();




while(1)
{
cout<<"odliczanie:" <<endl;

 std::this_thread::sleep_for(std::chrono::milliseconds(100));
   mojkomponent->inform();                                        //wysylaj powiadomienie do obserwatorow 
}


return 0;
}

