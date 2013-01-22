#include "factorizer.h"
#include <stdlib.h>

int *factors_of(unsigned int number)
{
  int *factors = malloc(2*sizeof(int)), n = 1;
  factors[0] = 1;
  for(int i = 2; i <= number/2; i++)
    {
      if (number % i == 0)
	{
	  factors = realloc(factors, (n+2)*sizeof(int));
	  factors[n++] = i;
	}
    }
  factors[n] = number;
  return factors;
}
