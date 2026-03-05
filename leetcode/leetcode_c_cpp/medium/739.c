/*
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to
wait after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.
*/

#include <stdio.h>
#include <stdlib.h>

int *dailyTemperatures_non_optimized(int *temperatures, int temperaturesSize,
                       int *returnSize) {
  int *answer = calloc(temperaturesSize, sizeof(int));
  int l = 0, r = 1;
  if (temperaturesSize == 1) {
    answer[0] = 0;
    *returnSize = temperaturesSize;
    return answer;
  }

  while (l < r && (l < temperaturesSize && r < temperaturesSize)) {
    printf(
        "Curr left idx %d with value %d and curr right idx %d with value %d\n",
        l, temperatures[l], r, temperatures[r]);

    if (temperatures[l] < temperatures[r]) {
      printf("l(idx %d) < r(idx %d) || %d < %d\n", l, r, temperatures[l],
             temperatures[r]);
      int days = r - l;
      answer[l] = days;
      l++;
      r = l + 1;
    } else if (temperatures[l] >= temperatures[r] && r >= temperaturesSize - 1) {
      printf("l(idx %d) > r(idx %d) || %d < %d\n", l, r, temperatures[l],
             temperatures[r]);
      answer[l] = 0;
      l++;
      r = l + 1;
      printf("L idx after check %d and R idx after check %d || Next idx after l %d\n", l, r, l + 1);
    } else if (temperatures[l] >= temperatures[r] && r <= temperaturesSize - 1) {
      r++;
    }
    if (l > temperaturesSize || r > temperaturesSize) {
      break;
    }
  }
  *returnSize = temperaturesSize;

  return answer;
}

int main() {
  int nSize = 10;
  int n[10] = {55,38,53,81,61,93,97,32,43,78};
  int rSize = 0;
  int *result = dailyTemperatures_non_optimized(n, nSize, &rSize);

  printf("==============\n");
  printf("Result size is %d\n", rSize);
  for (int i = 0; i < rSize; i++) {
    if (i == rSize - 1) {
      printf("%d\n", result[i]);
    } else {
      printf("%d -> ", result[i]);
    }
  }

  free(result);

  return 0;
}