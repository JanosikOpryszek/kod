#include <iostream>

using namespace std;

// smart wskaznik bez licznika referencji - wskaünik wy≥πczny jak unique_ptr
template <typename T>
class C
{
    public:
    C(){                       // konstruktor bezparametrowy
        pointer = nullptr;
    }
    C(T* ptr){                 // konstruktor z parametrem
        pointer = ptr;
    }

    ~C(){                     //destruktor
        delete pointer;
    }

    T* get(){                 //funkcja get
        return pointer;
    }

    void swap(C& other){      //funkcja swap
        T* tmp = pointer;
        pointer = other.pointer;
        other.pointer = tmp;
    }

    C(C&& other){                //konstruktor przenoszπcy
        T* tmp = pointer;
        pointer = other.pointer;
        other.pointer = nullptr;
    }


    T operator * (){      // operator *
     if(pointer)
        return *(pointer);
     else
        return 0;

    }
    C& operator==(const C& other){}     // operator ==
    C& operator!=(const C& other){}      // operator !=
    C& operator<(const C& other){}      // operator <
    C& operator<=(const C& other){}      // operator <=
    C& operator>(const C& other){}      // operator >
    C& operator>=(const C& other){}      // operator >=


    private:

    C(const C& other) {};               // kopiujπcy
    C& operator=(const C& other){}      // operator  przypisania


    T* pointer;
};

void foo(C<int> blablabla){
    cout << blablabla.get() << endl;
}

int main()
{


        cout << "tworze c z wartoscia 10\n";
        C<int> c(new int(10));
        cout << "tworze inny z wartoscia 101\n";
        C<int> inny(new int(101));
        cout << "\n";
        cout <<"c.get() wyswietla: ";
        cout << c.get() << "\n";
        cout << "\n";
        cout <<"*(c.get()) wyswietla: ";
        cout << *(c.get()) << "\n";
        cout << "\n";
        cout <<"przeciazony *c wyswietla: ";
        cout << *c << "\n";
        cout << "\n";

        cout << "tworze nowy cc konstruktorem przenoszacym z inny, ktory powinien sie wyzerowac \n";
        C<int> cc(move(inny));

        cout << "inny.get() wyswietla : ";
        cout << inny.get() << "\n";
        cout << "*inny wyswietla : ";
        cout << *inny << "\n";

        cout <<"cc.get() wyswietla: ";
        cout << cc.get() << "\n";
        cout <<"*cc wyswietla: ";
        cout << *cc << "\n";
        cout << "\n";
        cout << " zamieniam inny z c za pomoca  inny.swap(c) \n";
        inny.swap(c);

        cout << "inny.get() wyswietla : ";
        cout << inny.get() << "\n";
        cout <<"*inny wyswietla: ";
        cout << *inny << "\n";
        cout <<"c.get() wyswietla: ";
        cout << c.get() << "\n";
        cout <<"*c wyswietla: ";
        cout << *c << "\n";
        cout << "\n";

        //foo(c);  nie zadziala bo kopiujacy w obszarze prywatnym

        //if (c == inny){

       // }


    return 0;
}
