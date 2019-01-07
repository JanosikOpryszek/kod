#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<float> mojva={-1,-2,-3,4,3,2};


float minimum(std::vector<float> v)
{
auto it=std::min_element(begin(v),end(v),[](float st,float ch) { return abs(st)<abs(ch);     }  ); 
 
return *it;
}


int main ()
{

    cout<<minimum(mojva)<<endl;


return 0;
}




