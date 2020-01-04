#include <stdio.h>
#include "euler.h"
/// @file
/// Test Project Euler Problem 1 solution
// -----------------------------------------------------------------------------
int main(void) {
  int a = 3, b = 5, limit = 1000, sum;

  // Get solution
  problem1(a, b, limit, &sum);

  // Check
  if (sum != 233168)
    // LCOV_EXCL_START
    printf("Error\n\t Calculated: %d != True: 233168\n", sum);
  // LCOV_EXCL_STOP

  return 0;
}
// -----------------------------------------------------------------------------
