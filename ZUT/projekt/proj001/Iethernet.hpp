/// @file        <Iethernet.hpp>
/// @ingroup     <drv>
/// @brief       <interface for send MSG in network>


#ifndef IETHERNET_HPP
#define IETHERNET_HPP

#include<string>
//#include"pub/eErrorCodes.h"
#include"eErrorCodes.h"

namespace drv
{
    class Iethernet
    {
        public:
         /// @brief     <destructor>
        virtual ~Iethernet(){}
        //========================================
        /// @brief     <send msg to ethernet>
        /// @param     [IN]  <string>
        /// @param     [OUT] <output error cod>
        /// @return    <enum error code >
        //========================================
        virtual eErrorCodes send(std::string)=0;

    };    //class prototypes


}     //namespace drv

#endif //IETHERNET_HPP
