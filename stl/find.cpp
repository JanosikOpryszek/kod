#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> mojva={1,2,3,4,3,2,10,3,55,3,128};


std::vector<int> znajdz(std::vector<int> &v,int ii)
{
unsigned int licz=0;
std::vector<int> tempv;

while(licz<(v.end()-v.begin()))
{
auto it=std::find_if(v.begin()+licz,end(v),[ii](int i ){  return i==ii;  } ); 
licz=it-v.begin();
if(licz<(v.end()-v.begin()))   // check if not las 
    tempv.push_back(licz);
licz+=1;
}

return tempv;
}


int main ()
{

    for(auto element : znajdz(mojva,3))
        cout<<element<<endl;

return 0;
}




