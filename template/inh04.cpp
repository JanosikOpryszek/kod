#include<iostream>

using namespace std;

struct Base {
        virtual void f() {
                    cout << "Base" << endl;
                        }
            virtual ~Base() {
                    }
};

struct Derived: Base {
        void f() override {
                    cout << "Derived" << endl;
                        }
            virtual ~Derived() {
                    }
};

int main ()
{


Base b;
Derived d;

b.f();
d.f();

Base bb = d;
bb.f();


return 0;
}
