#include "unity_fixture.h"
#include "prime_factors.h"

TEST_GROUP(PrimeFactors);

TEST_SETUP(PrimeFactors) {}
TEST_TEAR_DOWN(PrimeFactors) {}

TEST(PrimeFactors,FactorsOfOne)
{
  int expected[] = { 1 };
  int *actual = prime_factors_of(1);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 1);
}

TEST(PrimeFactors,FactorsOfTwo)
{
  int expected[] = { 1, 2};
  int *actual = prime_factors_of(2);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 2);
}

TEST(PrimeFactors,FactorsOfThree)
{
  int expected[] = { 1, 3 };
  int *actual = prime_factors_of(3);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 2);
}

TEST(PrimeFactors,FactorsOfFour)
{
  int expected[] = { 1, 2, 4 };
  int *actual = prime_factors_of(4);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 3);
}

TEST(PrimeFactors,FactorsOfFive)
{
  int expected[] = { 1, 5 };
  int *actual = prime_factors_of(5);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 2);
}

TEST(PrimeFactors,FactorsOfEight)
{
  int expected[] = { 1, 2, 4, 8 };
  int *actual = prime_factors_of(8);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 4);
}

TEST(PrimeFactors,FactorsOfTweleve)
{
  int expected[] = { 1, 2, 3, 4, 6, 12 };
  int *actual = prime_factors_of(12);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 6);
}

TEST(PrimeFactors,FactorsOfTwentyFour)
{
  int expected[] = { 1, 2, 3, 4, 6, 8, 12, 24 };
  int *actual = prime_factors_of(24);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 8);
}

TEST_GROUP_RUNNER(PrimeFactors)
{
  RUN_TEST_CASE(PrimeFactors,FactorsOfOne);
  RUN_TEST_CASE(PrimeFactors,FactorsOfTwo);
  RUN_TEST_CASE(PrimeFactors,FactorsOfThree);
  RUN_TEST_CASE(PrimeFactors,FactorsOfFour);
  RUN_TEST_CASE(PrimeFactors,FactorsOfFive);
  RUN_TEST_CASE(PrimeFactors,FactorsOfEight);
  RUN_TEST_CASE(PrimeFactors,FactorsOfTweleve);
  RUN_TEST_CASE(PrimeFactors,FactorsOfTwentyFour);
}

