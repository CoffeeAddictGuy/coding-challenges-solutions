/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

#include <mylittlelib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool containsDuplicate_TLE(int* nums, int numsSize) {
    if (numsSize < 2)
        return false;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 1; j < numsSize; j++) {
            if (j == i) 
                break;
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

bool containsDuplicate(int* nums, int numsSize) {

}

int main() {
    srand(time(NULL));
    int arraySize = (rand() % 20) + 1;
    int* nums = malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++) {
        nums[i] = rand() % 10 + 1;
    }
    printArray(nums, arraySize);
    printf("Result - %d", containsDuplicate(nums, arraySize));
    return 0;
}