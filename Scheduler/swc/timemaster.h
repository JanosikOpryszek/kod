//=============================================================================
// Project      <<CAA>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <timemaster.h>
/// @ingroup     <swc>
/// @brief       <SWC for TimeMaster Ecu implementation header>


#ifndef TIMEMASTER_H
#define TIMEMASTER_H

//#include <cstdint>
#include<iostream>
#include "ISwC.h"

namespace swc
{
class TimeMaster: public pub::ISwC
{



public:
    void*work();

    TimeMaster();


};
}
#endif // TIMEMASTER_H
