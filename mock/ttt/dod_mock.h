#ifndef DOD_MOCK_H
#define DOD_MOCK_H

#include "gmock/gmock.h"

#include "../kalkulator/dodaj.h"

namespace mocks{


class Dod_mock:public kalk::Dodaj
{
public:
    Dod_mock();
    virtual ~Dod_mock();

    MOCK_METHOD2( dodawanie, int(int id, int id2));

};



} //namespace mocks{

#endif // DOD_MOCK_H
