/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    if (numsSize == 1) 
        return nums[0];
    double current_sum = 0;
    if (k == numsSize) {
        for (int i = 0; i < numsSize; i++) {
            current_sum += nums[i];
        }
        return current_sum/k;
    }
    current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += nums[i];
    }
    double max_sum = current_sum;
    for (int i = k; i < numsSize; i++) {
        current_sum += nums[i] - nums[i - k];
        if (current_sum > max_sum)
            max_sum = current_sum;
    }
    return max_sum/k; 
}

int main() {
    int nums[] = { 1,12,-5,-6,50,3 };
    int k = 4;
    int numsSize = 6;
    printf("Res - %f\n", findMaxAverage(nums, numsSize, k));
    return 0;
}