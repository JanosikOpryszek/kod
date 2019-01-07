#include <iostream>

using namespace std;

// smart wskaznik bez licznika referencji - wskaznik wylaczny jak unique_ptr
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

    C(C&& other){                //konstruktor przenoszacy
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

    bool operator==(const C& other){     // operator ==
     if(pointer && other.pointer )
     {
         if(*pointer  == *other.pointer)
            return true;
         else
            return false;
     }
     else
        return 0;
    }


    bool operator != (const C& other){      // operator !=
    if(pointer && other.pointer )
    {
         if(*pointer  != *other.pointer)
            return true;
         else
            return false;
    }
    else
        return 0;
    }


    bool operator < (const C& other){      // operator <
    if(pointer && other.pointer )
    {
        if(*pointer  < *other.pointer)
            return true;
         else
            return false;
     }
     else
        return 0;
    }


    bool operator <= (const C& other){      // operator <=
    if(pointer && other.pointer )
    {
        if(*pointer  <= *other.pointer)
            return true;
         else
            return false;
     }
     else
        return 0;
    }


    bool operator > (const C& other){      // operator >
    if(pointer && other.pointer )
    {
        if(*pointer  > *other.pointer)
            return true;
         else
            return false;
     }
     else
        return 0;
    }


    bool operator >= (const C& other){      // operator >=
    if(pointer && other.pointer )
    {
        if(*pointer  >= *other.pointer)
            return true;
         else
            return false;
     }
     else
        return 0;
    }


    private:                             //prywatny, blokowanie uzycia konst. kopiujacego i operatora przypisania
    C(const C& other) {};               // kopiujacy
    C& operator=(const C& other){}      // operator  przypisania
    T* pointer;

};

//**********************************************************************************

// smart wskaznik z licznikiem referencji - wskaznik wspoldzielony jak shared_ptr
template <typename T>
class S
{
    public:
    S(){                       // konstruktor bezparametrowy
        pointer = nullptr;
    }
    S(T* ptr){                 // konstruktor z parametrem
        pointer = ptr;
        licznik++;
    }

    S(const S& other) {        // konstruktor kopiujacy
    pointer=other.pointer;
    licznik++;
    }

    S(S&& other){              //konstruktor przenoszacy
        T* tmp = pointer;
        pointer = other.pointer;
        other.pointer = nullptr;
    }


    ~S(){                     //destruktor
        delete pointer;
        licznik--;
    }


    T* get(){                 //funkcja get
        return pointer;
    }

    void swap(S& other){      //funkcja swap
        T* tmp = pointer;
        pointer = other.pointer;
        other.pointer = tmp;
    }

    int ile(){               //funkcja ile
        return licznik;
    }


    void operator=(const S& other){      // operator  przypisania z innego wskaznika
    if(other.pointer)          //czy argument ma przypisany wskaznik
    {
        if(pointer)
            *pointer = *other.pointer;
        else
        {
            pointer=new T;
            *pointer=*other.pointer;
            licznik++;
        }
    }
    else
        cout << " probujesz przypisac wskaznik o wartosci nullptr\n";
    }


    void operator=(int wartosc){      // operator  przypisania wartosci
        if(pointer)
            *pointer = wartosc;
        else
        {
            pointer=new T;
            *pointer=wartosc;
            licznik++;
        }
    }


    T operator * (){      // operator *
     if(pointer)
        return *(pointer);
     else
        return 0;
    }

    bool operator==(const S& other){     // operator ==
     if(pointer && other.pointer )
     {
         if(*pointer  == *other.pointer)
            return true;
         else
            return false;
     }
     else
        return 0;
    }


    bool operator != (const S& other){      // operator !=
    if(pointer && other.pointer )
    {
         if(*pointer  != *other.pointer)
            return true;
         else
            return false;
    }
    else
        return 0;
    }


    bool operator < (const S& other){      // operator <
    if(pointer && other.pointer )
    {
        if(*pointer  < *other.pointer)
            return true;
         else
            return false;
     }
     else
        return 0;
    }


