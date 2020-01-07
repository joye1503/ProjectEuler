#include "utils.h"
/// @file
/// Mathematical utilities
///
/// @addtogroup Math
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Compute gcd of integers (long int) a and b

  @param[in] a        first integer
  @param[in] b        second integer
  @param[out] result  gcd of a and b

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int calculateGCD(long a, long b, long *result) {
  // Compute gcd
  if (b == 0)
    *result = a;
  else
    calculateGCD(b, a % b, result);

  return 0;
};
// -----------------------------------------------------------------------------
/**
  @brief Compute lcm of integers (long int) a and b

  @param[in] a        first integer
  @param[in] b        second integer
  @param[out] result  lcm of a and b

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int calculateLCM(long a, long b, long *result) {
  // Compute gcd
  long gcd;
  calculateGCD(a, b, &gcd);

  // Compute lcm
  long lcm = a * b / gcd;

  *result = lcm;

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
int isPrime(long number, bool *prime) {
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
/**
  @brief Check if number (long int) is a palindrome

  @param[in] number  number to check as palindrome
  @param[out] prime  boolian value, true if palindrome, othewise false

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int isPalindrome(long number, bool *palindrome) {
  int numdigits = floor(log10(number)) + 1;

  // Convert to array
  int *numasarray;
  numasarray = (int *)calloc(numdigits, sizeof(int));
  long copy = number;
  for (int i = 0; i < numdigits; i++) {
    numasarray[i] = copy % 10;
    copy /= 10;
  }

  // Check if palindrome
  for (int i = 0; i < numdigits / 2; i++) {
    *palindrome = (numasarray[i] == numasarray[numdigits-i-1]);
    if (!(*palindrome))
      break;
  }

  // Cleanup
  free(numasarray);

  return 0;
};
// -----------------------------------------------------------------------------
long longMin(long a, long b) {
  return a < b ? a : b;
};
/**
  @brief Return maximum of two integers (long int)

  @param[in] a  first integer
  @param[in] b  second integer

  @return  Maximum of a and b
**/
// -----------------------------------------------------------------------------
long longMax(long a, long b) {
  return a > b ? a : b;
};
// -----------------------------------------------------------------------------
/**
  @brief Return integer (long int) power

  @param[in] base   base to exponentiate
  @param[in] power  power to raise the base to

  @return base^power

  @ref Utility
**/
// -----------------------------------------------------------------------------
long longPow(long base, long power) {
  long result = 1;

  while (power) {
    if (power & 1) result *= base;
    power >>= 1;
    base *= base;
  }
  return result;
}
/// @}
