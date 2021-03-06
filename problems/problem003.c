#include <math.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 3
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the largest prime factor of a number

  @param[in] number   number to find factor of
  @param[out] factor  largest prime factor

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem003(long number, long *factor) {
  bool finished = false;
  long dividend = number;

  // Find factor
  while (!finished) {
    int ierr;

    // Check for factorization completion
    ierr = isPrime(dividend, &finished); ErrChk(ierr);
    if (finished)
      break;

    // Divide out next prime factor
    long bound = floor(sqrt((double)dividend));
    bool prime = false;
    for (long i = 2; i < bound; i++) {
      // Check for prime divisor
      if (!(dividend % i)) {
        ierr = isPrime(i, &prime); ErrChk(ierr);
      }

      // Update dividend and break
      if (prime) {
        dividend /= i;
        break;
      }
    }
  }
  *factor = dividend;

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 3

  The prime factors of 13195 are 5, 7, 13 and 29.

  What is the largest prime factor of the number 600851475143 ?
**/
// -----------------------------------------------------------------------------
int problem003CL(FILE *stream) {
  int ierr;

  long number, factor;

  // Get number from user
  printf("    This code finds the largest prime factor of a [number].\n\n");
  ierr = getUserLong("      Enter number: ", stream, &number); ErrChk(ierr);

  // Find sum of multiples
  ierr = problem003(number, &factor); ErrChk(ierr);

  printf("    The largest prime factor of %ld: %ld\n\n",
         number, factor);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
