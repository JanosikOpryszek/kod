#include<iostream>
#include<vector>
using namespace std;

//zadanie matryca advanced 14

template <int N,int M,typename T>
struct Matrix
{
Matrix(){}    
std::vector<vector<T> > matryca {N,vector<T>(M)};


void operator[] (int n)
{
    int rz=n/M;
    int nr=n%N;
    cout<<"rzad= "<<rz<<" kolumna= "<<nr<<endl;
    cout<<matryca[rz-1][nr-1]<<endl;
}

/*
void operator+=(int rzad,T)
{
}
*/

};



int main()
{


Matrix<3,3,int> aaa; //{{1,2,3},{4,5,6},{7,8,9}};

aaa.matryca[0].push_back(10);
aaa.matryca[0].push_back(11);
aaa.matryca[0].push_back(12);

aaa.matryca[1].push_back(13);
aaa.matryca[1].push_back(14);
aaa.matryca[1].push_back(15);

aaa[5];


return 0;
}

