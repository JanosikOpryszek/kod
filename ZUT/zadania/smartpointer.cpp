#include <iostream>
#include <vector>

using namespace std;

// smart wskaznik bez licznika referencji - wskaznik wylaczny jak unique_ptr
template <typename T>
class Unique
{
    public:
    Unique(){                       // konstruktor bezparametrowy
        pointer = nullptr;
    }
    Unique(T* ptr){                 // konstruktor z parametrem
        pointer = ptr;
    }

    ~Unique(){                     //destruktor
        delete pointer;
    }

    T* get(){                 //funkcja get
        return pointer;
    }

    void swap(Unique& other){      //funkcja swap
        T* tmp = pointer;
        pointer = other.pointer;
        other.pointer = tmp;
    }

    Unique(Unique&& other){                //konstruktor przenoszacy
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

    bool operator==(const Unique& other){     // operator ==
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


    bool operator != (const Unique& other){      // operator !=
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


    bool operator < (const Unique& other){      // operator <
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


    bool operator <= (const Unique& other){      // operator <=
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


    bool operator > (const Unique& other){      // operator >
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


    bool operator >= (const Unique& other){      // operator >=
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
    Unique(const Unique& other) {};               // kopiujacy
    Unique& operator=(const Unique& other){}      // operator  przypisania
    T* pointer;

};

//**********************************************************************************

// smart wskaznik z licznikiem referencji - wskaznik wspoldzielony jak shared_ptr
template <typename T>
class Shared
{
    public:



    Shared(T* ptr): pointer(ptr),licznik(new int){                 // konstruktor z parametrem
        *licznik=1;
    }

    Shared(const Shared<T>& other) {        // konstruktor kopiujacy
    licznik=other.licznik;
    pointer=other.pointer;
    (*licznik)++;
    }



    Shared(Shared&& other){              //konstruktor przenoszacy
        pointer = other.pointer;
        licznik=other.licznik;
        delete other;            // albo pointer i licznik
    }


    ~Shared(){                     //destruktor
        if(*licznik>1)
            {
                (*licznik)--;
            }
        else if (*licznik==1)
        {
            delete pointer;
            delete licznik;
        }
     }


    T* get(){                 //funkcja get
        return pointer;
    }

    void swap(Shared& other){      //funkcja swap
        T* tmp = pointer;
        pointer = other.pointer;
        other.pointer = tmp;
        int* tmp2 = licznik;
        licznik = other.licznik;
        other.licznik = tmp2;


    }

    int ile(){               //funkcja ile
        return *licznik;
    }


    void operator=(const Shared<T>& other){      // operator  przypisania z innego wskaznika
        cout << "operator przypisania\n";
        if(pointer)
            {
                *pointer = *other.pointer;
                licznik=other.licznik;
                *licznik++;
            }
        else
            {
                pointer=new T;
                *pointer=*other.pointer;
                licznik=other.licznik;
                *licznik++;
            }
        }


    void reset(int wartosc){      // funkcja  przypisania wartosci
            *pointer = wartosc;
    }


    T operator * (){      // operator *
     if(pointer)
        return *(pointer);
     else
        return 0;
    }

    bool operator==(const Shared& other){     // operator ==
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


    bool operator != (const Shared& other){      // operator !=
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


    bool operator < (const Shared& other){      // operator <
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


    bool operator <= (const Shared& other){      // operator <=
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


    bool operator > (const Shared& other){      // operator >
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


    bool operator >= (const Shared& other){      // operator >=
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
    int* licznik;

};



void foo(Unique<int> argu){
    cout << "------------------z wnetrza funkcji to co dal przeslany argument: "<<*argu << endl;
}

Unique<int> foo2(Unique<int> argu){
    cout << "------------------z wnetrza funkcji to co dal przeslany argument: "<<*argu << endl;
    return move(argu);
}

void foos(Shared<int> argu){
    cout << "------------------z wnetrza funkcji, kopia argumentu  ma wartosc: "<<*argu << endl;
    cout << "------------------z wnetrza funkcji ile= "<< argu.ile()<< endl;;

}

int main()
{
        cout << "****************************************************************************************\n";
        cout << "Klasa Unique - smart wskaznik bez licznika referencji - wskaznik wylaczny jak unique_ptr \n";
        cout << "tworze wskaznik 'c' z wartoscia 10\n";
        Unique<int> c(new int(10));
        cout << "tworze wskaznik 'inny' z wartoscia 100\n";
        Unique<int> inny(new int(100));
        cout << "\n";
        cout <<"c.get() wyswietla adres: ";
        cout << c.get() << "\n";
        cout <<"*(c.get()) wyswietla wartosc: ";
        cout << *(c.get()) << "\n";
        cout <<"przeciazony *c wyswietla wartosc: ";
        cout << *c << "\n";
        cout << "\n";

        cout << "zamieniam 'inny' z 'c' za pomoca  inny.swap(c) \n";
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

        cout << "tworze nowy 'cc' konstruktorem przenoszacym z 'inny' cc(move(inny)), 'inny' powinien sie wyzerowac, 'cc' byc jak 'inny'\n";
        Unique<int> cc(move(inny));
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
        cout << "funkcja foo, pointer 'c' jako argument funkcji - przeslany konstruktorem przenoszacym foo(move(c))\n";
        foo(move(c));
        cout << "*c po przeniesieniu do argumentu funkcji wyswietla : ";
        cout << *c << "\n\n";
        cout << "funkcja foo2 ktora przyjmuje argument 'cc' i zwraca do 'odb' za pomoca konstruktora przenoszacego \n";
        Unique<int> odb( foo2(move(cc)) );
        cout <<"*cc wyswietla: ";
        cout << *cc << "\n";
        cout <<"*odb wyswietla: ";
        cout << *odb << "\n";
        cout << "\n";


        cout << "operator == \n";
        cout << "tworze wskaznika 'a' z wartoscia 5\n";
        Unique<int> a(new int(5));
        cout << "tworze wskaznika 'b' z wartoscia 5\n";
        Unique<int> b(new int(5));
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

        cout << "*********************************************************************************************\n";
        cout << "Klasa Shared - smart wskaznik z licznikiem referencji - wskaznik wspoldzielony jak shared_ptr \n";
        cout << "tworze wskaznik 's' z wartoscia 7\n";
        Shared<int> s(new int(7));
        cout << "ile obiektow typu s : " << s.ile() << endl;
        cout << "\n";
        cout << "tworze wskaznik 's2' z wartoscia 10\n";
        Shared<int> s2(new int(10));
        cout << "ile obiektow  typu s : " << s2.ile() << endl;
        cout << "przypisanie do powyzszego wskaznika 's2' wartosci 11 za pomoca s2.reset(11) \n";
        s2.reset(11);
        cout << "*s2=" << *s2 <<"\n";
        cout << "ile obiektow  typu s2: " << s2.ile() << endl;
        cout << "\n";
        cout << "wywolanie funkcji foos(s2) czyli stworzenie kopi przez przeslanie argumentu\n";
        foos(s2);
        cout << "po wyjsciu z funkcji: ";
        cout << "ile obiektow typu s2 : " << s2.ile() << endl;
        cout << "\n";
        cout << "vector typu Shared<int> i dodane typu <int>\n";
        // umieœæ wskaŸniki w kontenerze
        vector<Shared<int>> whoMadeCoffee;
        cout <<"zaczynam pushback\n";
        whoMadeCoffee.push_back(s);
        cout << "byl push s\n";
        whoMadeCoffee.push_back(s);
        cout << "byl push s\n";
        whoMadeCoffee.push_back(s2);
        cout << "byl push s2\n";
        whoMadeCoffee.push_back(s);
        cout << "byl push s\n";
        whoMadeCoffee.push_back(s2);
        cout << "byl push s2\n\n";
        cout << "wyswietlam rangefor:\n";
        // wypisz wszystkie elementy
        for (auto &ptr : whoMadeCoffee) {
             cout << *ptr << " ";
        }
        cout << "\nrangefor koniec\n";
        cout << endl ;
        cout << "ile obiektow s : " << s.ile() << endl;
        cout << "ile obiektow vector[s] : " << whoMadeCoffee[1].ile() << endl;
        cout << "\n";
        cout << "ile obiektow vector[s2] : " << whoMadeCoffee[2].ile() << endl;
        cout << "\n";
        cout << "tworze wskaznik 'ch' typu <char> z wartoscia 8\n";
        Shared<char> ch(new char(7));
        cout << "ile obiektow typu ch: " << ch.ile() << endl;
        cout << "ile obiektow typu s2 : " << s2.ile() << endl;





    return 0;
}
