#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static int resZero = 0;
static int start = 50;
static void rOperation(int n);
static void lOperation(int n);

int main() {
  FILE *fptr;
  char line[10];
  fptr = fopen("adventofcode/2025/secret.txt", "r");
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
      int res = atoi(*test);
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
  int t = start + n;
  printf("%d + %d = %d\n", start, n, t);
  while (t > 99) {
    t -= 100;
  }
  start = t;
  printf("Start now is %d\n", start);
  if (t == 0)
    resZero++;
}

void lOperation(int n) {
  int t = (start - n) % 100;
  if (t < 10)
    t += 100;
  printf("%d - %d = %d\n", start, n, t);
  if (t < 0)
    t *= -1;
  while (t > 99) {
    t -= 100;
  }
  start = t;
  printf("Start now is %d\n", start);
  if (t == 0)
    resZero++;
}
