#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

std::string mojs="moj napis";


string upper(const std::string &s)
{
    
std::string nowy;
auto it=begin(nowy);
    std::transform(begin(s),end(s), std::back_inserter(nowy),[](char c) { return ::toupper(c);  });
return nowy;
}


int main ()
{

    
//upper(mojs);

std::cout<<mojs<<std::endl;

std::cout<<upper(mojs)<<std::endl;


return 0;


}




