#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../kalkulator.h"


using namespace testing;

TEST(mojkalk, dod)
{
    //EXPECT_EQ(1, 1);
    ASSERT_EQ(kalkulator(2,3), 5);
}
