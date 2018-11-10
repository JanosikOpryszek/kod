//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <itimemaster.hpp>
/// @ingroup     <publ>
/// @brief       <interface of Timemaster>


#ifndef ITIMEMASTER_HPP
#define ITIMEMASTER_HPP

#include<iostream>
#include"errorcode.hpp"

namespace publ 
{

class ITimemaster: public Errorcode
{
public:
virtual int init()=0;

int metoda();

};    //class prototypes

}     //namespace publ

#endif //ITIMEMASTER_HPP


 
