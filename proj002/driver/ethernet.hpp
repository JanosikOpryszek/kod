//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <ethernet.hpp>
/// @ingroup     <driver>
/// @brief       <network driver>


#ifndef ETHERNET_HPP
#define ETHERNET_HPP

#include"../publ/interface.hpp"
namespace driver
{

class Ethernet:public publ::Interface

{
public:
int init();
int deinit();
int dodaj(Interface *);
protected:
Interface * pIntAdr;
int metoda();

};    //class prototypes

}     //namespace driver

#endif //ETHERNET_HPP


 
