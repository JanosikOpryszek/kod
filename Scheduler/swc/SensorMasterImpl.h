//=============================================================================
// Project      <<CAA>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <StarterImpl.h>
/// @ingroup     <srv>
/// @brief       <Starter implementation header>

#ifndef SENSORMASTERIMPL_H
#define SENSORMASTERIMPL_H


#include "ISwC.h"
#include<iostream>

namespace swc
{
    class SensorMasterImpl : public pub::ISwC
    {
    public:
        SensorMasterImpl();

    private:
        void* work();
    };
}

#endif // SENSORMASTERIMPL_H
