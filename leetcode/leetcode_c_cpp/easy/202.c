// Write an algorithm to determine if a number n is happy.
//
// A happy number is a number defined by the following process:
//
//     Starting with any positive integer, replace the number by the sum of the
//     squares of its digits. Repeat the process until the number equals 1
//     (where it will stay), or it loops endlessly in a cycle which does not
//     include 1. Those numbers for which this process ends in 1 are happy.
//
// Return true if n is a happy number, and false if not.

#include <math.h>
#include <mylittlelib.h>
#include <stdbool.h>
#include <stdio.h>

static int check[1] = {-1};

bool isHappy(int n) {
  if (n == 1 || n == 10)
    return true;
  else if (n < 10)
    return false;
  else {
    int rad = getRadix(n);
    int res = 0;
    for (int i = 0; i < rad; i++) {
      if (i != rad - 1)
        printf("%d ^ 2 + ", getAnyNumberByIndex(n, i, 10));
      else
        printf("%d ^ 2", getAnyNumberByIndex(n, i, 10));
      res += pow(getAnyNumberByIndex(n, i, 10), 2);
    }
    printf(" = %d\n", res);
    return isHappy(res);
  }
}

int main() {
  int n = 7;
  bool res = isHappy(n);
  (res) ? printf("Number %d is happy\n", n)
        : printf("Number %d isn't happy\n", n);
}
