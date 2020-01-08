/// @file
/// Test Project Euler isPrimeFallback
/// \test Test isPrimeFallback result
#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  bool trueResult = true;
  long a = 104729;
  bool prime;

  // Get primality
  isPrimeFallback(a, &prime);

  // Check
  if (prime != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %s != True: %s\n", prime ? "true" : "false",
           trueResult ? "true" : "false");
  // LCOV_EXCL_STOP

  // Second test
  trueResult = false;
  a = 104731;

  // Get primality
  isPrimeFallback(a, &prime);

  // Check
  if (prime != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %s != True: %s\n", prime ? "true" : "false",
           trueResult ? "true" : "false");
  // LCOV_EXCL_STOP

  return 0;
}
// -----------------------------------------------------------------------------
