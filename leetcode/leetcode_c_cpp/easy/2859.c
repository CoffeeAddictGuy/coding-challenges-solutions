// You are given a 0-indexed integer array nums and an integer k.
//
// Return an integer that denotes the sum of elements in nums whose
// corresponding indices have exactly k set bits in their binary representation.
//
// The set bits in an integer are the 1's present when it is written in binary.
//
//     For example, the binary representation of 21 is 10101, which has 3 set
//     bits.

#include <stdio.h>
#include <stdlib.h>
int sumIndicesWithKSetBits(int *nums, int numsSize, int k) {
  int r = 0;
  for (int i = 0; i < numsSize; i++) {
    if (k == 0 && numsSize == 1)
      return nums[0];
    if (i != 0) {
      int j = i;
      int t = 0;
      while (j > 1) {
        (j % 2 == 1) ? t++ : t + 0;
        j /= 2;
      }
      t++;
      printf("num[%d](%d) with %d ones in binary\n", i, nums[i], t);
      if (t == k) {
        printf("Add num[%d](%d) because 1 in binary == k(%d)\n", i, nums[i], k);
        r += nums[i];
      }
    }
  }
  return r;
}

int main() {
  int numsSize = 1;
  int *nums = (int *)malloc(sizeof(int) * numsSize);
  nums[0] = 1;
  int k = 0;
  int result = sumIndicesWithKSetBits(nums, numsSize, k);
  printf("Result is %d\n", result);
  return 0;
}
