//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <Iethernet.hpp>
/// @ingroup     <drv>
/// @brief       <interface for MSGveryficator & PDUrouter to send MSG in network>


#ifndef IETHERNET_HPP
#define IETHERNET_HPP

#include<string>
#include"pub/eErrorCodes.h"

namespace drv
{
    class Iethernet
    {
        public:
         /// @brief     <destructor>
        virtual ~Iethernet();
        //========================================
        /// @brief     <send msg to ethernet>
        /// @param     [IN]  <string>
        /// @param     [OUT] <output error cod>
        /// @return    <enum error code >
        //========================================
        virtual eErrorCodes send(std::string)=0;

    };    //class prototypes

    Iethernet::~Iethernet()
    {

    }

}     //namespace drv

#endif //IETHERNET_HPP
