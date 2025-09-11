#include <stdio.h>

int main() {
    int sum = 0;
    int curr = 2;
    int pre = 1;
    sum += curr;

    while (curr + pre <= 4000000) {
        int next = curr + pre;

        if (next > 4000000) {
            break;
        }

        if (next % 2 == 0) {
            sum += next;
        }

        pre = curr;
        curr = next;
        }
    printf("%d", sum);
    return 0;
}