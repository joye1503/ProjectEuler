#include <stdio.h>
#include "euler.h"
/// @file
/// Test Project Euler Problem 1
// -----------------------------------------------------------------------------
int main(void) {
  int a = 3, b = 5, limit = 1000, sum, trueResult = 233168;

  // Get sum
  problem1(a, b, limit, &sum);

  // Check
  if (sum != trueResult)
    printf("Error:\n\tComputed: %d != True: %d\n", sum, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
