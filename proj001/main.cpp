//=============================================================================
// Project      <<TESTOWY>>
//
// Copyright <2018> MB 
//
//=============================================================================
/// @file        <main.cpp>
/// @ingroup     <core>
/// @brief       <main>
#include<iostream>
#include"apl/timemaster.hpp"
#include"rte/communicationmanager.hpp"
#include"service/router.hpp"
#include"service/lcm.hpp"
#include"driver/ethernet.hpp"
#include"service/starter.hpp"


service::Starter starterobj;
apl::Timemaster *timemasterobj;
rte::Communicationmanager *commmanagerobj;
service::Router *routerobj;
service::Lcm *lcmobj;
driver::Ethernet *ethernetobj;


int main (void)
{



std::cout<<"Creating objects using starters start() method:"<<std::endl;
if(starterobj.start(timemasterobj,commmanagerobj,routerobj,lcmobj,ethernetobj)==0)
{
    std::cout<<"-objects created!"<<std::endl;
}
else
{
    std::cout<<"-error creating objects!!"<<std::endl;
}

std::cout<<"Registering objects using starters reg() method:"<<std::endl;
if(starterobj.reg()==0)
{
    std::cout<<"-all objects registered!"<<std::endl;
}
else
{
    std::cout<<"-error registering objects!!"<<std::endl;
}

std::cout<<"Initialize all registered obj using lcm init() method:"<<std::endl;
if(lcmobj->init()==0)
{
    std::cout<<"-incjalization OK!"<<std::endl;
}
else
{
    std::cout<<"-inicjalization error!!"<<std::endl;
}


return 0;
}


