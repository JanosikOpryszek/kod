//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <communicationmanager.cpp>
/// @ingroup     <rte>
/// @brief       <real time environment>

#include"communicationmanager.hpp"

namespace rte
{

//========================================
/// @brief     <init>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Communicationmanager::init()
{
          //Init

return E_OK;
} //Communicationmanager::init()

//========================================
/// @brief     <deinit>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Communicationmanager::deinit()
{
          //deInit

return E_OK;
} //Communicationmanager::deinit()

//========================================
/// @brief     <get>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Communicationmanager::get()
{
    std::cout<<"method get Communicationmanager"<<std::endl; 

return zm1;
} //Communicationmanager::get()

//========================================
/// @brief     <set>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================

int Communicationmanager::set(int a)
{ 
    std::cout<<"method set Communicationmanager"<<std::endl;
    zm1=a;
return E_OK;
} //Communicationmanager::set()



} //namespace rte


 
