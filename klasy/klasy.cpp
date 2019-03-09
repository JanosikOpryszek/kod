#include<iostream>
#include<string>
#include <memory>
#include"klasy.hpp"

namespace std
{




Moja::Moja():mojs("przykladowy tekst")
{
    cout<< " konstruktor bezparam"<<endl;
}

Moja::Moja(string a)
{
    mojs=a;
    cout<< " konstruktor parametrowy"<<endl;
}

Moja::~Moja()
{}


Moja::Moja(Moja& other)                 //konstruktor kopiujacy
{                                       //Konstruktor kopiuj¹cy uruchamia siê jeœli przypisujesz wartoœc
     cout<<"KOPIUJACY"<<endl;           //w chwili tworzenia obiektu
     mojs=other.mojs;
}

Moja::Moja(Moja&& other)                //konstruktor przenoszacy (gdy uzywasz std::move )
{
     cout<<"PRZENOSZACY"<<endl;
     mojs=other.mojs;
     other.mojs='\0';
}


Moja& Moja::operator=(const Moja& other)    //operator przypisania , jeœli przypisujesz póŸniej ni¿
{                                           //w chwili tworzenia obiektu, chyba ze jest przenoszacy
    cout<<"OPERATOR PRZYPISANIA ="<<endl;
    mojs=other.mojs;
    return *this;
}


Moja& Moja::operator=(Moja&& other)         // przenosz¹cy operator przypisania jeœli przypisujesz póŸniej ni¿
{                                           //w chwili tworzenia obiektu, jesli operator stworzony to uzywany ten!
    cout<<"przenoszacy operator przypisania"<<endl;

    if (this != &other)
    {
        mojs=other.mojs;
        delete(&other);
    }
    return *this;
}

void Moja::printt()
{
    cout<<mojs<<endl;
}


//************************************** MM ********************************
MM::MM()
{
    //moja = Moja("aa");  //dodanie tego sprawi, ¿e prawa strona uruchomi konstruktor parametrowy
                       //znak przypisania uruchomi  "przenosz¹cy operator przypisania"
                        //jeœli jest, jeœli nie, uruchomi zwyk³y operator przypisania

    //ptrmoja=new Moja("pp");  //tu pomimo operatora przypisania, nastêpuje tylko przypisanie wskaŸnika
                            // wiec nie uruchomi sie przenosz¹cy operator przypisania

    //moja=*ptrmoja;      //to natomiast uruchomi operator przypisania (nie przenosz¹cy) dlatego, ¿e
                       //obiekt *ptrmoja nie zniknie po tej operacji (prawa strona nie jest r-wartoscia)


    moja=Moja(std::move (Moja("pp")));  //move uruchamia semantykê przenoszenia czyli przenoszacy
}

MM::~MM()
{}



void MM::pp()
{
    moja.printt();
    ptrmoja->printt();
}



}// namespace







