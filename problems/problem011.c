#include <math.h>
#include <string.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 11
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the greatest product of n adjacent entries in the grid

  @param[in] n         number of adjacent entries
  @param[out] product  greatest product of adjacent entries

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem011(int n, long *product) {
  FILE *stream;
  long bestProd = -1;
  char s[1001], nullchar[1] = "\0";
  int grid[20][20];

  // Open file
  stream = fopen("data/grid.txt", "r");

  // Check good open
  if(stream == NULL)
    // LCOV_EXCL_START
    return Error(1, "grid file failed to load.", NULL);
  // LCOV_EXCL_STOP

  // Grid array
  for (int i = 0; i < 20; i++) {
    if(fgets(s, sizeof(s), stream) == NULL)
      // LCOV_EXCL_START
      return Error(1, "grid file entry failed to load.", NULL);
    // LCOV_EXCL_STOP
    for (int j = 0; j < 20; j++) {
      s[j*3+2] = nullchar[0];
      grid[i][j] = strtol(s+j*3, NULL, 10);
    }
  }

  // Close
  fclose(stream);

  // Check products of adjacent numbers
  int strides[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 20 - n*strides[i][0]; j++)
      for (int k = 0 + (strides[i][1] >= 0 ? 0 : n);
           k < 20 - n*strides[i][1] + (strides[i][1] >= 0 ? 0 : n); k++) {
        long prod = 1;
        for (int m = 0; m < n; m++)
          prod *= grid[j+m*strides[i][0]][k+m*strides[i][1]];
        if (prod > bestProd)
          bestProd = prod;
      }

  // Save result
  *product = bestProd;

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 11

  In the 20×20 grid below, four numbers along a diagonal line have been marked
    in red.

  The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

  What is the greatest product of four adjacent numbers in the same direction
    (up, down, left, right, or diagonally) in the 20×20 grid?
**/
// -----------------------------------------------------------------------------
int problem011CL(FILE *stream) {
  int ierr;

  int n;
  long product;

  // Get number adjacent from user
  printf("    This code finds the largest product of [n] adjacent entries in\n"
         "      grid of numbers in data/grid.txt.\n\n");
  ierr = getValidUserInt("      Enter n: ", stream, 1, 20, &n); ErrChk(ierr);

  // Find lcm
  ierr = problem011(n, &product); ErrChk(ierr);

  printf("    The greatest product of %d adjacent entries: %ld\n\n",
         n, product);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
