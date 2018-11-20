#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <pub/eStates.h>
#include <pub/eErrorCodes.h>
class IObserver
{
public:
    virtual ~IObserver();
    virtual eErrorCodes mOnStateChange(eStates a_sNewState) = 0;

};

IObserver::~IObserver(){}

#endif // IOBSERVER_H
