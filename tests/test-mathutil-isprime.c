/// @file
/// Test Project Euler isPrime
/// \test Test isPrime result
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
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %s != True: %s\n", prime ? "true" : "false",
           trueResult ? "true" : "false");
  // LCOV_EXCL_STOP

  // Second test
  trueResult = false;
  a = 999999999988;

  // Get primality
  isPrime(a, &prime);

  // Check
  if (prime != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %s != True: %s\n", prime ? "true" : "false",
           trueResult ? "true" : "false");
  // LCOV_EXCL_STOP

  // Third test
  trueResult = true;
  a = 104729;

  // Get primality
  isPrime(a, &prime);

  // Check
  if (prime != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %s != True: %s\n", prime ? "true" : "false",
           trueResult ? "true" : "false");
  // LCOV_EXCL_STOP

  // Fourth test
  trueResult = false;
  a = 104728;

  // Get primality
  isPrime(a, &prime);

  // Check
  if (prime != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %s != True: %s\n", prime ? "true" : "false",
           trueResult ? "true" : "false");
  // LCOV_EXCL_STOP

  return 0;
}
// -----------------------------------------------------------------------------
