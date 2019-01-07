#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> mojv{1,2,3,4,5};
auto it=mojv.begin();


void print( const std::vector<int>& v) {
    std::cout<<"[";
    std::for_each(v.begin(),v.end()-1, [](int vv) {std::cout<<vv; std::cout<<",";    });
    std::cout<<(*v.end()-1);
    std::cout<<"]";
}


int main ()
{

    print(mojv);


return 0;


}




