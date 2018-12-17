//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <Imsgvermethod.h>
/// @ingroup     <drv>
/// @brief       <interface with method- putmessage for  MSGveryficator>

#ifndef IMSGVERMETHOD_H     //PLIK Z KATALOGU MSGver
#define IMSGVERMETHOD_H

#include<string>
//#include"pub/eErrorCodes.h"      //oryginalnie z folderu pub
#include"eErrorCodes.h"      //oryginalnie z folderu pub

namespace drv
{

class Imsgvermethod
    {
    public:
    virtual ~Imsgvermethod(){}

    //========================================
    /// @brief     <recieve msg from ethernet>
    /// @param     [IN]  <string>
    /// @param     [OUT] <output error cod>
    /// @return    <enum error code >
    //========================================
   virtual eErrorCodes putMessage(std::string comingMessage)=0;
    };    //class prototypes

}     //namespace drv


#endif // IMSGVERMETHOD_H











