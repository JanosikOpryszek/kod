#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>

using namespace std;

void licz( )
{
int licz;
float licz2;
vector<float> mojva;

cout<<"podaj ilosc liczb do przemnozenia:"<<endl;
    cin>>licz;
cout<<"podawaj kolejne liczby float"<<endl;

std::cin.exceptions(std::ios::failbit | std::ios::badbit);

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




