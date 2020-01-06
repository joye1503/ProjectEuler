/// @file
/// Test Project Euler calculateLCM
/// \test Test calculateLCM result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  int trueResult = 70;
  int a = 14, b = 35, lcm;

  // Get GCD
  calculateLCM(a, b, &lcm);

  // Check
  if (lcm != trueResult)
    printf("Error:\n\tComputed: %d != True: %d\n", lcm, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
