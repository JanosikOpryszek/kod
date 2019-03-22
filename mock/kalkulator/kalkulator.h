#ifndef KALKULATOR_H
#define KALKULATOR_H
#include "dodaj.h"
#include "odejmij.h"

namespace kalk {



class Kalkulator
{

public:
    Kalkulator(Dodaj& aa,Odejmij& bb);

    int dodaj(int a,int b);


    int odejmij(int a,int b);

private:
    class Dodaj& aa;
    class Odejmij& bb;

};

}

#endif // KALKULATOR_H
