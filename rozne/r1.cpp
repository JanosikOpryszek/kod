#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<stdlib.h>
#include <thread>
#include <string>

using namespace std;


//https://pl.wikibooks.org/wiki/Kody_%C5%BAr%C3%B3d%C5%82owe/Obserwator_(wzorzec_projektowy)


class Obserwator {
    public:
    virtual void update()=0;
};

class Obserwowany {
protected:
    std::list <Obserwator*> obserwatorzy;
public:
    void dodaj(Obserwator *o) {
        obserwatorzy.push_back (o);
    }
    void usun(Obserwator *o) {
        obserwatorzy.remove (o);
    }
 
    void powiadom () {
        std::list<Obserwator *>::iterator it;
        for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) {
            (*it)->update ();
        }
    }
};



class Student: public Obserwowany 
{
public:
    int id;

    int get_id() {return id;};
    void set_id(int value) {id=value;};
    void pracuj ()
    {
    int licz=100;
    while (licz--)
    {
    id+=1;
    powiadom();                                    //powiadom obserwatora 

   std::this_thread::sleep_for(std::chrono::milliseconds(100));

//   cout<<id<<endl;                              //wyswietlanie przekazane do obserwatora
    }
    };

Student(unsigned int init_val) {id = init_val;};   // constructor
~Student() {};                                     // destructor
};

class Odczyt:public Obserwator
{
    int id1;
protected:
    int obId;                                     //zapisz id obiektu ktorym jestes
    Student *obiekt;                              //zapisz wskaznik na obserwowany obiekt
public:
    Odczyt (Student *h, int id) {                 //konstruktor (wskaznik na obserwowany, od ktorym jestes)
        obiekt = h;
        obId = id;
    }
        void update (){                           //twoja funkcja ktora wywoluje obserwowany 
       
        id1=obiekt->get_id();
        cout<<id1<<endl;
        }


    int get_id() {return id1;};
    void set_id(int value) {id1=value;};
};

std::vector<int> vectorint;           
std::vector<char> vectorchar;           

int main()
{

Student* mojstudent=new Student(10);              //stworzenie obiektu obserwowanego

Obserwator* mis1=new Odczyt(mojstudent,1);         //stworzenie obserwatora
mojstudent->dodaj(mis1);                           //zarejestrowanie obserwatora


//watki w c++
std::thread th(&Student::pracuj, mojstudent);
//th.join();
//mojstudent->pracuj();



while(1)
{
cout<<"odliczanie:" <<endl;

   std::this_thread::sleep_for(std::chrono::milliseconds(100));
}


return 0;
}

