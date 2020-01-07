/// @file
/// Test Project Euler isPalindrome
/// \test Test isPalindrome result
#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  bool trueResult = true;
  long a = 98765432123456789;
  bool palindrome;

  // Get primality
  isPalindrome(a, &palindrome);

  // Check
  if (palindrome != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %s != True: %s\n", palindrome ? "true" : "false",
           trueResult ? "true" : "false");
  // LCOV_EXCL_STOP

  // Second test
  trueResult = false;
  a = 999999999988;

  // Get primality
  isPalindrome(a, &palindrome);

  // Check
  if (palindrome != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %s != True: %s\n", palindrome ? "true" : "false",
           trueResult ? "true" : "false");
  // LCOV_EXCL_STOP

  return 0;
}
// -----------------------------------------------------------------------------
