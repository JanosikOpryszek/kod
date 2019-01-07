#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> mojv;


struct Pred {
        int operator()() 
        {
        static int a;   
        return a+=1;
        }
};




int main ()
{

int licz;


for(int i=0;i<10;i++)
{
std::generate(licz , Pred() -> int);
mojv.push_back(licz);
}


for (auto element : mojv)
    cout<<element<<endl;


return 0;
}




