/// @file
/// Test Project Euler Problem 10
/// \test Test problem 10 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  FILE *stream;

  // Open file
  stream = fopen("tests/input/test-problem-010.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get sum of primes below 10
  problem010CL(stream);

  // Get sum of primes below 2000000
  problem010CL(stream);

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
