#include "unity_fixture.h"
#include "prime_factors.h"

TEST_GROUP(PrimeFactors);

TEST_SETUP(PrimeFactors) {}
TEST_TEAR_DOWN(PrimeFactors) {}


TEST(PrimeFactors,FactorsOfOne)
{
  int *actual = prime_factors_of(1);
  TEST_ASSERT_NULL(actual);
}

TEST(PrimeFactors,FactorsOfOne_Alt)
{
  int *actual;
  int count = alt_prime_factors_of(1, &actual);
  TEST_ASSERT_EQUAL(0,count);
  TEST_ASSERT_NULL(actual);
}

TEST(PrimeFactors,FactorsOfTwo)
{
  int expected[] = { 2 };
  int *actual = prime_factors_of(2);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 1);
}

TEST(PrimeFactors, FactorsOfTwo_Alt)
{
  int expected[] = { 2 };
  int *actual = NULL;
  int count = alt_prime_factors_of(2, &actual);
  TEST_ASSERT_EQUAL(1,count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
}

TEST(PrimeFactors,FactorsOfThree)
{
  int expected[] = { 3 };
  int *actual = prime_factors_of(3);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 1);
}

TEST(PrimeFactors,FactorsOfThree_Alt)
{
  int *actual = NULL;
  int expected[] = { 3 };
  int count = alt_prime_factors_of(3, &actual);
  TEST_ASSERT_EQUAL(1,count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
}

TEST(PrimeFactors,FactorsOfFour)
{
  int expected[] = { 2, 2 };
  int *actual = prime_factors_of(4);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 2);
}

TEST(PrimeFactors,FactorsOfFour_Alt)
{
  int *actual = NULL;
  int expected[] = { 2, 2 };
  int count = alt_prime_factors_of(4, &actual);
  TEST_ASSERT_EQUAL(2,count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
}

TEST(PrimeFactors,FactorsOfFive)
{
  int expected[] = { 5 };
  int *actual = prime_factors_of(5);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 1);
}

TEST(PrimeFactors,FactorsOfFive_Alt)
{
  int *actual = NULL;
  int expected[] = { 5 };
  int count = alt_prime_factors_of(5, &actual);
  TEST_ASSERT_EQUAL(1, count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
}

TEST(PrimeFactors,FactorsOfEight)
{
  int expected[] = { 2, 2, 2 };
  int *actual = prime_factors_of(8);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 3);
}

TEST(PrimeFactors,FactorsOfEight_Alt)
{
  int *actual = NULL;
  int expected[] = { 2, 2, 2 };
  int count = alt_prime_factors_of(8, &actual);
  TEST_ASSERT_EQUAL(3, count);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, count);
}

TEST(PrimeFactors,FactorsOfTweleve)
{
  int expected[] = { 2, 2, 3 };
  int *actual = prime_factors_of(12);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 3);
}

TEST(PrimeFactors,FactorsOfTweleve_Alt)
{
  int *actual = NULL;
  int expected[] = { 2, 2, 3 };
  int count = alt_prime_factors_of(12, &actual);
  TEST_ASSERT_EQUAL(3, count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
}

TEST(PrimeFactors,FactorsOfTwentyFour)
{
  int expected[] = { 2, 2, 2, 3 };
  int *actual = prime_factors_of(24);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 4);
}

TEST(PrimeFactors,FactorsOfTwentyFour_Alt)
{
  int *actual = NULL;
  int expected[] = { 2, 2, 2, 3 };
  int count = alt_prime_factors_of(24, &actual);
  TEST_ASSERT_EQUAL(4, count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
}

TEST_GROUP_RUNNER(PrimeFactors)
{
  RUN_TEST_CASE(PrimeFactors,FactorsOfOne);
  RUN_TEST_CASE(PrimeFactors,FactorsOfOne_Alt);
  RUN_TEST_CASE(PrimeFactors,FactorsOfTwo);
  RUN_TEST_CASE(PrimeFactors,FactorsOfTwo_Alt);
  RUN_TEST_CASE(PrimeFactors,FactorsOfThree);
  RUN_TEST_CASE(PrimeFactors,FactorsOfThree_Alt);
  RUN_TEST_CASE(PrimeFactors,FactorsOfFour);
  RUN_TEST_CASE(PrimeFactors,FactorsOfFour_Alt);
  RUN_TEST_CASE(PrimeFactors,FactorsOfFive);
  RUN_TEST_CASE(PrimeFactors,FactorsOfFive_Alt);
  RUN_TEST_CASE(PrimeFactors,FactorsOfEight);
  RUN_TEST_CASE(PrimeFactors,FactorsOfEight_Alt);
  RUN_TEST_CASE(PrimeFactors,FactorsOfTweleve);
  RUN_TEST_CASE(PrimeFactors,FactorsOfTweleve_Alt);
  RUN_TEST_CASE(PrimeFactors,FactorsOfTwentyFour);
  RUN_TEST_CASE(PrimeFactors,FactorsOfTwentyFour_Alt);
}

