//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <interface.hpp>
/// @ingroup     <publ>
/// @brief       <interface for all>


#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include"errorcode.hpp"
#include<thread>

namespace publ 
{

class Interface: public Errorcode
{
public:
virtual int init()=0;
virtual int deinit()=0;

};    //class prototypes

}     //namespace publ

#endif //INTERFACE_HPP


 
