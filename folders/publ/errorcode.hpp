//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <errorcode.hpp>
/// @ingroup     <publ>
/// @brief       <error code prototype>


#ifndef ERRORCODE_HPP
#define ERRORCODE_HPP

#include<iostream>

namespace publ 
{

class Errorcode 
{
public:
enum
{
E_OK = 0,
E_INVALID_INPUT = 1,
E_FILE_NOT_FOUND =2
};    //enum 
};    //class prototypes

}     //namespace publ

#endif //ERRORCODE_HPP


 
