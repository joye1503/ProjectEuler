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
  if (factor != 6857)
    printf("Error:\n\tComputed: %ld != True: 6857\n", factor);

  return 0;
}
// -----------------------------------------------------------------------------
