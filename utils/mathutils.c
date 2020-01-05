#include "utils.h"
/// @file
/// Mathematical utilities
///
/// @addtogroup Math
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Compute GCD of integers a and b

  @param[in] a        First integer
  @param[in] b        Second integer
  @param[out] result  GCD of a and b

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int calculateGCD(int a, int b, int *result) {
  // Compute gcd
  if (b == 0)
    *result = a;
  else
    calculateGCD(b, a % b, result);

  return 0;
};
// -----------------------------------------------------------------------------
/**
  @brief Compute LCM of integers a and b

  @param[in] a        First integer
  @param[in] b        Second integer
  @param[out] result  LCM of a and b

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int calculateLCM(int a, int b, int *result) {
  // Compute gcd
  int gcd;
  calculateGCD(a, b, &gcd);

  // Compute lcm
  int lcm = a * b / gcd;

  *result = lcm;

  return 0;
};
// -----------------------------------------------------------------------------
/**
  @brief Check if number is prime

  @param[in] number  number to check primality
  @param[out] prime  boolian value, true if prime, othewise false

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int isPrime(int number, bool *prime) {
  int bound = floor(sqrt((double)number));

  // Check if prime
  for (int i = bound; i > 1; i--) {
    *prime = number % i;
    if (!(*prime))
      break;
  }

  return 0;
};
// -----------------------------------------------------------------------------
/**
  @brief Check if number (long int) is prime

  @param[in] number  number to check primality
  @param[out] prime  boolian value, true if prime, othewise false

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int isPrimeLong(long number, bool *prime) {
  long bound = floor(sqrt((double)number));

  // Check if prime
  for (long i = bound; i > 1; i--) {
    *prime = number % i;
    if (!(*prime))
      break;
  }

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
