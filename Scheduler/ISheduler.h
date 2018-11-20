#ifndef ISHEDULER_H
#define ISHEDULER_H

#include "pub/ISubject.h"

class ISheduler
        :public IObserver
{
public:
    eErrorCodes mOnStateChange(eStates a_sNewState);
};


#endif // ISHEDULER_H
