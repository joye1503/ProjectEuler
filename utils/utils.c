#include "utils.h"
/// @file
/// Interface utilities
///
/// @addtogroup Utilities
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Get user input integer

  @param[in] userPrompt  Text for user prompt
  @param[out] input      User input integer

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int getUserInt(char *userPrompt, int *input) {
  char *p, s[100];
  int n = 0;

  // Get user input with given prompt
  printf("%s", userPrompt);
  while (fgets(s, sizeof(s), stdin)) {
    n = strtol(s, &p, 10);
    // Check for integer
    if (p == s || *p != '\n') {
      printf("%s", userPrompt);
    } else break;
  }

  // Save user input
  *input = n;

  return 0;
};
// -----------------------------------------------------------------------------
/**
  @brief Get user input integer from a range

  @param[in] userPrompt  Text for user prompt
  @param[in] lower       Lower end of range, inclusive
  @param[in] upper       Upper end of range, inclusive
  @param[out] input      User input integer

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int getValidUserInt(char *userPrompt, int lower, int upper, int *input) {
  bool valid = false;

  // Loop until valid
  while (!valid) {
    getUserInt(userPrompt, input);
    if (*input < lower || *input > upper)
      printf("Invalid input! Provide a value in the range [%d - %d].\n", lower,
             upper);
    else
      break;
  }

  return 0;
};
// -----------------------------------------------------------------------------
/**
  @brief Get user input integer (long int)

  @param[in] userPrompt  Text for user prompt
  @param[out] input      User input integer

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int getUserLong(char *userPrompt, long *input) {
  char *p, s[100];
  long n = 0;

  // Get user input with given prompt
  printf("%s", userPrompt);
  while (fgets(s, sizeof(s), stdin)) {
    n = strtol(s, &p, 10);
    // Check for integer
    if (p == s || *p != '\n') {
      printf("%s", userPrompt);
    } else break;
  }

  // Save user input
  *input = n;

  return 0;
};
// -----------------------------------------------------------------------------
/**
  @brief Get user input integer (long int) from a range

  @param[in] userPrompt  Text for user prompt
  @param[in] lower       Lower end of range, inclusive
  @param[in] upper       Upper end of range, inclusive
  @param[out] input      User input integer

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int getValidUserLong(char *userPrompt, long lower, long upper, long *input) {
  bool valid = false;

  // Loop until valid
  while (!valid) {
    getUserLong(userPrompt, input);
    if (*input < lower || *input > upper)
      printf("Invalid input! Provide a value in the range [%ld - %ld].\n", lower,
             upper);
    else
      break;
  }

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
