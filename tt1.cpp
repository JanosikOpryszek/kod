#include<iostream>



using namespace std;

class Bazowa
{
public:
    int a;
    int b;
    Bazowa(int a,int b):a(a),b(b){}

};


class Pochodna :public Bazowa
{
public:
    static int c;
    Pochodna(int a, int b ):Bazowa(a,b){}

};

//zmienna statyczna klasy moze byc inicjalizowana tylko w obszarze globalnym, nie w konstruktorze
int Pochodna::c=3;


int main()
{

//Tworzymy obiekty klasy pochodnej ale typu klasy bazowej
Bazowa *obiekt=new Pochodna(1,2);
Bazowa *obiekt2=new Pochodna(5,6);


//to nie zadziala !!!
//obiekt->c=4;
//bo
//dostep do pola c zdefiniowanego w klasie pochodnej tylko po kastowaniu na obiekt typem klasy pochodnej
static_cast<Pochodna*>(obiekt)->c=4;


//tu tak samo nie zadziala, bo z punktu widzenia typu klasy bazowej pole c nie istnieje
//cout<<obiekt->c<<endl;

//wiec kastujemy
cout<<static_cast<Pochodna*>(obiekt)->c<<endl;

//jak widać zmienna statyczna wspolna dla obu obiektow
cout<<static_cast<Pochodna*>(obiekt2)->c<<endl;


return 0;
}
