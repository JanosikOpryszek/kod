#include<iostream>
#include<vector>
#include<array>
using namespace std;

template <int T,typename D,bool heap>
struct Array
{

Array()
{
}    
std::vector<D> mojav;
std::array<D,T> mojaa;
int it=0;


D& operator[] (int n)
{
if(heap)
    return mojav[n];
else
    return mojaa[n];
}

void operator+=(D zm)
{
if(heap)
    mojav.push_back(zm);
else
    mojaa[it++]=zm;
}


D& begin()
{
if(heap)
    return mojav.front();
else
    return mojaa.front();
}


D& end()
{
if(heap)
    return mojav.back();
else
    return mojaa.back();
}

};



int main()
{


Array<10,int,false> aaa;

aaa+=10;
aaa+=20;
aaa+=30;

std::cout<<aaa[2]<<std::endl;


return 0;
}

