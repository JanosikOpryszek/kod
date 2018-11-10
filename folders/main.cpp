//=============================================================================
// Project      <<TESTOWY>>
//
// Copyright <2018> MB 
//
//=============================================================================
/// @file        <main.cpp>
/// @ingroup     <core>
/// @brief       <main>
#include"apl/timemaster.hpp"
#include"rte/communicationmanager.hpp"
#include"service/router.hpp"
#include"driver/ethernet.hpp"
//#include"public     not here

#include<iostream>


int main (void)
{

apl::Timemaster timeobj;

std::cout<<"Testing errorcode generate, Timemaster obj from apl, method:  metoda();"<<std::endl;
std::cout<<"metoda() returns: "<<timeobj.metoda()<<std::endl;


return 0;
}


