
#ifndef LOGER_HPP
#define LOGER_HPP

#include"ILogger.h"

namespace srv
{

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
    eErrorCodes mLog_INF(std::string a_strInput);
    eErrorCodes mLog_WRN(std::string a_strInput);
    };

}
#endif

