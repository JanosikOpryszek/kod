#include <iostream>

using namespace std;

template <typename T>
class C
{
    public:
    C(){
        pointer = nullptr;
    }
    C(T* ptr){
        pointer = ptr;
    }
    
    ~C(){
        delete pointer;
    }
    
    T* get(){
        return pointer;
    }
    
    C(C&& other){
    //C(C& other){
        cout << "X" << endl;
        T* tmp = pointer;
        pointer = other.pointer;
        other.pointer = tmp;
        //other.pointer = nullptr;
    }
    
    
    
    private:
    
    C(const C& other) {};
    C& operator=(const C& other){}
    
    T* pointer;
};

void foo(C<int> blablabla){
    cout << blablabla.get() << endl;
}

int main()
{
    
    {
        C<int> c(new int(10));
        C<int> inny(new int(101));
        
        c.swap(inny);
        
        cout << c.get() << endl;
        cout << *(c.get()) << endl;
        //throw 0;
        //C<int> cc = c;
        foo(c);
        cout << c.get() << endl;
        if (c == inny){
            
        }
    }

    return 0;
}
