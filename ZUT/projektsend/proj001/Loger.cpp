#include "Loger.hpp"
#include<iostream>




    eErrorCodes Loger::errRet;
    
    Loger::Loger()
    {
    std::cout<<"Logger created"<<std::endl;
    }

    Loger::~Loger()
    {

    }

    eErrorCodes Loger::init()
    {
        errRet=OK;    
        return errRet;
    }

    eErrorCodes Loger::deinit()
    {
        errRet=OK;    
        return errRet;
    }



    eErrorCodes Loger::mLog_ERR(std::string a_strInput)
    {
        std::cout<<a_strInput<<std::endl;
        errRet=OK;    
        return errRet;
    }


    eErrorCodes Loger::mLog_DBG(std::string a_strInput)
    {
        std::cout<<a_strInput<<std::endl;
        errRet=OK;    
        return errRet;
    }




