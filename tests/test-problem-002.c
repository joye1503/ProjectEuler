#include <stdio.h>
#include "euler.h"
/// @file
/// Test Project Euler Problem 2
// -----------------------------------------------------------------------------
int main(void) {
  int a = 2, limit = 4000000, sum, trueResult = 4613732;

  // Get sum
  problem2(a, limit, &sum);

  // Check
  if (sum != trueResult)
    printf("Error:\n\tComputed: %d != True: %d\n", sum, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
