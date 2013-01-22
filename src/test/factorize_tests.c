#include "unity_fixture.h"

TEST_GROUP(Factorize);

TEST_SETUP(Factorize) {}
TEST_TEAR_DOWN(Factorize) {}

TEST(Factorize,FactorsOfOne)
{
  int expected[] = { 1 };
  int actual[] = { 1 };
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 1);
}

TEST_GROUP_RUNNER(Factorize)
{
  RUN_TEST_CASE(Factorize,FactorsOfOne);
}

