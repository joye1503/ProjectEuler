/// @file
/// Test Project Euler isPrime
/// \test Test isPrime result
#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  bool trueResult = true;
  int a = 13;
  bool prime;

  // Get primality
  isPrime(a, &prime);

  // Check
  if (prime != trueResult)
    printf("Error:\n\tComputed: %s != True: %s\n", prime ? "true" : "false",
           trueResult ? "true" : "false");

  // Second test
  trueResult = false;
  a = 14;

  // Get primality
  isPrime(a, &prime);

  // Check
  if (prime != trueResult)
    printf("Error:\n\tComputed: %s != True: %s\n", prime ? "true" : "false",
           trueResult ? "true" : "false");

  return 0;
}
// -----------------------------------------------------------------------------
