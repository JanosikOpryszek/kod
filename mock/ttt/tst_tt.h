//#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
 #include "dod_mock.h"
 #include "od_mock.h"

#include "../kalkulator/kalkulator.h"

using namespace testing;


namespace my_test
{
/*
MATCHER_P(nazwamatchera, obiekt, "")
{
    bool isMatch = true;
    isMatch = isMatch && arg.enStatus == obiekt.enStatus;
    return isMatch;
}
*/

class Base
{
public:

    Base()
    {
        vDefineDefaultActions();
    }

    virtual ~Base()
    {
    }

    void vDefineDefaultActions()
    {
        // init default action

//            ON_CALL(m_dpool_mock, DPOOL_enSetPoolData(_, _))
//                .WillByDefault(Return(E_DATA_OK));

    }

//dodawanie mockow
        NiceMock<mocks::Dod_mock>  dod_mock;
        NiceMock<mocks::Od_mock>  od_mock;

    };

class KlasaTestowa : public Base, public testing::Test
{
protected:
    virtual void SetUp()
    {
        kalkobj=new kalk::Kalkulator(dod_mock,od_mock);
    }

    virtual void TearDown()
    {

    }

    kalk::Kalkulator *kalkobj;

};



TEST_F(KlasaTestowa, test1)
{
    EXPECT_CALL(dod_mock, dodawanie(_,_)).WillOnce(Return(9));
    int ret = kalkobj->dodaj(5,4);
    EXPECT_EQ(ret, 9);
}

TEST_F(KlasaTestowa, test2)
{
    EXPECT_CALL(od_mock, odejmowanie(_,_)).Times(2).WillRepeatedly(Return(5));
    kalkobj->odejmij(11,6);
    int ret2 = kalkobj->odejmij(11,6);
    EXPECT_EQ(ret2, 5);
}




} //namespace
