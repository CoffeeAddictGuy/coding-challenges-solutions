/*
7. Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
*/

#include <stdlib.h>
#include <stdio.h>
#include <mylittlelib.h>

int reverse(int x){
    if (x == 0)
        return x;
    int neg = 0;
    if (x < 0) {
        neg = 1;
        x *= -1;
    }
    int res = 0;
    int rad = getRadix(x)-1;
    
    while (x != 0) {
        int digit = x % 10;
        if (res > INT_MAX/10 || (res == INT_MAX/10 && digit > 7)) return 0;
        if (res < INT_MIN/10 || (res == INT_MIN/10 && digit < -8)) return 0;
        res += digit * pow(10, rad);
        x /= 10;
        rad--;
    }

    if (neg != 0)
        res *= -1;
    return res;
}

int main() {
    int num = 1534236469;
    printf("Res - %d", reverse(num));
    return 0;
}