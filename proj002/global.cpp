//=============================================================================
// Project      <<TESTOWY>>
//
// Copyright <2018> MB 
//
//=============================================================================
/// @file        <global.hpp>
/// @ingroup     <core>
/// @brief       <global>
#ifndef GLOBAL_HPP
#define GLOBAL_HPP


#include"apl/timemaster.hpp"
#include"rte/communicationmanager.hpp"
#include"service/router.hpp"
#include"service/lcm.hpp"
#include"driver/ethernet.hpp"
#include"service/starter.hpp"


extern service::Starter starterobj;
extern apl::Timemaster *timemasterobj;
extern rte::Communicationmanager *commmanagerobj;
extern service::Router *routerobj;
extern service::Lcm *lcmobj;
extern driver::Ethernet *ethernetobj;
extern int kond1;

#endif //GLOBAL
