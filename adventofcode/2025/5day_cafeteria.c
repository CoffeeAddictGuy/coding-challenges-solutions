#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  FILE *file;
  char line[34];
  long long *n = (long long *)malloc(sizeof(long long) * 1000);
  file = fopen("adventofcode/2025/5day_secret.txt", "r");
  int sMode = 0;
  int c = 0;
  int fresh = 0;
  char *tL = line;
  if (file != NULL) {
    while (fgets(line, sizeof(line), file)) {
      if (line[0] == '\n' || line[0] == '\0') {
        sMode = 1;
        printf("LINE IS BLANK\n");
      } else if (sMode == 1) {
        n[c] = atoll(line);
        c++;
      }
    }
    fseek(file, 0, SEEK_SET);
    while (fgets(line, sizeof(line), file)) {
      if (line[0] == '\n' || line[0] == '\0') {
        break;
      }
      long long f = 0;
      long long s = 0;
      char *token = strtok(line, "-");
      while (token != NULL) {
        printf("%s\n", token);
        if (f == 0)
          f = atoll(token);
        else
          s = atoll(token);
        token = strtok(NULL, "-");
      }
      // s = atoll(token);
      printf("%lld and %lld\n", f, s);
      for (int i = 0; i < 1000; i++) {
        if (n[i] >= f && n[i] <= s) {
          printf("ID %lld fresh because in %lld - %lld diaposon\n", n[i], f, s);
          fresh++;
          n[i] = 0;
        } else {
          printf("ID %lld not fresh because not in %lld - %lld diaposon\n",
                 n[i], f, s);
          // fresh++;
        }
      }
    }
  } else {
    printf("Unable to open file");
  }
  printf("Result - %d\n", fresh);
  fclose(file);
  free(n);
  return 0;
}
