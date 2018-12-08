#include<iostream>
#include<memory>

using namespace std;

class Animal {
    public:
            Animal() {
                        cout << "Hello! " << endl;
                                //eat();
                                    }
                virtual void eat() = 0 ;
               /* {
                            cout << "Eating..." << endl;
                                }
                    virtual ~Animal() {
                    cout<<"destructor animala"<<endl;
                    } */
};

class Cat: public Animal {
    public:
            Cat() {
                eat();
                        cout << "Hi! " << endl;
                       // eat();
                            }
                virtual void eat() const noexcept override {
                            cout << "I'm a cat and eating a rat." << endl;
                                }
                    virtual ~Cat() {
                    cout<<"destructor Cat"<<endl;
                    }
};

int main ()
{

unique_ptr<Animal> a {make_unique<Cat>()};



return 0;
}
