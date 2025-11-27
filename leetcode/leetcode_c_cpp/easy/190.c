
// Reverse bits of a given 32 bits signed integer.

#include <mylittlelib.h>
#include <stdio.h>
#include <stdlib.h>

int reverseBits(int n) {

  int t = n;
  char *res = (char *)malloc(32 + 1);
  int cnt = 0;
  while (t > 1) {
    res[cnt] = t % 2 + '0';
    t /= 2;
    cnt++;
    if (t == 1) {
      res[cnt] = 1 + '0';
      cnt++;
    }
  }
  res[cnt] = '0';
  int result = 0;
  int f = 2;

  for (int i = 1; i < 32 - cnt; i++) {
    res[cnt + i] = '0';
  }
  cnt += 32 - cnt;

  for (int i = 0; i < cnt; i++) {
    // printf("%d", res[i] - '0');
    if (res[i] - '0' == 1) {
      int pow = cnt - i - 1;
      int temp = (res[i] - '0') * fastPow(&f, &pow);
      result += temp;
    }
  }
  return result;
}

int main() {
  int n = 43261596;
  int res;
  printf("NUM - %d\n", n);
  res = reverseBits(n);
}
