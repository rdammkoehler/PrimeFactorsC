#include "unity_fixture.h"
#include "is_prime.h"

TEST_GROUP(Primes);

TEST_SETUP(Primes) {}
TEST_TEAR_DOWN(Primes) {}

TEST(Primes,OneIsNotPrime)
{
  TEST_ASSERT_FALSE(isPrime(1));
}

TEST(Primes,TwoIsPrime)
{
  TEST_ASSERT_TRUE(isPrime(2));
}

TEST(Primes,ThreeIsPrime)
{
  TEST_ASSERT_TRUE(isPrime(3));
}

TEST(Primes,FourIsntPrime)
{
  TEST_ASSERT_FALSE(isPrime(4));
}

TEST(Primes,FiveIsPrime)
{
  TEST_ASSERT_TRUE(isPrime(5));
}

TEST(Primes,SixIsntPrime)
{
  TEST_ASSERT_FALSE(isPrime(6));
}

TEST(Primes,SevenIsPrime)
{
  TEST_ASSERT_TRUE(isPrime(7));
}

TEST_GROUP_RUNNER(Primes)
{
  RUN_TEST_CASE(Primes,OneIsNotPrime);
  RUN_TEST_CASE(Primes,TwoIsPrime);
  RUN_TEST_CASE(Primes,ThreeIsPrime);
  RUN_TEST_CASE(Primes,FourIsntPrime);
  RUN_TEST_CASE(Primes,FiveIsPrime);
  RUN_TEST_CASE(Primes,SixIsntPrime);
  RUN_TEST_CASE(Primes,SevenIsPrime);
}

