//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <starter.hpp>
/// @ingroup     <service>
/// @brief       <starts all obj>


#ifndef STARTER_HPP
#define STARTER_HPP


#include"../publ/errorcode.hpp"
#include"starter.hpp"
#include"../apl/timemaster.hpp"
#include"../rte/communicationmanager.hpp"
#include"router.hpp"
#include"lcm.hpp"
#include"../driver/ethernet.hpp"
namespace service
{

class Starter: public publ::Errorcode

{
public:
int start(apl::Timemaster*&,rte::Communicationmanager*&,Router*&,Lcm*&,driver::Ethernet*&);
int reg();



};    //class prototypes

}     //namespace service

#endif //STARTER_HPP

 
