#include "prime_factors.h"
#include <stdlib.h>

int alt_prime_factors_of(int number, int ** prime_factors) {
  (*prime_factors) = (number==1)?NULL:(int*)malloc(0);
  int count = 0;
  for( int candidate = 2; number > 1; candidate++ )
    {
      for(; number % candidate == 0; number /= candidate) {
	(*prime_factors) = (int*)realloc((*prime_factors), (count+1)*sizeof(int));
	(*prime_factors)[count] = candidate;
	count++;
      }
    }
  return count;
}

int *prime_factors_of(int number)
{
  int *prime_factors = (number==1)?NULL:(int*)malloc(0);
  int count = 0;
  for( int candidate = 2; number > 1; candidate++ )
    {
      for(; number % candidate == 0; number /= candidate) 
	{
	  prime_factors = (int*)realloc(prime_factors, (count+1)*sizeof(int));
	  prime_factors[count] = candidate;
	  count++;
	}
    }
  return prime_factors;
}
