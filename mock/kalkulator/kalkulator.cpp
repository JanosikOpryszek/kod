#include "kalkulator.h"

namespace kalk {

Kalkulator::Kalkulator(class Dodaj& aa,class Odejmij& bb):aa(aa),bb(bb)
{

}


int Kalkulator::dodaj(int a, int b)
{

    return aa.dodawanie(a,b);
}

int Kalkulator::odejmij(int a, int b)
{

    return bb.odejmowanie(a,b);
}

}
