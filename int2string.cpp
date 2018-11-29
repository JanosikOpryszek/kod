#include<iostream>
#include<string>
#include <sstream>


int main ()
{
int aa=5;
std::string tekst("numer int =");

std::stringstream sstm;
sstm << tekst << aa;
std::string result = sstm.str();

    std::cout<<result<<std::endl;



return 0;
}
