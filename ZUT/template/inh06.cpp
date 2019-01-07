#include<iostream>

using namespace std;

struct Base {
    int a;
    Base(int _a) :
            a(_a) {
    }
};

struct Derived: Base {
    int b;
    Derived(int _a, int _b) :
            Base(_a), b(_b) {
    }
};


int main ()
{

    Derived d1 { 1, 1 };
    Derived d2 { 2, 2 };
    Base& b_ref = d2;
    b_ref = d1;
    cout << d2.a << d2.b << endl;


return 0;
}