    bool operator <= (const S& other){      // operator <=
    if(pointer && other.pointer )
    {
        if(*pointer  <= *other.pointer)
            return true;
         else
            return false;
     }
     else
        return 0;
    }


    bool operator > (const S& other){      // operator >
    if(pointer && other.pointer )
    {
        if(*pointer  > *other.pointer)
            return true;
         else
            return false;
     }
     else
        return 0;
    }


    bool operator >= (const S& other){      // operator >=
    if(pointer && other.pointer )
    {
        if(*pointer  >= *other.pointer)
            return true;
         else
            return false;
     }
     else
        return 0;
    }



    private:
    T* pointer;
    static int licznik;

};

template <typename T>
int S<T>::licznik=0;


void foo(C<int> argu){
    cout << "z wnetrza funkcji to co dal przeslany argument: "<<*argu << endl;
}

void foos(S<int> argu){
    cout << "z wnetrza funkcji, kopia argumentu  ma wartosc: "<<*argu << endl;
    cout << " z wnetrza funkcji ile= "<< argu.ile()<< endl;;

}

int main()
{
        cout << " Klasa C - smart wskaznik bez licznika referencji - wskaznik wylaczny jak unique_ptr \n";
        cout << "tworze c z wartoscia 10\n";
        C<int> c(new int(10));
        cout << "tworze inny z wartoscia 100\n";
        C<int> inny(new int(100));
        cout << "\n";
        cout <<"c.get() wyswietla adres: ";
        cout << c.get() << "\n";
        cout <<"*(c.get()) wyswietla wartosc: ";
        cout << *(c.get()) << "\n";
        cout <<"przeciazony *c wyswietla wartosc: ";
        cout << *c << "\n";
        cout << "\n";

        cout << "zamieniam inny z c za pomoca  inny.swap(c) \n";
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

        cout << "tworze nowy cc konstruktorem przenoszacym z inny cc(move(inny)), inny powinien sie wyzerowac, cc byc jak inny\n";
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

        //foo(c);  nie zadziala bo kopiujacy w obszarze prywatnym
        cout << "nasz pointer c jako argument funkcji przeslany konstruktorem przenoszacym foo(move(c))\n";
        foo(move(c));
        cout << "*c po przeniesieniu do argumentu funkcji wyswietla : ";
        cout << *c << "\n";

        cout << "\n";
        cout << "operator == \n";
        cout << "tworze a z wartoscia 5\n";
        C<int> a(new int(5));
        cout << "tworze b z wartoscia 5\n";
        C<int> b(new int(5));
        cout << "a == b  : ";
        if (a == b)
            cout << "rowne\n";
        else
            cout << "rozne\n";
        cout << "\n";

        cout << "operator != \n";
        cout << "a != b  : ";
        if (a != b)
            cout << "rozne\n";
        else
            cout << "nie rozne\n";
        cout << "\n";

        cout << "operator < \n";
        cout << "a < cc  : ";
        if (a != cc)
            cout << "prawda\n";
        else
            cout << "falsz\n";
        cout << "\n";

        cout << "*********************************************************\n";
        cout << "Klasa S - smart wskaznik z licznikiem referencji - wskaznik wspoldzielony jak shared_ptr \n";
        cout << "tworze s z wartoscia 7\n";
        S<int> s(new int(7));
        cout << "ile obiektow: " << s.ile() << endl;
        cout << "\n";
        cout << "tworze wskaznik ale bez wartosci\n";
        S<int> s2;
        cout << "ile obiektow: " << s.ile() << endl;
        cout << " przypisanie do powyzszego wskaznika wartosci\n";
        s2=11;
        cout << "ile obiektow: " << s.ile() << endl;
        cout << "\n";
        cout << " wywolanie funkcji foos czyli stworzenie kopi przez przeslanie argumentu\n";
        foos(s2);
        cout << "po wyjsciu z funkcji: ";
        cout << "ile obiektow: " << s.ile() << endl;






    return 0;
}
