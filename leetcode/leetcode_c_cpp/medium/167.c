#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
  int l_c = 0;
  int r_c = numbersSize - 1;
  printf("l_c = %d and r_c = %d\n", numbers[0], numbers[numbersSize - 1]);
  while (true) {

    while (numbers[l_c] + numbers[r_c] > target) {
      printf("numbers[l_c] (%d) + numbers[r_c] (%d) > target (%d)\n",
             numbers[l_c], numbers[r_c], target);
      r_c--;
    }
    while (numbers[l_c] + numbers[r_c] < target) {
      printf("numbers[l_c] (%d) + numbers[r_c] (%d) < target (%d)\n",
             numbers[l_c], numbers[r_c], target);
      l_c++;
    }
    if (l_c >= r_c) {
      printf("l_c (%d) >= r_c (%d)\n", l_c, r_c);
      break;
    }
    if (numbers[l_c] + numbers[r_c] == target) {
      break;
    }
  }
  *returnSize = 2;
  int *n = malloc(sizeof(int) * 2);
  n[0] = l_c;
  n[1] = r_c;
  return n;
}

int main() {
  int first[4] = {2, 7, 11, 15};
  int second[3] = {2, 3, 4};
  int third[2] = {-1, 0};

  int returnSize = 0;
  printf("First test! \n");
  int *t = twoSum(first, 4, 9, &returnSize);
  for (size_t i = 0; i < returnSize; i++) {
    if (i == returnSize - 1) {
      printf("%d\n", first[t[i]]);
    } else {
      printf("%d + ", first[t[i]]);
    }
  }

  return 0;
}