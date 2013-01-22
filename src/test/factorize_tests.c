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
  int expected[] = { 1, 2, 4 };
  int *actual = factors_of(4);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 3);
}

TEST(Factorize,FactorsOfFive)
{
  int expected[] = { 1, 5 };
  int *actual = factors_of(5);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 2);
}

TEST(Factorize,FactorsOfEight)
{
  int expected[] = { 1, 2, 4, 8 };
  int *actual = factors_of(8);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 4);
}

TEST(Factorize,FactorsOfTweleve)
{
  int expected[] = { 1, 2, 3, 4, 6, 12 };
  int *actual = factors_of(12);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 6);
}

TEST(Factorize,FactorsOfTwentyFour)
{
  int expected[] = { 1, 2, 3, 4, 6, 8, 12, 24 };
  int *actual = factors_of(24);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 8);
}

TEST_GROUP_RUNNER(Factorize)
{
  RUN_TEST_CASE(Factorize,FactorsOfOne);
  RUN_TEST_CASE(Factorize,FactorsOfTwo);
  RUN_TEST_CASE(Factorize,FactorsOfThree);
  RUN_TEST_CASE(Factorize,FactorsOfFour);
  RUN_TEST_CASE(Factorize,FactorsOfFive);
  RUN_TEST_CASE(Factorize,FactorsOfEight);
  RUN_TEST_CASE(Factorize,FactorsOfTweleve);
  RUN_TEST_CASE(Factorize,FactorsOfTwentyFour);
}

