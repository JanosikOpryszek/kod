#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> mojva={1,2,3,4,4,3,2,1};

void copiuj(std::vector<int> &v )
{
    std::vector<int> temv;

std::copy_if(v.begin(),end(v),std::back_inserter(temv), [](int i) {return i%2 == 0;    }  ); 

for (auto element : temv)
    cout<<element<<endl;;

}


int main ()
{


copiuj(mojva);

return 0;
}




