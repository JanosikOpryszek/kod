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
if(N==0 && M==0)
    cout<<"N=0 i M=0, nie moge stworzyc"<<endl;
else
 for(int i=0;i<N;i++)
     iteratory.push_back((*(it+i)).begin());
}


template <int N1,int M1,typename T1>
Matrix (const Matrix<N1,M1,T1>& another){                        //konstruktor kopiujacy

if( std::is_convertible<T,T1>::value )
{
    if(N1<N && M1<M )
    {
        for(int i=0; i<N1;i++)
        {
            for( int j=0;j<M1;j++)
            {
            matryca[i][j]=another.matryca[i][j]; 
            }
        }
    }
    else
        cout<<"za duza tablica do skopiowania"<<endl;
}
else
    cout<<"niekonwertowalny TYP danych"<<endl;
}


template <int N1,int M1,typename T1>
void operator +(Matrix<N1,M1,T1> another)
{

if( std::is_convertible<T,T1>::value )
{
    if(N1<N && M1<M )
    {
        for(int i=0; i<N1;i++)
        {
            for( int j=0;j<M1;j++)
            {
            matryca[i][j]+=another.matryca[i][j]; 
            }
        }
    }
    else
        cout<<"za duza tablica do dodania"<<endl;
}
else
    cout<<"niekonwertowalny TYP danych"<<endl;
}




T operator[] (int n){                          //przeciazony operator [],podajesz zbiorowy index zwraca wartosc
int rz=(int)(n/M);
int nr=n-(rz*M);
return *(iteratory[rz]+nr);
}


friend ostream& operator<< (ostream& out, const Matrix& obj) {                         //przeciazony operator <<
out<<"start---------"<<endl;
out<<"Twoja matryca: "<<endl;

for(int i=0; i<N;i++)
{
    for( int j=0;j<M;j++)
    {
      out<<obj.matryca[i][j]; 
      out<<",";
    }
out<<endl;
}
out<<"end-----------"<<endl;
return out;
}

};




int main()
{
cout<<endl<<"Implementacja Matrix<N, M, T>  gdzie N i M wielkosc, T - typ"<<endl<<endl;
cout<<"Stworzenie Matrix<3,4,int> aaa i wypenie danymi."<<endl<<endl;

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


cout<<"Polecenie: 'cout << aaa' przeciazony <<  wynik:"<<endl;    // operator <<
cout<<aaa<<endl;

cout<<"Polecenie: 'cout << aaa[4]' przeciazony []  wynik:"<<endl;        //operator []
cout<<(aaa[4])<<endl;;
cout<<"end-----------"<<endl<<endl;


cout<<"Stworzenie Matrix<4,5,int> bb(aaa) za pomoca konstruktora kopiujacego."<<endl<<endl;;
Matrix<4,5,double> bb(aaa);         //konstruktor kopiujacy (tylko do wiekszej)

cout<<"Stworzona konstruktorem kopiujacym bb wyglada tak:"<<endl;   
cout<<bb<<endl<<endl;                     //wyswietl skopiowana 

cout<<"Dodaj bb+aaa, przeciazony + , wynik zapisz w bb."<<endl<<endl;

bb+aaa;

cout<<"Po dodaniu Twoje bb wyglada tak:"<<endl;   
cout<<bb<<endl<<endl;                     //wyswietl skopiowana 


return 0;
}

