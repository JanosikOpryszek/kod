#include<iostream>
#include<vector>
#include<list>
#include<cmath>
using namespace std;



template<typename T,typename T2, int N > 
T2 powerof(const T& aa)
{
T2 retContainer;


for(auto& element : aa)
    retContainer.push_back(pow(element,N));

return retContainer;
}

/*
template<typename T> 
vector<T> powerof (const vector<T> &aa,int T2)
{
vector<T> temp=aa;

for(auto& element : temp)
    element=pow(element,T2);

return temp;
}
*/

/*
vector<int> powerof(const vector<int> &T, int T2)
{
vector<int> toRett = T;

for(int& element : toRett)
    element=std::pow(element,T2);

return toRett;

}
*/

vector<int> mojvektor {1,2,3,4,5,6,7,8,9};
list<int> cel;
    
    
    
int main()
{
//cel=powerof(mojvektor,2);
//cel=powerof<int>(mojvektor,2);

cel=powerof<vector<int>,list<int>,2>(mojvektor);

for(auto element : cel)
    cout<<element<<endl;



return 0;
}

