// Given an integer n, return an array ans of length n + 1 such that for each i
// (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

#include <stdio.h>
#include <stdlib.h>

int *countBits(int n, int *returnSize) {
  int *res = (int *)malloc(sizeof(int) * (n + 1));
  for (int i = 0; i < n + 1; i++) {
    if (i == 0)
      res[i] = 0;
    else if (i == 1)
      res[i] = 1;
    else {
      int j = i;
      int t = 0;
      while (j > 1) {
        (j % 2 == 1) ? t++ : t + 0;
        j /= 2;
      }
      t++;
      res[i] = t;
    }
  }
  *returnSize = n + 1;
  return res;
}

int main() {
  int n = 2;
  int returnSize;
  int *result;
  result = countBits(n, &returnSize);

  printf("[");
  for (int i = 0; i < n + 1; i++) {
    if (i != n)
      printf("%d, ", result[i]);
    else
      printf("%d", result[i]);
  }
  printf("]\n");
  return 0;
}
