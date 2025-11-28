// Given a positive integer n, write a function that returns the number of in
// its binary representation (also known as the Hamming weight).

#include <stdio.h>
int hammingWeight(int n) {
  int t = 0;
  while (n > 1) {
    (n % 2 == 1) ? t++ : t + 0;
    n /= 2;
  }
  t++;
  return t;
}

int main() {
  int n = 2147483645;
  int res = hammingWeight(n);
  printf("Result - %d\n", res);
}
