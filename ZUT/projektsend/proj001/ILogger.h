#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>
//#include <pub/eErrorCodes.h>
//#include <pub/eStates.h>

#include "eErrorCodes.h"
#include "eStates.h"
namespace srv
{
class ILogger
{
public:
    virtual ~ILogger(){}
    virtual eErrorCodes init() = 0;
    virtual eErrorCodes deinit() = 0;
    virtual eErrorCodes mLog_ERR(std::string a_strInput) = 0;
    virtual eErrorCodes mLog_DBG(std::string a_strInput) = 0;
    //virtual eErrorCodes mLog_INF(std::string a_strInput) = 0;
    //virtual eErrorCodes mLog_WRN(std::string a_strInput) = 0;
};
}
#endif // ILOGGER_H
