#include "unity_fixture.h"
#include "factorizer.h"

TEST_GROUP(Factorize);

TEST_SETUP(Factorize) {}
TEST_TEAR_DOWN(Factorize) {}

TEST(Factorize,FactorsOfOne)
{
  int expected[] = { 1 };
  int *actual = factors_of(1);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 1);
}

TEST(Factorize,FactorsOfTwo)
{
  int expected[] = { 1, 2};
  int *actual = factors_of(2);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 2);
}

TEST(Factorize,FactorsOfThree)
{
  int expected[] = { 1, 3 };
  int *actual = factors_of(3);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 2);
}

TEST(Factorize,FactorsOfFour)
{
}

TEST(Factorize,FactorsOfFive)
{
}

TEST(Factorize,FactorsOfEight)
{
}

TEST(Factorize,FactorsOfTwelve)
{
}


TEST_GROUP_RUNNER(Factorize)
{
  RUN_TEST_CASE(Factorize,FactorsOfOne);
  RUN_TEST_CASE(Factorize,FactorsOfTwo);
  RUN_TEST_CASE(Factorize,FactorsOfThree);
}

