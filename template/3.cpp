#include<iostream>
#include<vector>
using namespace std;

template <int N,int M,typename T>
struct Matrix
{

Matrix()
{
}    
std::vector<vector<T> > matryca {N,vector<T>(M)};


void operator[] (int n)
{
    int rz=n/M;
    int nr=n%N;
    cout<<"rzad= "<<rz<<" kolumna= "<<nr<<endl;
    cout<<matryca[rz][nr]<<endl;
}

/*
void operator+=(int rzad,T)
{
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
*/
};



int main()
{


Matrix<5,5,int> aaa;

aaa[17];

/*
aaa+=10;
aaa+=20;
aaa+=30;

std::cout<<aaa.begin()<<std::endl;
*/

return 0;
}

