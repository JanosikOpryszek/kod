#include<iostream>
#include<string>
#include"klasy.hpp"


using namespace std;



//string Moja::mojs="aaaxbbbbyyhwawiwjjjwwm";
//Moja* MM::moja;



Moja::Moja()
{
    mojs="aaaxbbbbyyhwawiwjjjwwm";
    cout<< " konst"<<endl;
}

Moja::Moja(string a)
{
    mojs=a;
    cout<< " konst prze"<<endl;
}

Moja::~Moja()
{

}



void Moja::printt()
{
    cout<<mojs<<endl;
}

MM::MM()
{
    moja = Moja("aa");
   //Moja moja;
   aa=55;
}

MM::~MM()
{

}


void MM::pp()
{
    moja.printt();
}









