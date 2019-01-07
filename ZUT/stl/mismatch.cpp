#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> mojva={1,2,3,4,4,3,2,1};

bool pali(std::vector<int> &v )
{
const auto p= std::mismatch(v.begin(),end(v),v.rbegin() ); 
return p.first == v.end() &&  p.second == v.rbegin();

}


int main ()
{

    cout<<pali(mojva)<<endl;;
return 0;
}




