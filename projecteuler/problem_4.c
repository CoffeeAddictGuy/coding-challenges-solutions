#include <stdio.h>
#include <stdbool.h>

int main() {
    int res = 1;
    bool loop = true;
    while (loop == true) {
        if (res % 1 == 0 && res % 2 == 0 &&
            res % 3 == 0 && res % 4 == 0 &&
            res % 5 == 0 && res % 6 == 0 &&
            res % 7 == 0 && res % 8 == 0 &&
            res % 9 == 0 && res % 10 == 0 &&
            res % 11 == 0 && res % 12 == 0 &&
            res % 13 == 0 && res % 14 == 0 &&
            res % 15 == 0 && res % 16 == 0 &&
            res % 17 == 0 && res % 18 == 0 &&
            res % 19 == 0 && res % 20 == 0) {
                printf("%d", res);
                loop = false;
            }
        res += 1;
    }
    return 0;
}