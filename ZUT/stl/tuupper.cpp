#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

std::string mojs="moj napis";


string upper(const std::string &s)
{
    std::string ss;
    std::for_each(begin(s),end(s), [&ss](char c) { ss+=::toupper(c); });

return ss;
}


int main ()
{

    
//upper(mojs);

std::cout<<mojs<<std::endl;

std::cout<<upper(mojs)<<std::endl;


return 0;


}




