#include<iostream>
#include<vector>
#include<list>
#include<algorithm>


using namespace std;

vector<int> mojva={1,2,3,4,5,6,7,8,9,10,11};
list<int> mojlist={1,2,3,4,5,6,7,8,9,10,11};

bool rowne(std::vector<int> &v,std::list<int> &l )
{

return std::equal(v.begin(),end(v),l.begin() ); 


}


int main ()
{

    cout<<rowne(mojva,mojlist);
return 0;
}




