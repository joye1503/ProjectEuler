#include <math.h>
#include <string.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 13
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the first n digits of the sum of the 100 50-digit numbers

  @param[in] n        number of digits to find
  @param[out] digits  first n digits of the sum

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem013(int n, long *digits) {
  FILE *stream;
  char s[200];
  int *sum;
  int numDigits = 50;
  long result = 0;

  // Open file
  stream = fopen("data/50digits.txt", "r");

  // Check good open
  if(stream == NULL)
    // LCOV_EXCL_START
    return Error(1, "50digits file failed to load.", NULL);
  // LCOV_EXCL_STOP

  // Initalize sum
  sum = (int *)calloc(numDigits, sizeof(int));

  // Grid array
  while(fgets(s, sizeof(s), stream)) {
    // Update sum
    int remainder = 0;
    for (int i = 0; i < 50; i++) {
      int currDigit = s[50 - 1 - i] - '0';
      sum[i] += currDigit + remainder;
      remainder = sum[i] / 10;
      sum[i] %= 10;
    }
    // Handle remainder
    int i = 50;
    while (remainder != 0) {
      if (i == numDigits) {
        sum = (int *)realloc(sum, (numDigits+1)*sizeof(int));
        sum[numDigits] = 0;
        numDigits++;
      }
      sum[i] += remainder;
      remainder = sum[i] / 10;
      sum[i] %= 10;
      i++;
    }
  }

  // Close
  fclose(stream);

  // Build result
  for (int i = 0; i < (n < numDigits ? n : numDigits); i++) {
    result *= 10;
    result += sum[numDigits - 1 - i];
  }

  // Free
  free(sum);

  // Save result
  *digits = result;

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 13

  Work out the first ten digits of the sum of the following one-hundred 50-digit
    numbers.
**/
// -----------------------------------------------------------------------------
int problem013CL(FILE *stream) {
  int ierr;

  int n;
  long digits;

  // Get number adjacent from user
  printf("    This code the first [n] digits of the sum of 100 50-digit\n"
         "      numbers found in data/50digits.txt.\n\n");
  ierr = getValidUserInt("      Enter n: ", stream, 1, INT_MAX, &n);
  ErrChk(ierr);

  // Find lcm
  ierr = problem013(n, &digits); ErrChk(ierr);

  printf("    The first %d digits of the sum: %ld\n\n",
         n, digits);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
