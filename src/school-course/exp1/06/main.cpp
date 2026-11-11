#include <gtest/gtest.h>

#include "leap_year.h"


TEST(LeapYearTest, DivisibleByFourIsLeapYear)
{
    EXPECT_TRUE(isLeapYear(2024));
}

TEST(LeapYearTest, OrdinaryYearIsNotLeapYear)
{
    EXPECT_FALSE(isLeapYear(2023));
}

TEST(LeapYearTest, CenturyNotDivisibleBy400IsNotLeapYear)
{
    EXPECT_FALSE(isLeapYear(1900));
}

TEST(LeapYearTest, DivisibleBy400IsLeapYear)
{
    EXPECT_TRUE(isLeapYear(2000));
}

TEST(LeapYearTest, NonPositiveYearIsNotLeapYear)
{
    EXPECT_FALSE(isLeapYear(0));
    EXPECT_FALSE(isLeapYear(-400));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
