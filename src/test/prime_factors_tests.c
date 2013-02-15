#include "unity_fixture.h"
#include "prime_factors.h"

TEST_GROUP(PrimeFactors);

TEST_SETUP(PrimeFactors) {}
TEST_TEAR_DOWN(PrimeFactors) {}

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
  free(actual);
}


TEST_GROUP_RUNNER(PrimeFactors)
{
  RUN_TEST_CASE(PrimeFactors,FactorsOfTwo);
  RUN_TEST_CASE(PrimeFactors,FactorsOfTwo_Alt);
}

