/// @file
/// Test Project Euler getUserInt
/// \test Test getUserInt result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  int trueResult = 7;
  FILE *stream;
  int input;

  // Open file
  stream = fopen("tests/input/test-util-getuserint.in" , "r");
  if(stream == NULL) {
    perror("Error opening file\n");
    return(-1);
  }

  // Get userInt
  getUserInt("", stream, &input);

  // Check
  if (input != trueResult)
    printf("Error:\n\tComputed: %d != True: %d\n", input, trueResult);


  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
