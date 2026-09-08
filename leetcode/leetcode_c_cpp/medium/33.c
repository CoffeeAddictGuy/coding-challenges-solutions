/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an
unknown index k (1 <= k < nums.length) such that the resulting array is
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
(0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and
become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <stdio.h>
int search(int *nums, int numsSize, int target) {
  if (target < nums[0] && target > nums[numsSize]) {
    return -1;
  }

  if (target == nums[0]) {
    return 0;
  } else if (target == nums[numsSize - 1]) {
    return numsSize - 1;
  }

  if (target < nums[0]) {
    printf("Left!\n");
    for (int i = numsSize - 1; i > 0; i--) {
        printf("Index %d: targer %d == nums[i] %d???\n", i, target, nums[i]);
      if (nums[i] == target) {
        printf("nums[i] %d\n", nums[i]);
        return i;
      }
    }
  }

  printf("Right!\n");
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == target) {
        return i;
    }
  }
  return -1;
}

int main() {
  int n = 2;
  int nums[2] = {1, 3};

  int target = 3;

  int result = search(nums, n, target);
  printf("Result is %d\n", result);

  return 0;
}