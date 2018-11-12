//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <timemaster.hpp>
/// @ingroup     <apl>
/// @brief       <control time>


#ifndef TIMEMASTER_HPP
#define TIMEMASTER_HPP

#include"../publ/interface.hpp"

namespace apl
{

class Timemaster:public publ::Interface
{
public:
int init();
int deinit();
int dodaj(Interface *);
protected:
Interface * pIntAdr;
int metoda();

};    //class prototypes

}     //namespace apl

#endif //TIMEMASTER_HPP


 
