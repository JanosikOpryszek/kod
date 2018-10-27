#include "kalkulator.h"

kalkulator::kalkulator()
{


}

int kalkulator::suma(int a, int b)
{
    return a+b;


}

float kalkulator::dzielenie(int a, int b)
{
    float wynik;
    if (b==0) return 0;
    wynik=(float)a/(float)b;
    return wynik;


}
