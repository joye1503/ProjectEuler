#include <stdio.h>

// -----------------------------------------------------------------------------
// Math utilities
// -----------------------------------------------------------------------------
/* Compute GCD of integers a and b
*/
int calculateGCD(int a, int b) {
  // Compute gcd
  if (b == 0)
    return a;
  else
    return calculateGCD(b, a % b);
};

/* Compute LCM of integers a and b
*/
int calculateLCM(int a, int b) {
  // Compute gcd
  int gcd = calculateGCD(a, b);

  // Compute lcm
  int lcm = a * b / gcd;

  return lcm;
};
