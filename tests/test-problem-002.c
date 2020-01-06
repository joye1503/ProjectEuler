/// @file
/// Test Project Euler Problem 2
/// \test Test problem 2 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 4613732;
  long a = 2, limit = 4000000, sum;

  // Get sum
  problem2(a, limit, &sum);

  // Check
  if (sum != trueResult)
    printf("Error:\n\tComputed: %ld != True: %ld\n", sum, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
