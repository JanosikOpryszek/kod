#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

void copiuj( )
{
vector<uint8_t> mojv={10,20,30,40};
 
std::ios::fmtflags old = std::cout.flags();

cout<<std::hex<<endl;

for (auto element :mojv )
    cout<<(int)element<<endl;;

std::cout.setf(old);
cout<<"powrot do OLD"<<endl;


for (auto element :mojv )
    cout<<(int)element<<endl;;


}

int main ()
{
copiuj();
return 0;
}




