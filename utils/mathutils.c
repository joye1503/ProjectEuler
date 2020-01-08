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
  @brief Check if number (long int) is prime in prime list

  @param[in] number  number to check primality
  @param[out] prime  boolian value, true if prime, othewise false

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int isPrime(long number, bool *prime) {
  FILE *stream;
  char s[100];
  long n = 0;

  // Open file
  stream = fopen("utils/primes.txt", "r");

  // Fallback if no primes file
  if(stream == NULL) {
    // LCOV_EXCL_START
    isPrimeFallback(number, prime);

    return 0;
    // LCOV_EXCL_STOP
  }

  // Read prime list from file
  while (fgets(s, sizeof(s), stream)) {
     // Stop when found prime as big as number
     n = strtol(s, NULL, 10);
     if (n >= number)
       break;
  }

  // Check for completion
  if (n == number)
    *prime = true;
  else if (n > number)
    *prime = false;
  else
    // Fallback if number is larger than last prime
    isPrimeFallback(number, prime);

  // Close
  fclose(stream);

  return 0;
};
// -----------------------------------------------------------------------------
/**
  @brief Check if number (long int) is prime by calculation

  @param[in] number  number to check primality
  @param[out] prime  boolian value, true if prime, othewise false

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int isPrimeFallback(long number, bool *prime) {
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
