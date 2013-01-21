#include "is_prime.h"
#include <math.h>

bool IsPrime(unsigned int number)
{
  bool prime = true;
  for(int divisor = 2; divisor <= sqrtl(number) && prime; divisor++)
    {
      prime = number % divisor != 0;
    }
  return prime;
}
