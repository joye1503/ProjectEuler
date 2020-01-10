#ifndef EULER_H
#define EULER_H
#include <math.h>

#define NUM_PROBLEMS 7

// -----------------------------------------------------------------------------
// Solution code
// -----------------------------------------------------------------------------
int problem001(long a, long b, long limit, long *sum);
int problem002(long a, long limit, long *sum);
int problem003(long number, long *factor);
int problem004(int digits, long *palindrome);
int problem005(int limit, long *lcm);
int problem006(int limit, long *difference);
int problem007(int n, long *prime);

// -----------------------------------------------------------------------------
// Command line interfaces
// -----------------------------------------------------------------------------
typedef int funcPtr(FILE *stream);
funcPtr problem001CL, problem002CL, problem003CL, problem004CL, problem005CL,
        problem006CL, problem007CL;

funcPtr *problems[NUM_PROBLEMS] = {
  problem001CL,
  problem002CL,
  problem003CL,
  problem004CL,
  problem005CL,
  problem006CL,
  problem007CL
};

#endif
