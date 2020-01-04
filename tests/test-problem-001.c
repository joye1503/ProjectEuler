#include <stdio.h>
#include "euler.h"
/// @file
/// Test Project Euler Problem 1
// -----------------------------------------------------------------------------
int main(void) {
  int a = 3, b = 5, limit = 1000, sum;

  // Get sum
  problem1(a, b, limit, &sum);

  // Check
  if (sum != 233168)
    printf("Error:\n\tComputed: %d != True: 233168\n", sum);

  return 0;
}
// -----------------------------------------------------------------------------
