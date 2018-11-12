//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <lcm.hpp>
/// @ingroup     <service>
/// @brief       <start init of all obj>


#ifndef LCM_HPP
#define LCM_HPP


#include"../publ/interface.hpp"
#include<list>

namespace service
{

class Lcm:public publ::Interface
{
public:
int init();
int deinit();
int dodaj(Interface *);
int usun(Interface *);

protected:
std::list <Interface*> obserwatorzy;
int metoda();

};    //class prototypes

}     //namespace service

#endif //LCM_HPP

 
