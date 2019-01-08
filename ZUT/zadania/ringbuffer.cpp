#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

template<typename T,int N>
class Ringbuffer
{

typename std::vector<T>::iterator it;
int licz=0;

public:

std::vector<T> myvec;

Ringbuffer()
{
    myvec.assign(N,0);
    it=myvec.begin();
}

typename std::vector<T>::iterator begin()
{
    return myvec.begin();
}

typename std::vector<T>::iterator end()
{
    myvec.end();

}

void push(T arg1 )
{
    if(licz==N)
    {
        std::rotate(myvec.begin(), myvec.begin() + 1, myvec.end());
        licz-=1;
    }
    *(it+licz)=arg1;
    licz+=1;
}


T pop()
{
    if (licz==0)
        return 0;
    T ret=*(it);
    std::rotate(myvec.begin(), myvec.begin() + 1, myvec.end());
    licz-=1;
    *(it+N-1)=0;
    return ret;
}

void show()
{
    for (auto element : myvec)
        cout<<element<<",";
    cout<<endl;
}

};



int main ()
{
cout << "tworze Ringbuffer typu int o wielkosci 10\n";
Ringbuffer<int,10> ring;

cout << "pushuje kolejno 10,11,12,13,14,15\n";
ring.push(10);
ring.push(11);
ring.push(12);
ring.push(13);
ring.push(14);
ring.push(15);

cout << "rangefor na vektorze z ringu: ";   //prawdziwy rangefor na koncu
for (auto element : ring.myvec)
    cout<<element<<",";
cout<<endl;

cout << "metoda show :";
ring.show();

cout << " pushuje 16,17,18\n";
ring.push(16);
ring.push(17);
ring.push(18);

cout << "metoda show :";
ring.show();

cout << " pushuje 19\n";
ring.push(19);

cout << "metoda show :";
ring.show();

cout << " pushuje 20\n";
ring.push(20);

cout << "metoda show :";
ring.show();

cout << " pushuje 21\n";
ring.push(21);

cout << "metoda show :";
ring.show();


cout<<"metoda pop\n"<<ring.pop()<<endl;

cout << "metoda show :";
ring.show();

cout<<"metoda pop\n"<<ring.pop()<<endl;

cout << "metoda show :";
ring.show();


cout << " pushuje 96,97,98\n";
ring.push(96);
ring.push(97);
ring.push(98);

cout << "metoda show :";
ring.show();

cout<<"metoda pop\n"<<ring.pop()<<endl;

cout << "metoda show :";
ring.show();
cout<<"metoda pop\n"<<ring.pop()<<endl;

cout << "metoda show :";
ring.show();
cout<<"metoda pop\n"<<ring.pop()<<endl;
cout<<"metoda pop\n"<<ring.pop()<<endl;

cout << "metoda show :";
ring.show();
cout<<"metoda pop\n"<<ring.pop()<<endl;
cout<<"metoda pop\n"<<ring.pop()<<endl;
cout<<"metoda pop\n"<<ring.pop()<<endl;
cout<<"metoda pop\n"<<ring.pop()<<endl;
cout<<"metoda pop\n"<<ring.pop()<<endl;
cout<<"metoda pop\n"<<ring.pop()<<endl;
cout<<"metoda pop\n"<<ring.pop()<<endl;

cout << "metoda show :";
ring.show();

cout << " pushuje 80,81,82,83,94,85\n";
ring.push(80);
ring.push(81);
ring.push(82);
ring.push(83);
ring.push(84);
ring.push(85);

cout << "metoda show :";
ring.show();

cout << " pushuje 86,87,88,89,90,91\n";
ring.push(86);
ring.push(87);
ring.push(88);
ring.push(89);
ring.push(90);
ring.push(91);

cout << "metoda show :";
ring.show();

cout<<"metoda pop\n"<<ring.pop()<<endl;
cout<<"metoda pop\n"<<ring.pop()<<endl;

cout << "metoda show :";
ring.show();

cout << "_____________range_for______________\n";
for (const auto& element: ring)
    cout<<element<<",";
cout<<endl;
cout << "_____________range_for______________\n";

return 0;
}





