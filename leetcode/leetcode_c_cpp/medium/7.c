/*
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range
[-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or
unsigned).
*/
#include <limits.h>
#include <math.h>
#include <stdio.h>

int reverse(int x) {
  int n = 0;
  long long t = x;
  if (x < 0) {
    t = (long long)x * -1;
    if (t > INT_MAX || t < INT_MIN) {
      return 0;
    }
    x = (int)t;
    n = 1;
  }

  int radix = floor(log10(x)) + 1;
  if (radix == 0) {
    return x;
  }

  int result = 0;
  int mul = 1;
  for (int i = 0; i < radix; i++) {
    int num = (int)(x / pow(10, radix - 1 - i)) % 10;

    if (num > INT_MAX / mul || result > INT_MAX - num * mul) {
      return 0;
    }
    result += num * mul;
    if (i != radix - 1) {
      mul *= 10;
    }
  }
  if (n == 1) {
    result *= -1;
  }
  return result;
}

int main() {
  int x = 1563847412;

  int res = reverse(x);
  printf("Result - %d\n", res);
  printf("-2143847412\n");
  printf("%d\n", INT_MAX);
  return 0;
}