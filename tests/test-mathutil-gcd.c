/// @file
/// Test Project Euler calculateGCD
/// \test Test calculateGCD result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  int trueResult = 7;
  int a = 14, b = 35, gcd;

  // Get GCD
  calculateGCD(a, b, &gcd);

  // Check
  if (gcd != trueResult)
    printf("Error:\n\tComputed: %d != True: %d\n", gcd, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
