#include<iostream>
#include<vector>
#include<list>
#include<algorithm>


using namespace std;


void licz( )
{
int licz;
vector<float> mojva;

cout<<"podaj liczbe"<<endl;
    cin>>licz;
float licz2;
cout<<"podawaj kolejne liczby float"<<endl;
for(int i=0;i<licz;i++)
{
cin>>licz2;
    mojva.push_back(licz2); 
}

if (std::is_sorted( mojva.begin(),mojva.end() ) )
{
  cout<<  std::accumulate  (mojva.begin(),end(mojva),1.0f,std::multiplies<float>() ) << endl;


}

}


int main ()
{

 licz();
return 0;
}




