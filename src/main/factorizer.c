#include "factorizer.h"

unsigned int count_factors(unsigned int number)
{
  unsigned int ct = 1;
  for(unsigned int i = 2; i <= (0.5*number); i++) 
    {
      if ( number % i == 0 )
	{
	  ct++;
	}
    }
  return ct;
}

unsigned int next_factor(unsigned int number, unsigned int last_factor)
{
  for(unsigned int i = last_factor + 1; i <= (0.5*number); i++)
    {
      if (number % i == 0)
	{
	  return i;
	}
    }
  return 1;
}

unsigned int *factorize(unsigned int number)
{
  unsigned int factor_count = count_factors(number);
  unsigned int *rval = malloc((factor_count+1)*sizeof(unsigned int));
  rval[0] = 1;
  for(unsigned int i = 1; i < factor_count; i++)
    {
      rval[i] = next_factor(number,rval[i-1]);
    }
  rval[factor_count] = number;
  return rval;
}
