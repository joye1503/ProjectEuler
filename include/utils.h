#ifndef UTILS_H
#define UTILS_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// -----------------------------------------------------------------------------
// Interface utilites
// -----------------------------------------------------------------------------
int getUserInt(char *userPrompt, int *input);
int getValidUserInt(char *userPrompt, int lower, int upper, int *input);
int getUserLong(char *userPrompt, long *input);
int getValidUserLong(char *userPrompt, long lower, long upper, long *input);

// -----------------------------------------------------------------------------
// Math utilities
// -----------------------------------------------------------------------------
int intMin(int a, int b);
int intMax(int a, int b);
long longMin(long a, long b);
long longMax(long a, long b);
int calculateGCD(int a, int b, int *result);
int calculateLCM(int a, int b, int *result);
int isPrime(int number, bool *prime);
int isPrimeLong(long number, bool *prime);

#endif
