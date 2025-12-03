#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long res = 0;

bool isRepeating(long long x) {
  char buf[12];
  sprintf(buf, "%lld", x);
  int n = strlen(buf);
  if (n % 2 != 0)
    return false;

  printf("%s\n", buf);

  for (int i = 0; i < n / 2; i++) {
    int f = buf[i] - '0';
    int s = buf[i + n / 2] - '0';
    printf("[%d] and [%d]\n", f, s);
    if (f != s)
      return false;
  }
  return true;
}

void isValid(char *f, char *s, int fSize, int sSize) {
  long long from = atoll(f);
  long long to = atoll(s);
  for (long long x = from; x <= to; x++) {
    if (isRepeating(x)) {
      // printf("REPEATING!");
      res += x;
    }
  }
}

void printFile(FILE *p) {
  char c;
  while ((c = fgetc(p)) != EOF) {
    if (c == ',')
      printf("\n");
    else
      printf("%c", c);
  }
}

int main() {
  FILE *pFile;
  char c;
  char fNum[12];
  char sNum[12];
  int fCnt = 0;
  int sCnt = 0;
  int s = 0;
  pFile = fopen("adventofcode/2025/2day_secret.txt", "r");
  if (pFile != NULL) {
    // printFile(pFile);
    while ((c = fgetc(pFile)) != EOF) {
      if (isdigit(c)) {
        if (s == 0) {
          fNum[fCnt] = c;
          fCnt++;
        } else {
          sNum[sCnt] = c;
          sCnt++;
        }
      } else if (c == '-') {
        s = 1;
      } else {
        fNum[fCnt++] = '\0';
        sNum[sCnt++] = '\0';
        isValid(fNum, sNum, fCnt - 1, sCnt - 1);
        fCnt = 0;
        fNum[0] = '\0';
        sCnt = 0;
        sNum[0] = '\0';
        s = 0;
      }
    }
    printf("File opened\n");
  } else {
    printf("File not opened\n");
  }
  pclose(pFile);
  printf("Answer is - %lld\n", res);
  return 0;
}
