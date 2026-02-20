/*
Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

#include <stdio.h>
#include <stdlib.h>
int *searchRange(int *nums, int numsSize, int target, int *returnSize) {

  *returnSize = 2;
  int *result = malloc(sizeof(int) * *returnSize);
  result[0] = -1;
  result[1] = -1;

  if (numsSize == 0) {
    return result;
  }

  if (target < nums[0] && target > nums[numsSize - 1]) {
    return result;
  }

  int left = 0, right = numsSize - 1;

  while (left < right) {
    printf("Left %d and Right %d\n%d %d\n", left, right, nums[left],
           nums[right]);
    if (nums[left] == target && result[0] == -1) {
      printf("Left equls target!\n");
      result[0] = left;
    } else if (result[0] == -1) {
      left++;
    }
    if (nums[right] == target && result[1] == -1) {
      printf("Right equls target!\n");
      result[1] = right;
    } else if (result[1] == -1) {
      right--;
    }

    if (result[0] != -1 && result[1] != -1) {
      break;
    }
  }

  printf("Left %d and Right %d\n%d %d\n", left, right, nums[left], nums[right]);

  if (left == right && nums[left] == target) {
    result[0] = left;
    result[1] = left;
  }

  return result;
}

int main() {
  int n = 3;
  int nums[3] = {1, 2, 3};

  int target = 1;

  int resultSize = 0;
  int *result = searchRange(nums, n, target, &resultSize);

  for (int i = 0; i < resultSize; i++) {
    if (i == resultSize - 1) {
      printf("%d\n", result[i]);
    } else {
      printf("%d -> ", result[i]);
    }
  }

  return 0;
}