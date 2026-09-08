#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

struct binary {
  char num[64];
  int len;
};

double old_myPow(double x, int n) {
  if (n == 0 || x == 1) {
    return 1;
  }

  double result = x;
  int steps = n;
  bool mode = false;

  if (steps < 0) {
    mode = true;
    steps *= -1;
  }

  for (int i = 1; i < steps; i++) {
    result *= x;
  }

  if (mode) {
    result = 1 / result;
  }

  return result;
}

struct binary d_to_b(long long n) {
  char main[64];
  struct binary result = {0};

  int k = 0;
  long long num = n;

  while (num > 1) {
    result.num[k] = num % 2 + '0';
    num /= 2;
    k++;

    if (num == 1) {
      result.num[k] = 1 + '0';
      k++;
    }
  }
  result.num[k] = 0;
  result.len = k;

  return result;
}

double good_myPow(double x, int n) {
  if (n == 0 || x == 1) {
    return 1;
  }

  double result = 1;

  long long steps = n;
  bool mode = false;

  if (steps < 0) {
    mode = true;
    steps *= -1;
  }

  if (steps == 1 && mode) {
    return 1 / x;
  } else if (steps == 1 && !mode) {
    return x;
  }

  struct binary b = d_to_b(steps);
  for (int i = b.len - 1; i >= 0; i--) {
    if (b.num[i] == '0') {
      result = result * result;
    } else {
      result = (result * result) * x;
    }
  }

  if (mode) {
    result = 1 / result;
  }

  return result;
}

double myPow(double x, int n) {
  if (n == 0 || x == 1) {
    return 1;
  }

  double result = 1;

  long steps = n;
  bool mode = false;

  if (steps < 0) {
    mode = true;
    steps *= -1;
  }

  if (steps == 1 && mode) {
    return 1 / x;
  } else if (steps == 1 && !mode) {
    return x;
  }

  double z = x;
  while (steps > 1) {
    int t = steps % 2;
    steps /= 2;
    if (t == 0) {
      z *= z;
    } else {
      result *= z;
      z *= z;
    }

    if (steps == 1) {
      t = 1;

      if (t == 0) {
        z *= z;
      } else {
        result *= z;
        z *= z;
      }
    }
  }

  if (mode) {
    result = 1 / result;
  }

  return result;
}

int main() {
  printf("OLD Result is %f\n", old_myPow(2, 10));
  printf("OLD Result is %f\n", old_myPow(2.1, 3));
  printf("OLD Result is %f\n", old_myPow(2, -2));
  printf("OLD Result is %f\n", old_myPow(8.84372, -5));
  printf("OLD Result is %f\n", old_myPow(8.95371, -1));
  printf("OLD Result is %f\n", old_myPow(2, -2147483648));

  printf("--------------\n");

  printf("GOOD Result is %f\n", good_myPow(2, 10));
  printf("GOOD Result is %f\n", good_myPow(2.1, 3));
  printf("GOOD Result is %f\n", good_myPow(2, -2));
  printf("GOOD Result is %f\n", good_myPow(8.84372, -5));
  printf("GOOD Result is %f\n", good_myPow(8.95371, -1));
  printf("GOOD Result is %f\n", good_myPow(2, -2147483648));

  printf("--------------\n");

  printf("Result is %f\n", myPow(2, 10));
  printf("Result is %f\n", myPow(2.1, 3));
  printf("Result is %f\n", myPow(2, -2));
  printf("Result is %f\n", myPow(8.84372, -5));
  printf("Result is %f\n", myPow(8.95371, -1));
  printf("Result is %f\n", myPow(2, -2147483648));
  return 0;
}