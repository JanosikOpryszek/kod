#include<iostream>
#include<vector>
//using namespace std;

template<typename Char>
class String {
public:
String() {}                     //konstruktor

String(const std::string &a)    //konstruktor parametrowy
{
std:copy( a.begin(), a.end(), back_inserter(mojvector) );
}


String(String const &source)               //kopiujacy
{
mojvector=source.mojvector;
}


Char& operator[](int n)        //przeciazony operator []
{
return String::mojvector[n];
}


void operator+=(Char c)        //przeciazony operator +=
{
String::mojvector.push_back(c);
}


bool operator==(const String &rhs)        //przeciazony operator ==
{
if(mojvector==rhs.mojvector)
    return true;
else
    return false;
}

private:
std::vector<char> mojvector;           //Pole
};


int main()
{

String<char> a;    //tworzymy obiekt a
a+='a';            //przeci¹zonym operatorem += dodajemy elementy
a+='b';
a+='c';
a+='d';

std::cout<<a[2]<<std::endl; // wyswietlamy przeciazonym operatorem [] 2 znak

std::string dupa="hello";   // tworzymy string

String<char> b(dupa);       // tworzymy nowy obiekt z wykorzystaniem
                           // konstruktora kopiujacego

if(a==dupa)                 // przeciazony operator ==
    std::cout<<"rowne"<<std::endl;
else
    std::cout<<"rozne"<<std::endl;

return 0;
}

