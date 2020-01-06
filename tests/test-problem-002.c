/// @file
/// Test Project Euler Problem 2
/// \test Test problem 2 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  int trueResult = 4613732;
  int a = 2, limit = 4000000, sum;

  // Get sum
  problem2(a, limit, &sum);

  // Check
  if (sum != trueResult)
    printf("Error:\n\tComputed: %d != True: %d\n", sum, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
