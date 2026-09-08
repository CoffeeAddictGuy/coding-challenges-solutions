
#include <stdio.h>
#include <stdlib.h>
static int res = 0;

void highSum(char *line) {
  int i = 0;
  int f = 0;
  int s = 0;
  int fI = 0;
  int sI = 0;
  char t[3];
  while (line[i] != '\0') {
    if (line[i] - '0' > f) {
      f = line[i] - '0';
      fI = i;
    }
    i++;
  }
  i = 0;
  if (fI == 99) {
    while (i < 99) {
      if (line[i] - '0' > s) {
        s = line[i] - '0';
        sI = i;
      }
      i++;
    }
    t[0] = line[sI];
    t[1] = line[fI];
  } else if (fI > 99 - 12) {

  } else {
    i = fI + 1;
    while (line[i] != '\0') {
      if (line[i] - '0' > s) {
        s = line[i] - '0';
        sI = i;
      }
      i++;
    }
    t[0] = line[fI];
    t[1] = line[sI];
  }
  t[2] = '\0';
  printf("%d\n", atoi(t));
  res += atoi(t);
  // printf("\n");
}

int main() {
  FILE *file = fopen("adventofcode/2025/3day_secret.txt", "r");
  char line[101];

  if (file != NULL) {
    while (fgets(line, sizeof(line), file)) {
      highSum(line);
      // printf("\n");
    }
  } else {
    printf("Unable to open file\n");
  }
  printf("Result - %d\n", res);

  return 0;
}
