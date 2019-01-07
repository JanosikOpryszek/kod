#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> mojva={1,2,3,4,4,3,2,1};

void transformuj(std::vector<int> &v )
{
    std::vector<string> taemv;

std::transform(v.begin(),end(v),std::back_inserter(taemv), [](int i) {return std::to_string(i);    }  ); 

for (auto element : taemv)
    cout<<element<<endl;;

}


int main ()
{


transformuj(mojva);

return 0;
}




