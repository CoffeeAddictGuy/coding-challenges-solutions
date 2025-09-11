#include <stdlib.h>
#include <stdio.h>


int haveZero(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            return 1;
    }
    return 0;
}
int isZeroEnd(int* nums, int numsSize, int* zeroIndex) {
    int firstZero = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            firstZero = i;
            break;
        }
    }
    for (int i = firstZero; i < numsSize; i++) {
        if (nums[i] != 0) {
            *zeroIndex = firstZero;
            return 0;
        } 
    }
    return 1;
}

void moveZeroes(int* nums, int numsSize) {
    if (numsSize <= 1)
        return;
    int zeroIndex = 0;
    int temp = 0;
    printf("Index - %d", zeroIndex);
    if (isZeroEnd(nums, numsSize, &zeroIndex) == 0 && haveZero(nums, numsSize) == 1) {
        for (int i = zeroIndex; i < numsSize - 1; i++) {
            temp = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = temp;
        }
        moveZeroes(nums, numsSize);
    } else {
        return;
    }
}

int main() {
    int numsSize = 2;
    int nums1[] = {2, 1};
    int nums2[] = {1, 5, 5, 0, 0};
    printf("Array before:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");
    moveZeroes(nums1, numsSize);
    printf("Array after:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums1[i]);
    }
    return 0;
}