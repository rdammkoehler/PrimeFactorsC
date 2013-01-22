#include "factorizer.h"
#include <stdio.h>

int *factors_of(unsigned int number)
{
  int *factors = malloc(2*sizeof(int)), n = 1;
  factors[0] = 1;
  for(int i = 2; i <= number/2; i++)
    {
      if (number % i == 0)
	{
	  factors = realloc(factors, n+2);
	  factors[n++] = i;
	}
    }
  factors[n] = number;
  for(int i = 0; i < n; printf("%d, ",factors[i++]));
  return factors;
}
