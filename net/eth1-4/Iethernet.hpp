//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <Iethernet.hpp>
/// @ingroup     <drv>
/// @brief       <interface for MSGveryficator>


#ifndef IETHERNET_HPP
#define IETHERNET_HPP


namespace drv
{

class Iethernet
    {
    public:
    virtual ~Iethernet(){};
    //========================================
    /// @brief     <send msg to ethernet>
    /// @param     [IN]  <string>
    /// @param     [OUT] <output error cod>
    /// @return    <enum error code >
    //========================================
    virtual eErrorCodes send(char [])=0;

    };    //class prototypes

}     //namespace drv

#endif //IETHERNET_HPP
