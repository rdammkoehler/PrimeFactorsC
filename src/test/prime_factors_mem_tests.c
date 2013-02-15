#include "unity_fixture.h"

/*
  Unity detects a memory leak if I don't free what I malloc in SUT -- TRUE
  
  When the SUT is inside of the test code, including <stdlib.h>
  is not necessary -- TRUE
  
  When the SUT is inside of the test code, I can inclue <stdlib.h> -- TRUE
  
  When the SUT is inside of the test code AND I use <stdlib.h> the behavior
  does not change -- TRUE
  
  On Windows, if I include <stdlib.h> I get a macro define issue 
  around malloc -- TRUE

 */

// *************************** SUT
int alt_prime_factors_of(unsigned int number, int ** prime_factors) {
  (*prime_factors) = (number==1)?NULL:(int*)malloc(0);
  int count = 0;
  for( int candidate = 2; number > 1; candidate++ )
    {
      for(; number % candidate == 0; number /= candidate) {
	(*prime_factors) = realloc((*prime_factors), (count+1)*sizeof(int));
	(*prime_factors)[count] = candidate;
	count++;
      }
    }
  return count;
}

int *prime_factors_of(unsigned int number)
{
  int *prime_factors = (number==1)?NULL:malloc(0);
  int count = 0;
  for( int candidate = 2; number > 1; candidate++ )
    {
      for(; number % candidate == 0; number /= candidate) {
	prime_factors = realloc(prime_factors, (count+1)*sizeof(int));
	prime_factors[count] = candidate;
	count++;
      }
    }
  return prime_factors;
}


// *************************** TESTS

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
  free(actual);
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

TEST(PrimeFactors,FactorsOfThree)
{
  int expected[] = { 3 };
  int *actual = prime_factors_of(3);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 1);
  free(actual);
}

TEST(PrimeFactors,FactorsOfThree_Alt)
{
  int *actual = NULL;
  int expected[] = { 3 };
  int count = alt_prime_factors_of(3, &actual);
  TEST_ASSERT_EQUAL(1,count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
  free(actual);
}

TEST(PrimeFactors,FactorsOfFour)
{
  int expected[] = { 2, 2 };
  int *actual = prime_factors_of(4);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 2);
  free(actual);
}

TEST(PrimeFactors,FactorsOfFour_Alt)
{
  int *actual = NULL;
  int expected[] = { 2, 2 };
  int count = alt_prime_factors_of(4, &actual);
  TEST_ASSERT_EQUAL(2,count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
  free(actual);
}

TEST(PrimeFactors,FactorsOfFive)
{
  int expected[] = { 5 };
  int *actual = prime_factors_of(5);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 1);
  free(actual);
}

TEST(PrimeFactors,FactorsOfFive_Alt)
{
  int *actual = NULL;
  int expected[] = { 5 };
  int count = alt_prime_factors_of(5, &actual);
  TEST_ASSERT_EQUAL(1, count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
  free(actual);
}

TEST(PrimeFactors,FactorsOfEight)
{
  int expected[] = { 2, 2, 2 };
  int *actual = prime_factors_of(8);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 3);
  free(actual);
}

TEST(PrimeFactors,FactorsOfEight_Alt)
{
  int *actual = NULL;
  int expected[] = { 2, 2, 2 };
  int count = alt_prime_factors_of(8, &actual);
  TEST_ASSERT_EQUAL(3, count);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, count);
  free(actual);
}

TEST(PrimeFactors,FactorsOfTweleve)
{
  int expected[] = { 2, 2, 3 };
  int *actual = prime_factors_of(12);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 3);
  free(actual);
}

TEST(PrimeFactors,FactorsOfTweleve_Alt)
{
  int *actual = NULL;
  int expected[] = { 2, 2, 3 };
  int count = alt_prime_factors_of(12, &actual);
  TEST_ASSERT_EQUAL(3, count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
  free(actual);
}

TEST(PrimeFactors,FactorsOfTwentyFour)
{
  int expected[] = { 2, 2, 2, 3 };
  int *actual = prime_factors_of(24);
  TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, 4);
  free(actual);
}

TEST(PrimeFactors,FactorsOfTwentyFour_Alt)
{
  int *actual = NULL;
  int expected[] = { 2, 2, 2, 3 };
  int count = alt_prime_factors_of(24, &actual);
  TEST_ASSERT_EQUAL(4, count);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, count);
  free(actual);
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

