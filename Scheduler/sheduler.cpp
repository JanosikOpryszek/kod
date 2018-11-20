//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <sheduler.cpp>
/// @ingroup     <drv>
/// @brief       <run and control rte and swc komponents>


#include"sheduler.hpp"

namespace rte
{

int Sheduler::init()
    {
    //Init (back from deinit)
    return errcode;
    }    //Sheduler::init()


int Sheduler::deinit()
    {
    //deInit on reset demand
    return errcode;
    } //Sheduler::deinit()

int Sheduler::initialize()
{
    //main loop of sheduler, run in thread by Starter
    return errcode;
    return errcode;
    } //Sheduler::intialize()

} //namespace drv


