//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <timemaster.cpp>
/// @ingroup     <apl>
/// @brief       <controle time>

#include"../global.cpp"
#include<thread>
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
    while(kond1)
    {
    std::cout<<"Timemaster"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }

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


