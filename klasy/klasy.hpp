#include<iostream>
#include<string>

namespace std
{



class Moja
{
public:
    Moja();
    Moja(string a);
    ~Moja();
    Moja(Moja&);                     // konstruktor kopiujacy
    Moja(Moja&&);                    //konstruktor przenoszacy

    Moja& operator=(const Moja&);  //operator przypisania =
    Moja& operator=(Moja&&);      //przenosz¹cy operator przypisania =

    void printt();

private:
    string mojs;
};

//**************************************** MM****************************************

class MM
{
public:

    MM();
    ~MM();
    void pp();


private:
    Moja moja=Moja("aa");         //uruchomi tylko konstruktor parametrowy
    //Moja moja;                     // uruchomi tylko konstruktor bezparametrowy
    Moja* ptrmoja=new Moja(moja);  //uruchomi  tylko konstruktor KOPIUJACY

};


} // namespace
