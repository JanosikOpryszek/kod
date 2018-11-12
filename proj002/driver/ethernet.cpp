//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <ethernet.cpp>
/// @ingroup     <drivers>
/// @brief       <network driver>

#include"../global.cpp"
#include<thread>
#include<iostream>
#include"ethernet.hpp"

namespace driver
{


//========================================
/// @brief     <init>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Ethernet::init()
{
this->metoda();

return E_OK;
} //Ethernet::init()

//========================================
/// @brief     <deinit>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Ethernet::deinit()
{
          //deinit

return E_OK;
} //Ethernet::deinit()

//========================================
/// @brief     <any metchod>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Ethernet::metoda()
{
while(kond1)
{
    std::cout<<"           Ethernet"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
}
return E_OK;
} //Ethernet::metoda()

//========================================
/// @brief     <InterfaceDependency adres>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================

int Ethernet::dodaj(Interface *o)
{ 
pIntAdr=o;
return E_OK;
} //Ethernet::dodaj()


} //namespace driver




 
