#include <stdio.h>
#include "euler.h"
/// @file
/// Test Project Euler Problem 3
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 6857;
  long number = 600851475143, factor;

  // Get largest prime factor
  problem3(number, &factor);

  // Check
  if (factor != trueResult)
    printf("Error:\n\tComputed: %ld != True: %ld\n", factor, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
