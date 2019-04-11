#include <iostream>
#include "dodaj.h"
#include "odejmij.h"
#include "kalkulator.h"

using namespace std;




int main()
{
    kalk::Dodaj ddd;
    kalk::Odejmij ooo;
    kalk::Kalkulator kalc(ddd,ooo);

    cout<<"5+6="<<kalc.dodaj(5,6)<<endl;
    cout<<"11-3="<<kalc.odejmij(11,3)<<endl;


    return 0;
}


