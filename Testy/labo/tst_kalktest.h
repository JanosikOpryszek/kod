#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <kalkulator.h>


using namespace testing;

TEST(kalktest, suma)
{

    kalkulator kalk;
    //EXPECT_EQ(1, 1);
    ASSERT_EQ(kalk.suma(2,3),5);
    ASSERT_EQ(kalk.dzielenie(8,0),0);
}
