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
/*
#include"pub/IObserver.h"
#include"pub/eErrorCodes.h"
#include"pub/eStates.h"
#include"pub/eEcuNum.h"
#include"srv/Logger/ILogger.h"
#include"srv/Configurator/IConfigurator.h"
#include"rte/CommunicationMgr/ICommunicationMgr.h"
*/

#include"IObserver.h"
#include"eErrorCodes.h"
#include"eStates.h"
#include"eEcuNum.h"

namespace rte
{
    class ISheduler :public pub::IObserver
    {
    public:
    virtual eErrorCodes mOnStateChange(eStates a_sNewState)=0;
    };

} //namespace rte
#endif // ISHEDULER_H
