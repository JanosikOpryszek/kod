#include<iostream>
#include<vector>
using namespace std;

//zadanie matryca advanced 14


template <int N,int M,typename T>
struct Matrix
{
std::vector<vector<T> > matryca {N,vector<T>(M)};
std::vector<typename vector<T>::iterator> iteratory;
typename vector<vector<T> >::iterator it=matryca.begin();

/*
typename vector<T>::iterator it0=(*it).begin();
typename vector<T>::iterator it1=(*(it+1)).begin();
typename vector<T>::iterator it2=(*(it+2)).begin();
*/

Matrix(){    
 for(int i=0;i<N;i++)
     iteratory.push_back((*(it+i)).begin());
}

void operator[] (int n)
{

    int rz=(int)(n/M);
    int nr=n-(rz*M);
    cout<<"rzad= "<<rz<<" nr w rzedzie= "<<nr<<endl;


    switch(rz)
    {
    case 0:
    {

    cout<<*(iteratory[0]+nr)<<endl;
    break;
    }

    case 1:
    {

    cout<<*(iteratory[1]+nr)<<endl;
    break;
    }

    case 2:
    {

    cout<<*(iteratory[2]+nr)<<endl;
    break;
    }

    }

}

};



int main()
{


Matrix<3,3,int> aaa; 
/*
aaa.matryca[0][0]=10;
aaa.matryca[0][1]=11;
aaa.matryca[0][2]=12;

aaa.matryca[1][0]=13;
aaa.matryca[1][1]=14;
aaa.matryca[1][2]=15;

aaa.matryca[2][0]=16;
aaa.matryca[2][1]=17;
aaa.matryca[2][2]=18;
*/


cout<<"Ilosc rzedow: "<<aaa.matryca.size()<<endl;
cout<<"Ilosc elementow w rzedzie: "<<aaa.matryca[0].size()<<endl;

for(int i=0; i<3;i++)
{
for( auto ele : aaa.matryca[i] )
    {
      cout<<ele<<" ";
    }

cout<<endl;

}


cout<<"wartosc wpisana  [2]  "<<endl;
aaa[2];

cout<<"wartosc wpisana  [4]  "<<endl;
aaa[4];


cout<<"wartosc wpisana  [6]  "<<endl;
aaa[6];

return 0;
}

