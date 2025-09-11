#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mylittlelib.h>

int addDigits(int num) {
    if (num < 10)
        return num;
    int res = 0;
    for (int i = 0; i < getRadix(num); i++) {
        res += getAnyNumberByIndex(num, i, 10);
    }
    return addDigits(res);
}

int main() {
    int num = 38;
    printf("Result - %d\n", addDigits(num));
    return 0;
}