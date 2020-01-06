/// @file
/// Test Project Euler Problem 1
/// \test Test problem 1 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  int trueResult = 233168;
  int a = 3, b = 5, limit = 1000, sum;

  // Get sum
  problem1(a, b, limit, &sum);

  // Check
  if (sum != trueResult)
    printf("Error:\n\tComputed: %d != True: %d\n", sum, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
