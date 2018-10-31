#include<iostream>
#include<vector>
using namespace std;

//zadanie matryca advanced 14


template <int N,int M,typename T>
struct Matrix
{
std::vector<vector<T> > matryca {N,vector<T>(M)};         //macierz Vektorow o wielkosci NxM wypelniona zerami
std::vector<typename vector<T>::iterator> iteratory;      //vektor przechowujacy iteratory typu vector<T>
typename vector<vector<T> >::iterator it=matryca.begin(); //iterator 1 wymiaru macierzy, vektor na vektor


Matrix(){                                                 //konstruktor wypwlniajacy vektor iteratorw 2 wymiaru
 for(int i=0;i<N;i++)
     iteratory.push_back((*(it+i)).begin());
}


//Matrix (const Matrix<N1,M1,T1>& ){                        //konstruktor kopiujacy

//}


T operator[] (int n){                                   //przeciazony operator [],podajesz zbiorowy index zwraca wartosc
int rz=(int)(n/M);
int nr=n-(rz*M);
return *(iteratory[rz]+nr);
}


friend ostream& operator<< (ostream& out, const Matrix& obj) {                                   //przeciazony operator <<
out<<"matryca:"<<endl;

for(int i=0; i<N;i++)
{
    for( int j=0;j<M;j++)
    {
      out<<obj.matryca[i][j]; 
      out<<",";
    }
out<<endl;
}
return out;
}



};


int main()
{
Matrix<3,4,int> aaa;                                      //stworz macierz vektorw o wielkosci 3x3

aaa.matryca[0][0]=10;
aaa.matryca[0][1]=11;
aaa.matryca[0][2]=12;
aaa.matryca[0][3]=77;

aaa.matryca[1][0]=13;
aaa.matryca[1][1]=14;
aaa.matryca[1][2]=15;
aaa.matryca[1][3]=88;


aaa.matryca[2][0]=16;
aaa.matryca[2][1]=17;
aaa.matryca[2][2]=18;
aaa.matryca[2][3]=99;



cout<<"cout << obiekt"<<endl;
cout<<aaa<<endl;

cout<<"cout << aaa[4]"<<endl;
cout<<(aaa[4])<<endl;;

return 0;
}

