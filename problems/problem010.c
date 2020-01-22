#include <math.h>
#include <string.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 20
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the sum of all prime numbers below n

  @param[in] n         limit to sum to
  @param[out] product  sum of prime numbers below n

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem010(int n, long *sum) {
  bool *primality;
  long bound = floor((n - 2) / 2) + 1;

  // Initalize array
  primality = (bool *)calloc(bound, sizeof(bool));
  for (int i = 1; i < bound; i++)
    primality[i] = true;

  // Sieve of Erathosthenes
  for (int i = 1; i < bound; i++)
    if (primality[i])
      for (int j = 3*i+1; j < bound; j+=2*i+1)
        primality[j] = false;

  // Compute sum
  *sum = 2;
  for (int i = 1; i < bound; i++)
    if (primality[i])
      *sum += 2*i+1;

  // Cleanup
  free(primality);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 10

  The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

  Find the sum of all the primes below two million.
**/
// -----------------------------------------------------------------------------
int problem010CL(FILE *stream) {
  int ierr;

  long n, sum;

  // Get a and limit from user
  printf("    This code finds the sum of all prime numbers below [n].\n\n");
  ierr = getValidUserLong("      Enter n: ", stream, 3, INT_MAX, &n);
  ErrChk(ierr);

  // Find lcm
  ierr = problem010(n, &sum); ErrChk(ierr);

  printf("    The sum of all prime numbers below %ld: %ld\n\n",
         n, sum);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
