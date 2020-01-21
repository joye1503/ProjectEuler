#ifndef UTILS_H
#define UTILS_H
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

// -----------------------------------------------------------------------------
// Error handling
// -----------------------------------------------------------------------------

#define ErrChk(ierr) do { if (ierr) return ierr; } while (0)
#define Error(ecode, ...)                                     \
  (ErrorExit(__FILE__, __LINE__, __func__, (ecode), __VA_ARGS__) ?: (ecode))
int ErrorExit(const char *filename, int lineno, const char *func, int ecode,
              const char *format, ...);

// -----------------------------------------------------------------------------
// Interface utilites
// -----------------------------------------------------------------------------
int getUserInt(char *userPrompt, FILE *stream, int *input);
int getValidUserInt(char *userPrompt, FILE *stream, int lower, int upper,
                    int *input);
int getUserLong(char *userPrompt, FILE *stream, long *input);
int getValidUserLong(char *userPrompt, FILE *stream, long lower, long upper,
                     long *input);

// -----------------------------------------------------------------------------
// Math utilities
// -----------------------------------------------------------------------------
long longMin(long a, long b);
long longMax(long a, long b);
long longPow(long base, long power);
int calculateGCD(long a, long b, long *result);
int calculateLCM(long a, long b, long *result);
int isPrime(long number, bool *primality);
int isPrimeFallback(long number, bool *primality);
int isPalindrome(long number, bool *palindrome);

#endif
