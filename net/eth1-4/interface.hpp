//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <interface.hpp>
/// @ingroup     <pub>
/// @brief       <interface for all observers of LCM>


#ifndef INTERFACE_HPP
#define INTERFACE_HPP


namespace pub
{

class Interface
{
public:
//========================================
/// @brief     <configure and run inner thread>
/// @param     [IN]  <none>
/// @param     [OUT] <output error cod>
/// @return    <enum error code >
//========================================
virtual int run()=0;
//========================================
/// @brief     <init, run by LCM>
/// @param     [IN]  <none>
/// @param     [OUT] <output error cod>
/// @return    <enum error code >
//========================================
virtual int resume()=0;

//========================================
/// @brief     <deinit, run by LCM>
/// @param     [IN]  <none>
/// @param     [OUT] <output error cod>
/// @return    <enum error code >
//========================================
virtual int pause()=0;

};    //class prototypes

}     //namespace publ

#endif //INTERFACE_HPP



