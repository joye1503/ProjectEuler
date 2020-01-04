#include <stdio.h>
#include "euler.h"
/// @file
/// Test Project Euler Problem 2
// -----------------------------------------------------------------------------
int main(void) {
  int a = 2, limit = 4000000, sum;

  // Get sum
  problem2(a, limit, &sum);

  // Check
  if (sum != 4613732)
    printf("Error:\n\tComputed: %d != True: 4613732\n", sum);

  return 0;
}
// -----------------------------------------------------------------------------
