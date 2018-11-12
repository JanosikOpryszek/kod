#include<iostream>

using namespace std;

int *a1;
int *b1;

int aa=5;

void tt(int *&a,int *&b)
{
b=a;

}




int main()
{
a1=&aa;
    tt(a1,b1);
cout<<*b1<<endl;
aa++;
cout<<*b1<<endl;


return 0;
}
