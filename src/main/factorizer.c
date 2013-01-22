#include "factorizer.h"
#include <math.h>
#include <stdio.h>

int *factors_of(unsigned int number)
{
  int *factors = malloc(2*sizeof(int));
  factors[0] = 1;
  int n = 1;
  for(int i = 2; i < sqrt(number); i++, n++)
    {
      printf("number:%d i:%d\n",number,i);
      if (number % i == 0)
	{
	  printf("%d is a factor of %d",i,number);
	  factors = realloc(factors, n+1);
	  factors[n] = i;
	}
    }
  factors[n] = number;
  return factors;
}
