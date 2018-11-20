//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <sISheduler.h>
/// @ingroup     <pub>
/// @brief       <run and control rte and swc komponents>

#ifndef ISHEDULER_H
#define ISHEDULER_H

#include "pub/IObserver.h"
#include"pub/eErrorCodes.h"

namespace pub
{


class ISheduler :public IObserver
{
public:
    virtual eErrorCodes mOnStateChange(eStates a_sNewState)=0;
};

} //namespace
#endif // ISHEDULER_H
