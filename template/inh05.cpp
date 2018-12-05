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

Base* pb = &b;
Base* pd = &d;

pb->f();
pd->f();

pb->Base::f();
pd->Base::f();



return 0;
}
