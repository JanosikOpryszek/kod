#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> mojva={1,2,3,4,4,3,2,1};

vector<int> mojva2={1,2,3,4,5,6,7,8};

void transformuj(std::vector<int> &v,std::vector<int> &v2 )
{
    std::vector<float> tempv;

std::transform(v.begin(),end(v),begin(v2),std::back_inserter(tempv), [](int i,int ii) {return pow(i,ii);    }  ); 

for (auto element : tempv)
    cout<<element<<endl;;

}


int main ()
{


transformuj(mojva,mojva2);

return 0;
}




