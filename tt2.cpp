#include <iostream>

using namespace std;


class Foo
{
    public:
    Foo()
{
cout<<"konstruktor"<<endl;
}

~Foo()
{
cout<<"destruktor"<<endl;
}


void work()
{
cout<<"hej"<<endl;
}


};

Foo fooo;

int main()
{
cout<<"czesc"<<endl;


fooo.work();

cout<<"pa"<<endl;
return 0;
}





