#include "utils.h"

/* Project Euler Problem 1:

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/
int problem1(void) {
  int a, b, limit;

  // Get a, b, and limit
  printf("This code finds the sum of all the multiples of [a] or [b]\n  below "
         "[limit].\n");
  getUserInt("Enter a: ", &a);
  getUserInt("Enter b: ", &b);
  getUserInt("Enter limit: ", &limit);

  // Find sum of multiples
  int sum = 0;

  // Multiples of a
  for (int i=a; i<limit; i+=a)
      sum += i;

  // Multiples of b
  for (int i=b; i<limit; i+=b)
    if (i%a)
      sum += i;

  printf("Sum of multiples of %d or %d below %d: %d\n", a, b, limit, sum);

  return 0;
};
