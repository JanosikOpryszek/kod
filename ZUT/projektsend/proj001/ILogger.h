#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>
#include "eErrorCodes.h"


namespace srv
{
class ILogger
{
public:
    virtual ~ILogger(){}
    /*
    virtual eErrorCodes init() = 0;
    virtual eErrorCodes deinit() = 0;
    */
    virtual eErrorCodes mLog_ERR(std::string a_strInput) = 0;
    virtual eErrorCodes mLog_DBG(std::string a_strInput) = 0;

};
}
#endif // ILOGGER_H
