#include "utils.h"
/// @file
/// Interface utilities
///
/// @addtogroup Utilities
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Error handler that prints to stderr and exits
**/
// LCOV_EXCL_START
int ErrorExit(const char *filename, int lineno, const char *func, int ecode,
              const char *format, ...) {
  va_list args;

  fprintf(stderr, "%s:%d in %s(): ", filename, lineno, func);
  va_start (args, format);
  vfprintf(stderr, format, args);
  va_end (args);
  fprintf(stderr, "\n");
  exit(ecode);
  return ecode;
}
// LCOV_EXCL_STOP
// -----------------------------------------------------------------------------
/**
  @brief Get user input integer

  @param[in] userPrompt  text for user prompt
  @param[out] input      user input integer

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int getUserInt(char *userPrompt, FILE *stream, int *input) {
  char *p, s[100];
  int n = 0;

  // Get user input with given prompt
  printf("%s", userPrompt);
  while (fgets(s, sizeof(s), stream)) {
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

  @param[in] userPrompt  text for user prompt
  @param[in] lower       lower end of range, inclusive
  @param[in] upper       upper end of range, inclusive
  @param[out] input      user input integer

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int getValidUserInt(char *userPrompt, FILE *stream, int lower, int upper,
                    int *input) {
  bool valid = false;

  // Loop until valid
  while (!valid) {
    getUserInt(userPrompt, stream, input);
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

  @param[in] userPrompt  text for user prompt
  @param[out] input      user input integer

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int getUserLong(char *userPrompt, FILE *stream, long *input) {
  char *p, s[100];
  long n = 0;

  // Get user input with given prompt
  printf("%s", userPrompt);
  while (fgets(s, sizeof(s), stream)) {
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

  @param[in] userPrompt  text for user prompt
  @param[in] lower       lower end of range, inclusive
  @param[in] upper       upper end of range, inclusive
  @param[out] input      user input integer

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int getValidUserLong(char *userPrompt, FILE *stream, long lower, long upper,
                     long *input) {
  bool valid = false;

  // Loop until valid
  while (!valid) {
    getUserLong(userPrompt, stream, input);
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
