//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <router.hpp>
/// @ingroup     <service>
/// @brief       <manage msg>


#ifndef ROUTER_HPP
#define ROUTER_HPP


#include"../publ/interface.hpp"

namespace service
{

class Router:public publ::Interface
{
public:
int init();
int deinit();
int dodaj(Interface *);
int dodajup(Interface *);
protected:
Interface * pIntAdr;
Interface * pIntAdrup;
int metoda();
};    //class prototypes

}     //namespace service

#endif //ROUTER_HPP

 
