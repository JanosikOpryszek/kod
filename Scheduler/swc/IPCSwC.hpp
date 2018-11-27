#ifndef IPCSWC_HPP
#define IPCSWC_HPP
#include<iostream>
#include <stdint.h>
#include "ISwC.h"

namespace swc
{
    class IPCSwC : public pub::ISwC
    {

    public:
        IPCSwC();
        ~IPCSwC();
        void* work();
    };

}
#endif // IPCSWC_HPP
