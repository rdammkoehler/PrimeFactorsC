#include "unity_fixture.h"
#include "factorizer.h"

TEST_GROUP(Factorizer);

TEST_SETUP(Factorizer) {}
TEST_TEAR_DOWN(Factorizer) {}

TEST(Factorizer,FactorsOfOne)
{
  unsigned int expected [1] = { 1 };
  unsigned int *actual = factorize(1);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected,actual, 1);
}

TEST(Factorizer,FactorsOfFive)
{
  unsigned int expected [4] = { 1, 5 };
  unsigned int *actual = factorize(5);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected,actual, 2);
}

TEST(Factorizer,FactorsOfSix)
{
  unsigned int expected [4] = { 1, 2, 3, 6 };
  unsigned int *actual = factorize(6);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected,actual, 4);
}

TEST_GROUP_RUNNER(Factorizer)
{
  RUN_TEST_CASE(Factorizer,FactorsOfOne);
  RUN_TEST_CASE(Factorizer,FactorsOfSix);
}
