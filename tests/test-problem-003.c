/// @file
/// Test Project Euler Problem 3
/// \test Test problem 3 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 6857;
  long number = 600851475143, factor;

  // Get largest prime factor
  problem3(number, &factor);

  // Check
  if (factor != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %ld != True: %ld\n", factor, trueResult);
  // LCOV_EXCL_STOP

  return 0;
}
// -----------------------------------------------------------------------------
