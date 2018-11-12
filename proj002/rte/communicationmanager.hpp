//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <communicationmanager.hpp>
/// @ingroup     <rte>
/// @brief       <real time environment>


#ifndef COMMUNICATIONMANAGER_HPP
#define COMMUNICATIONMANAGER_HPP 


#include"../publ/interface.hpp"

namespace rte
{

class Communicationmanager:public publ::Interface
{
public:
int init();
int deinit();
int get();
int set(int);
//int dodaj(Interface *);
protected:
//Interface * pIntAdr;
int zm1;

};    //class prototypes

}     //namespace rte

#endif //COMMUNICATIONMANAGER_HPP 
 
