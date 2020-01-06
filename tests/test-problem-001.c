/// @file
/// Test Project Euler Problem 1
/// \test Test problem 1 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 233168;
  long a = 3, b = 5, limit = 1000, sum;

  // Get sum
  problem1(a, b, limit, &sum);

  // Check
  if (sum != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %ld != True: %ld\n", sum, trueResult);
  // LCOV_EXCL_STOP

  return 0;
}
// -----------------------------------------------------------------------------
