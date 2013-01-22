#include "prime_factors.h"
#include <stdlib.h>

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
