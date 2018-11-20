//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <sheduler.hpp>
/// @ingroup     <drv>
/// @brief       <run and control rte and swc komponents>


#ifndef SHEDULER_HPP
#define SHEDULER_HPP

#include"../pub/interface.hpp"

namespace rte
{

class Sheduler:public pub::Interface
{
public:
//========================================
/// @brief     <init after deinit, its not initialization!>
/// @param     [IN]  <void>
/// @param     [OUT] <enum-int>
/// @return    <errorcode>
//========================================
int init();

//========================================
/// @brief     <deinit on reset>
/// @param     [IN]  <void>
/// @param     [OUT] <enum-int>
/// @return    <errorcode>
//========================================
int deinit();

//========================================
/// @brief     <run in pthread from Starter, it main working loop>
/// @param     [IN]  <void>
/// @param     [OUT] <enum-int>
/// @return    <errorcode>
//========================================
int initialize();


};    //class prototypes

}     //namespace drv

#endif //SHEDULER_HPP



