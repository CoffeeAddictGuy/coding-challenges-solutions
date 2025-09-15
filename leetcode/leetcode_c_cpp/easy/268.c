/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/
#include <stdlib.h>
#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    int sumAr = numsSize * (numsSize + 1) / 2;
    int res = sumAr - sum;
}

int main() {
    int array[] = {0,1};
    int size = 2;
    printf("Result - %d", missingNumber(array, size));
    return 0;
}