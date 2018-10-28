#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../kalkulator.h"

using namespace testing;

TEST(t1, t1)
{
    int wynik=kalkulator(2,3);
    ASSERT_EQ(wynik, 5);
}
