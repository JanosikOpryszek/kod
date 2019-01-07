#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

using namespace std;

vector<string> mojva={"ala1","Ala","ALa","ala2","ALA"};

void remove(std::vector<string> &v )
{
auto it=std::remove_if(v.begin(),end(v),[](std::string ss){
        for( auto element : ss)
        {
            if (isdigit(element))
               return true;
        } 
        return false;  
        }
        ); 

v.erase(it, v.end());

}

int main ()
{
remove(mojva);
for(auto element : mojva)
    cout<<element<<endl;
return 0;
}




