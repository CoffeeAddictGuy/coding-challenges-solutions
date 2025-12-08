#include <corecrt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE* pFile;
    errno_t err;
    err = fopen_s(&pFile, "7day_secret.txt", "r"); //Try secure version of fopen.

    if (err == 0) {
        char c;
        int map[142][141];
        int row = 0;
        int col = 0;
        while ((c = fgetc(pFile)) != EOF) {
            if (c == '\0' || c == '\n') {
                row++;
                col = 0;
                //printf("End of line");
            } else if (c == '.') {
                map[row][col] = 0;
                col++;
            } else if (c == 'S') {
                map[row][col] = 1;
                col++;
            } else if (c == '^') {
                map[row][col] = 2;
                col++;
            }
            // printf("%c", c);
        } 
        int res = 0;

        for (int i = 0; i < 142; i++) {
            for (int j = 0; j < 141; j++) {
                if ((i > 0 || i == 141) && map[i - 1][j] == 1 && map[i][j] == 0) {
                    map[i][j] = 1;
                } else if (map[i][j] == 2 && map[i - 1][j] == 1) {
                    res += 1;
                    map[i][j - 1] = 1;
                    map[i][j + 1] = 1;
                }
                printf("%d", map[i][j]);
            }
            printf("\n");
        }
        printf("Result - %d\n", res);
    } else {
        printf("Unable to open file!");
    }
}