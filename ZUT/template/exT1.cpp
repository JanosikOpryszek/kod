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

vector<int> mojvektor {1,2,3,4,5,6,7,8,9};
list<int> cel;
    
    
int main()
{

cel=powerof<vector<int>,list<int>,2>(mojvektor);

for(auto element : cel)
    cout<<element<<endl;


return 0;
}

