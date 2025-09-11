#include <stdio.h>

int main() {
    int sum = 0;
    int a = 3;
    int b = 5;
    for (int i = 1; i < 1000; i++) {
        if (i % a == 0 || i % b == 0) {
            sum += i;
        }
    }
    printf("%d", sum);
    return 0;
}