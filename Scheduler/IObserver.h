#ifndef IOBSERVER_H
#define IOBSERVER_H

//#include <pub/eStates.h>
#include "eStates.h"
//#include <pub/eErrorCodes.h>
#include "eErrorCodes.h"

class IObserver
{
public:
    virtual ~IObserver(){}
    virtual eErrorCodes mOnStateChange(eStates a_sNewState) = 0;

};

#endif // IOBSERVER_H
