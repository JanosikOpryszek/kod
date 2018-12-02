#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<string> mojva={"ala","Ala","ALa","ala","ALA"};


void replace1(std::vector<string> &v )
{

std::replace_if(v.begin(),end(v), [](string ss) {
        
        for( auto element : ss)
            {
            if ((char)element<122 && (char)element >97)
            return  true;   

            }

        return false;
               
        
        },std::string ("bummer")  ); 

//for (auto element : tempv)
//    cout<<element<<endl;;

}


int main ()
{


replace1(mojva);


for (auto element : mojva)
    cout<<element<<endl;;

return 0;
}




