#include "unity_fixture.h"
#include "is_prime.h"

TEST_GROUP(Primes);

TEST_SETUP(Primes) {}
TEST_TEAR_DOWN(Primes) {}

TEST(Primes,IsPrime)
{
  TEST_ASSERT_TRUE(IsPrime(2));
}

TEST(Primes,IsntPrime)
{
  TEST_ASSERT_FALSE(IsPrime(4));
}

TEST(Primes,AnotherPrime)
{
  TEST_ASSERT_TRUE(IsPrime(5));
}

TEST_GROUP_RUNNER(Primes)
{
  RUN_TEST_CASE(Primes,IsPrime);
  RUN_TEST_CASE(Primes,IsntPrime);
  RUN_TEST_CASE(Primes,AnotherPrime);
}
