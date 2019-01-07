#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> mojva={1,2,3,4,3,2,10,3,55,3,128};

void remove(std::vector<int> &v,int ii )
{

auto it=std::remove(v.begin(),end(v),ii ); 
v.erase(it, v.end());

}


int main ()
{
remove(mojva,3);
for(auto element : mojva)
    cout<<element<<endl;
return 0;
}




