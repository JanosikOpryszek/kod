#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


using namespace std;

vector<string> mojva={"alaaaaaaaa","Alaaa","ALaaaaa","ala","ALAaa"};

void sortuj(std::vector<string> &v )
{
std::sort(v.begin(),end(v), [](string ss,string ss2) {    return ss.length()<ss2.length();         }  ); 
}

int main ()
{
sortuj(mojva);

for (auto element : mojva)
    cout<<element<<endl;;

return 0;
}




