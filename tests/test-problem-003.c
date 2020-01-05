#include <stdio.h>
#include "euler.h"
/// @file
/// Test Project Euler Problem 3
// -----------------------------------------------------------------------------
int main(void) {
  long number = 600851475143, factor;

  // Get largest prime factor
  problem3(number, &factor);

  // Check
  if (sum != 6857)
    printf("Error:\n\tComputed: %d != True: 6857\n", sum);

  return 0;
}
// -----------------------------------------------------------------------------
