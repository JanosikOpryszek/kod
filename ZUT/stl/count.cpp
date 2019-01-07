#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> mojva={1,2,3,4,5,6,7,8,9,10,11};


int odd(const std::vector<int> &v)
{

return count_if(begin(v),end(v), [](int ii){ return ii%2 == 0;  } );

}



int main ()
{

cout<<odd(mojva)<<endl;

return 0;
}




