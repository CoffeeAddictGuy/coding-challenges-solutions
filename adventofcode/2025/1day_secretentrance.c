#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int resZero = 0;
static int start = 50;
static void rOperation(int n);
static void lOperation(int n);

int main() {
  FILE *fptr;
  char line[10];
  fptr = fopen("adventofcode/2025/1day_secret.txt", "r");
  if (fptr != NULL) {
    while (fgets(line, sizeof(line), fptr)) {
      int c = 0;
      printf("%s", line);
      for (int i = 0; i < sizeof(line); i++) {
        if (isalpha(line[i]))
          printf("[%c]", line[i]);
        if (isdigit(line[i])) {
          c++;
          printf("[%d]", line[i] - '0');
        }
      }
      printf("\n");
      char *test[c];
      for (int i = 1; i <= c; i++) {
        test[i - 1] = &line[i];
      }
      int res = atoi(*test + 1);
      printf("Test - %d\n", res);

      if (line[0] == 'R') {
        rOperation(res);
        printf("RIGHT ROTATION\n");
      } else {
        lOperation(res);
        printf("LEFT ROTATION\n");
      }
    }
    fclose(fptr);
  } else {
    fprintf(stderr, "Unable to open file\n");
  }

  printf("Answer is - %d\n", resZero);
  return 0;
}

void rOperation(int n) {
  int old = start;
  int dist = n;
  resZero += (old + dist) / 100;

  start = (old + dist) % 100;
}

void lOperation(int n) {
  int old = start;
  int dist = n;

  int to = old - dist;

  if (to < 0) {
    resZero += (-to) / 100 + 1;
  }

  start = (to % 100 + 100) % 100;
}
