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

#include<iostream>
#include"../publ/itimemaster.hpp"

namespace apl
{

class Timemaster:public publ::ITimemaster
{
public:
int init();

};    //class prototypes

}     //namespace apl

#endif //TIMEMASTER_HPP


 
