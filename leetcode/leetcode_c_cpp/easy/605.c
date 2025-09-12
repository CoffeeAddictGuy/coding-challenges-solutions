/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, 
return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printFlowerBed(int* flowerbed, int flowerbedSize) {
    for (int i = 0; i < flowerbedSize; i++) {
        printf("%d - ", flowerbed[i]);
    }
    printf("\n");
}

int plantedFlowersCount(int* flowerbed, int flowerbedSize) {
    int res = 0;
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 2)
            res += 1;
    }
    return res;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (flowerbedSize == 1 && flowerbed[0] == 0 && n == 1)
        return true;
    else if (flowerbedSize == 1 && flowerbed[0] == 0 && n > 1)
    {
        return true;
    }
    
    if (plantedFlowersCount(flowerbed, flowerbedSize) == n)
        return true;
    printFlowerBed(flowerbed, flowerbedSize);
    for (int i = 0; i < flowerbedSize; i++) {
        if (i == 0) { //first one
            if (flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 2;
                return canPlaceFlowers(flowerbed, flowerbedSize, n);
            }
        }
        else if (i == flowerbedSize-1) { //last one
            if (flowerbed[i] == 0 && flowerbed[i-1] == 0) {
                flowerbed[i] = 2;
                return canPlaceFlowers(flowerbed, flowerbedSize, n);
            }
        }

        else if (flowerbed[i] != 1 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] != 2 && i != 0 && i != flowerbedSize-1) {
            flowerbed[i] = 2;
            return canPlaceFlowers(flowerbed, flowerbedSize, n);
        }
    }
    return false;
}

int main() {
    int flowerbed1[] = {1,0,0,0,1,0,0};
    int flowerbed2[] = {1,0,0,0,1};
    int n = 1;
    bool res = canPlaceFlowers(flowerbed1, 7, 2);
    printf("Result - %d", res);
    return 0;
}