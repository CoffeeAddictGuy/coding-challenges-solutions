#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE* pFile;
    char line[3742];
    int row = 0;
    int col = 0;
    pFile = fopen("6day_secret.txt", "r");

    int n[4][1000];
    int command[1000];

    if (pFile != NULL) {
        while (fgets(line, sizeof(line), pFile)) {
            char *pch;
            pch = strtok(line, " ");
            while (pch!=NULL) {
                if (pch[0] == '*') {
                    command[col] = 1;
                    col++;
                    pch = strtok(NULL, " ");
                } else if (pch[0] == '+') {
                    command[col] = 0;
                    col++;
                    pch = strtok(NULL, " ");
                } else {
                    n[row][col] = atoi(pch);
                    col++;
                    pch = strtok(NULL, " ");
                }
            }
            row++;  
            col = 0;          
        }

        long long res = 0;
        for (int j = 0; j < 1000; j++) {
            long long  tResSum = 0;
            long long tResMul = 1;
            for (int i = 0; i < 4; i++) {
                if (command[j] == 1) {
                    printf("%lld * %lld", tResMul, n[i][j]);
                    tResMul *= n[i][j];
                    printf("= %lld\n", tResMul);
                } else if (command[j] == 0) {
                    printf("%lld + %lld", tResSum, n[i][j]);
                    tResSum += n[i][j];
                    printf("= %lld\n", tResSum);
                }
            }
            if (command[j] == 1) {
                res += tResMul;
            } else if (command[j] == 0)
            {
                res += tResSum;
            }
        }
        printf("Result - %lld\n", res);
        printf("Long long max value - %lld", LLONG_MAX);
        
    } else {
        printf("Unable to open file!");
    }

    return 0;
}