#include<iostream>
#include<vector>
//using namespace std;



template<class Char>
class String {
public:
String() {}                     //konstruktor


String(const std::string &a)
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


String& operator+=(Char c)        //przeciazony operator +=
{
String::mojvector.push_back(c); 
}




bool operator==(const String &rhs)        //przeciazony operator +=
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

String<char> a;
a+='a';
a+='b';
a+='c';
a+='d';

std::cout<<a[2]<<std::endl;

std::string dupa="hello";

String<char> b(dupa);


if(a==dupa)
    std::cout<<"rowne"<<std::endl;
else
    std::cout<<"rozne"<<std::endl;

return 0;
}

