#ifndef OD_MOCK_H
#define OD_MOCK_H

#include "gmock/gmock.h"

#include "../kalkulator/odejmij.h"

namespace mocks{


class Od_mock:public kalk::Odejmij
{
public:
    Od_mock();
    virtual ~Od_mock();

    MOCK_METHOD2( odejmowanie, int(int id, int id2));

};



} //namespace
#endif // OD_MOCK_H
