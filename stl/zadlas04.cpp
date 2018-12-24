#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<fstream>

using namespace std;




int main (int argc,char**argv)
{

if(argc<2)
{}
else
{
    std::string arg=argv[1];
  
    std::ifstream file { arg.c_str() };
file.open(arg.c_str());
file.unsetf(std::ios_base::skipws);
char c;
    while(file >> c)
    {
            cout<<c;
    }
}
cout<<endl;
return 0;
}




