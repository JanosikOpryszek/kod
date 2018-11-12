//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <timemaster.cpp>
/// @ingroup     <apl>
/// @brief       <controle time>

#include<iostream>
#include"timemaster.hpp"

namespace apl
{


//========================================
/// @brief     <init>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Timemaster::init()
{
this->metoda(); 

return E_OK;
} //Timemaster::init()

//========================================
/// @brief     <deinit>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Timemaster::deinit()
{
          //deInit 

return E_OK;
} //Timemaster::deinit()

//========================================
/// @brief     <any metchod>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Timemaster::metoda()
{
    std::cout<<"Timemasters objects method started!"<<std::endl;

return E_OK;
} //Timemaster::metoda()

//========================================
/// @brief     <InterfaceDependency adres>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================

int Timemaster::dodaj(Interface *o)
{ 
pIntAdr=o;
return E_OK;
} //Timemaster::dodaj()



} //namespace apl


