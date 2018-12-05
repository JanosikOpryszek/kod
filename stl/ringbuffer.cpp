#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


template<typename T,int N>
class Ringbuffer
{

typename std::vector<T>::iterator it;
int licz=0;

public:

std::vector<T> myvec;

    Ringbuffer()
    {
    myvec.assign(N,0); 
    it=myvec.begin();
    }


void push(T arg1 )
{
if(licz==N)
    {
        std::rotate(myvec.begin(), myvec.begin() + 1, myvec.end());
        licz-=1;
    }
*(it+licz)=arg1;
licz+=1;
}


T pop()
{
if (licz==0)
    return 0;
T ret=*(it);
std::rotate(myvec.begin(), myvec.begin() + 1, myvec.end());
licz-=1;
*(it+N-1)=0;
return ret;
}

void show()
{
for (auto element : myvec)
    cout<<element<<",";
cout<<endl;
}

};



int main ()
{

Ringbuffer<int,10> ring;

ring.push(10);
ring.push(11);
ring.push(12);
ring.push(13);
ring.push(14);
ring.push(15);

for (auto element : ring.myvec)
    cout<<element<<",";
cout<<endl;

ring.show();
ring.push(16);
ring.push(17);
ring.push(18);

ring.show();
ring.push(19);

ring.show();
ring.push(20);

ring.show();
ring.push(21);
ring.show();

cout<<ring.pop()<<endl;
ring.show();

cout<<ring.pop()<<endl;
ring.show();


ring.push(96);
ring.push(97);
ring.push(98);

ring.show();

cout<<ring.pop()<<endl;

ring.show();
cout<<ring.pop()<<endl;

ring.show();
cout<<ring.pop()<<endl;
cout<<ring.pop()<<endl;

ring.show();
cout<<ring.pop()<<endl;
cout<<ring.pop()<<endl;
cout<<ring.pop()<<endl;
cout<<ring.pop()<<endl;
cout<<ring.pop()<<endl;
cout<<ring.pop()<<endl;
cout<<ring.pop()<<endl;

ring.show();


ring.push(80);
ring.push(81);
ring.push(82);
ring.push(83);
ring.push(84);
ring.push(85);

ring.show();


ring.push(86);
ring.push(87);
ring.push(88);
ring.push(89);
ring.push(90);
ring.push(91);

ring.show();

cout<<ring.pop()<<endl;
cout<<ring.pop()<<endl;

ring.show();
return 0;
}





