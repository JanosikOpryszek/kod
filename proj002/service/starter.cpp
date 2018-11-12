//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <starter.cpp>
/// @ingroup     <service>
/// @brief       <start all obj>

#include"../global.cpp"
#include"starter.hpp"
#include"../apl/timemaster.hpp"
#include"../rte/communicationmanager.hpp"
#include"router.hpp"
#include"lcm.hpp"
#include"../driver/ethernet.hpp"

namespace service
{

//========================================
/// @brief     <start obj>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Starter::start(apl::Timemaster *&t,rte::Communicationmanager *&c,Router *&r,Lcm *&l,driver::Ethernet *&e)
{

    c=new rte::Communicationmanager;
    t=new apl::Timemaster;
    r=new Router;
    l=new Lcm;
    e=new driver::Ethernet;

return E_OK;
} //Starter::start()

//========================================
/// @brief     <register adr of interfaces>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Starter::reg()
{
    timemasterobj->dodaj(commmanagerobj); 
    routerobj->dodaj(ethernetobj);
    routerobj->dodajup(commmanagerobj);
    ethernetobj->dodaj(routerobj);
    lcmobj->dodaj(ethernetobj);
    lcmobj->dodaj(routerobj);
    //lcmobj->dodaj(commmanagerobj);
    lcmobj->dodaj(timemasterobj);


return E_OK;
} //Starter::reg()




} //namespace service

