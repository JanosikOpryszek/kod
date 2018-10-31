#include<iostream>
#include<vector>
using namespace std;

//zadanie matryca advanced 14


template <int N,int M,typename T>
struct Matrix
{
Matrix(){}    
std::vector<vector<T> > matryca {N,vector<T>(M)};

typename vector<vector<T> >::iterator it=matryca.begin();
typename vector<T>::iterator it2=(*it).begin();



void operator[] (int n)
{
    int rz=n/M;
    int nr=n%N;
    cout<<"rzad= "<<rz<<" kolumna= "<<nr<<endl;

    cout<<*it2<<endl;
}


};



int main()
{


Matrix<3,3,int> aaa; 

aaa.matryca[0][0]=10;
aaa.matryca[0][1]=11;
aaa.matryca[0][2]=12;

aaa.matryca[1][0]=13;
aaa.matryca[1][1]=14;
aaa.matryca[1][2]=15;

aaa.matryca[2][0]=16;
aaa.matryca[2][1]=17;
aaa.matryca[2][2]=18;

//aaa[5];

cout<<aaa.matryca.size()<<endl;
cout<<aaa.matryca[0].size()<<endl;


for( auto ele : aaa.matryca[0] )
      cout<<ele<<endl;





return 0;
}

