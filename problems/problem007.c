#include <math.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 7
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the nth prime

  @param[in] n       ordinal number of prime to find
  @param[out] prime  nth prime number

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem007(int n, long *prime) {
  FILE *stream;
  int i = 0;
  long current = 0;

  // Open file
  stream = fopen("data/primes.txt", "r");

  // Loop through list of primes
  if(stream != NULL) {
    char s[100];

    // Loop for nth prime
    while (fgets(s, sizeof(s), stream)) {
      i++;
      if (i == n)
        break;
    }
    current = strtol(s, NULL, 10);

    // Close
    fclose(stream);
  }

  // Check numbers past last prime read in, if needed
  while (i < n) {
    int ierr;

    // Iterate guess
    current++;

    // Check primality
    bool primality;
    ierr = isPrime(current, &primality); ErrChk(ierr);
    if (primality)
      i++;
  }

  // Save result
  *prime = current;

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 7

  By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
  that the 6th prime is 13.

  What is the 10 001st prime number?
**/
// -----------------------------------------------------------------------------
int problem007CL(FILE *stream) {
  int ierr;

  int n;
  long prime;

  // Get a and limit from user
  printf("    This code finds the [n]th prime.\n\n");
  ierr = getValidUserInt("      Enter n: ", stream, 1, INT_MAX, &n);
  ErrChk(ierr);

  // Find lcm
  ierr = problem007(n, &prime); ErrChk(ierr);

  printf("    The %dth prime is: %ld\n\n", n, prime);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
