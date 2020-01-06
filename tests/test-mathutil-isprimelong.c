/// @file
/// Test Project Euler isPrimeLong
/// \test Test isPrimeLong result
#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  bool trueResult = true;
  long a = 999999999989;
  bool prime;

  // Get primality
  isPrime(a, &prime);

  // Check
  if (prime != trueResult)
    printf("Error:\n\tComputed: %s != True: %s\n", prime ? "true" : "false",
           trueResult ? "true" : "false");

  // Second test
  trueResult = false;
  a = 999999999988;

  // Get primality
  isPrime(a, &prime);

  // Check
  if (prime != trueResult)
    printf("Error:\n\tComputed: %s != True: %s\n", prime ? "true" : "false",
           trueResult ? "true" : "false");

  return 0;
}
// -----------------------------------------------------------------------------
