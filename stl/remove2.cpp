#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

// poprawka, czy tym char czy string w lambda
using namespace std;

vector<string> mojva={"ala1","Ala","ALa","ala2","ALA"};

void remove(std::vector<string> &v )
{

auto it=std::remove_if(v.begin(),end(v),[](char ss){
       
       if (isdigit(ss))
               return true;
        else
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




