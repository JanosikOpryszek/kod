#ifndef HUSWC_HPP
#define HUSWC_HPP

#include<iostream>
#include <stdlib.h>
#include"ISwC.h"


namespace swc
{
    class HUSwC:public pub::ISwC
    {

    public:
        HUSwC();
        ~HUSwC();
        void* work();

    };
}
#endif // HUSWC_HPP
