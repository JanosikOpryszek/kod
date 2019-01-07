#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<fstream>

using namespace std;


int main (int argc,char**argv)
{

if(argc<2)
{
    cout<<"arg < 2" <<endl;
}
else
{
    std::string arg=argv[1];
    cout<<arg<<endl;
    std::ifstream file { arg};     
    file.unsetf(std::ios_base::skipws);
    
    if(file.is_open())
    {
        char c;
        while(file >> c)
        {
            cout<<c;
        }
    }
    else
    cout<<"failed to open"<<endl;
}
cout<<endl;
return 0;
}




