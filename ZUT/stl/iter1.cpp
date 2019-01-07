#include<iostream>
#include<vector>


using namespace std;

vector<int> mojv {1,2,3,4,5,6,7,8};



int main ()
{

vector<int>::iterator it;
it=mojv.begin();

//for (auto element : it)
//    cout<<element<<endl;
int aa;


for (unsigned int i=0;i<=mojv.size();i++)
{
    if(*(it++)==6)
       aa= std::distance(mojv.begin(),it);
}
cout<<aa<<endl;
        




return 0;
}




