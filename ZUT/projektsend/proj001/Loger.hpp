
#ifndef LOGER_HPP
#define LOGER_HPP

#include"ILogger.h"
//#include"eErrorCodes.h"



class Loger:public srv::ILogger
    {
    static eErrorCodes errRet;
    public:
    Loger();
    ~Loger();
    eErrorCodes init();
    eErrorCodes deinit();
    eErrorCodes mLog_ERR(std::string a_strInput);
    eErrorCodes mLog_DBG(std::string a_strInput);
    };


#endif

