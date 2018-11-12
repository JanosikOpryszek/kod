//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <router.cpp>
/// @ingroup     <service>
/// @brief       <manage msg>

#include"../global.cpp"
#include<thread>
#include<iostream>
#include"router.hpp"

namespace service
{

//========================================
/// @brief     <init>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Router::init()
{
this->metoda(); 

return E_OK;
} //Router::init()

//========================================
/// @brief     <deinit>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Router::deinit()
{


return E_OK;
} //Router::deinit()

//========================================
/// @brief     <any metchod>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Router::metoda()
{
while(kond1)
{
    std::cout<<"                         Reouter"<<std::endl; 
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
}
return E_OK;
} //Router::metoda()

//========================================
/// @brief     <InterfaceDependency adres>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================

int Router::dodaj(Interface *o)
{ 
pIntAdr=o;
return E_OK;
} //Router::dodaj()

int Router::dodajup(Interface *o)
{ 
pIntAdrup=o;
return E_OK;
} //Router::dodaj()


} //namespace service

