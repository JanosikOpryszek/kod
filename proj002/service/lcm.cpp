//=============================================================================
// Project      <<TEST>>
//
// Copyright <2018> MBel
//
//=============================================================================
/// @file        <lcm.cpp>
/// @ingroup     <service>
/// @brief       <run init of all obj>

#include"../global.cpp"
#include<iostream>
#include<thread>
#include"lcm.hpp"

namespace service
{

//========================================
/// @brief     <init>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Lcm::init()
{
    kond1=1;
    std::thread t(&Lcm::metoda, this);
    t.detach();
//    this->metoda(); 


return E_OK;
} //Lcm::init()

//========================================
/// @brief     <deinit>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Lcm::deinit()
{

    kond1=0;

return E_OK;
} //Lcm::deinit()

//========================================
/// @brief     <any metchod>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Lcm::metoda()
{

std::cout<<"Lcm initialize all obj...."<<std::endl; 
int i=0;
std::thread  myThreads[10];                          

std::list<Interface *>::iterator it;
for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) 
{
    myThreads[i]=std::thread(&Interface::init, (*it));
    i++;
}
std::cout<<"threads started"<<std::endl;   
int end=i;
for (i=0;i<end;i++) 
{
    myThreads[i].join();
}


return E_OK;
} //Lcm::metoda()

//========================================
/// @brief     <add Obserwer to list>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Lcm::dodaj(Interface *o)
{ 
obserwatorzy.push_back(o);
std::cout<<"-obj registered!"<<std::endl;

return E_OK;
} //Lcm::dodaj()

//========================================
/// @brief     <remove Obserwer from list>
/// @param     [IN]  <input parameter + ranges>
/// @param     [OUT] <output parameter + ranges>
/// @return    <return value description>
//========================================
int Lcm::usun(Interface *o)
{ 
std::cout<<"-obj unregistered!"<<std::endl;
obserwatorzy.remove(o);
return E_OK;
} //Lcm::usun()


} //namespace service

