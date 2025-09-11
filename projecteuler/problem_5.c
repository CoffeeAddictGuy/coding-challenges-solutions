#include <stdio.h>
#include <math.h>

int main() {
    int sqrt_hundred_sum = 0;
    int sqrt_sum_hundred = 0;

    for (int i = 1; i < 101; i++) {
        sqrt_hundred_sum += pow(i, 2);
    }

    for (int i = 1; i < 101; i++) {
        sqrt_sum_hundred += i;
    }
    printf("%d \n", sqrt_sum_hundred);
    sqrt_sum_hundred = pow(sqrt_sum_hundred, 2);

    int res = sqrt_sum_hundred -  sqrt_hundred_sum;
    printf("%d \n", res);
    printf("%d \n", sqrt_sum_hundred);
    return 0;
}