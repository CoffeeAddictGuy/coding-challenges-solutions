#include <stddef.h>
#include <stdio.h>
#include <string.h>

static int res = 0;

void forklifsChecker(int map[137][137]) {
  int t = 0;
  for (int i = 0; i < 137; i++) {
    for (int j = 0; j < 137; j++) {
      // corner
      if (i == 0 && j == 0) { // left upper
        if (map[i][j] == 1) {
          if (map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j] < 4) {
            res += 1;
            map[i][j] = 0;
            t = 1;
          }
        }
        printf("[%d]", map[i][j]);
      } else if (i == 136 && j == 0) { // left bottom
        if (map[i][j] == 1) {
          if (map[i - 1][j] + map[i - 1][j + 1] + map[i][j + 1] < 4) {
            res += 1;
            map[i][j] = 0;
            t = 1;
          }
        }
        printf("[%d]", map[i][j]);
      } else if (i == 0 && j == 136) { // right upper
        if (map[i][j] == 1) {
          if (map[i + 1][j] + map[i + 1][j - 1] + map[i][j - 1] < 4) {
            res += 1;
            map[i][j] = 0;
            t = 1;
          }
        }
        printf("[%d]", map[i][j]);
      } else if (i == 136 && j == 136) { // right bottom
        if (map[i][j] == 1) {
          if (map[i][j - 1] + map[i - 1][j - 1] + map[i - 1][j] < 4) {
            res += 1;
            map[i][j] = 0;
            t = 1;
          }
        }
        printf("[%d]", map[i][j]);
      }
      // left wall
      else if (j == 0 && (i != 0 || i != 136)) {
        if (map[i][j] == 1) {
          if (map[i - 1][j] + map[i - 1][j + 1] + map[i][j + 1] +
                  map[i + 1][j + 1] + map[i + 1][j] <
              4) {
            res += 1;
            map[i][j] = 0;
            t = 1;
          }
        }
        printf("[%d", map[i][j]);
      }
      // right wall
      else if (j == 136 && (i != 0 || i != 136)) {
        if (map[i][j] == 1) {
          if (map[i + 1][j] + map[i + 1][j - 1] + map[i][j - 1] +
                  map[i - 1][j - 1] + map[i - 1][j] <
              4) {
            res += 1;
            map[i][j] = 0;
            t = 1;
          }
        }
        printf("%d]", map[i][j]);
      }
      // upper
      else if (i == 0 && (j != 0 || j != 136)) {
        if (map[i][j] == 1) {
          if (map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j] +
                  map[i + 1][j - 1] + map[i][j - 1] <
              4) {
            res += 1;
            map[i][j] = 0;
            t = 1;
          }
        }
        printf("%d", map[i][j]);
      }
      // bottom
      else if (i == 136 && (j != 0 || j != 136)) {
        if (map[i][j] == 1) {
          if (map[i][j - 1] + map[i - 1][j - 1] + map[i - 1][j] +
                  map[i - 1][j + 1] + map[i][j + 1] <
              4) {
            res += 1;
            map[i][j] = 0;
            t = 1;
          }
        }
        printf("%d", map[i][j]);
      } else {
        if (map[i][j] == 1) {
          if (map[i - 1][j] + map[i - 1][j + 1] + map[i][j + 1] +
                  map[i + 1][j + 1] + map[i + 1][j] + map[i + 1][j - 1] +
                  map[i][j - 1] + map[i - 1][j - 1] <
              4) {
            res += 1;
            map[i][j] = 0;
            t = 1;
          }
        }
        printf("%d", map[i][j]);
      }
    }
    printf("\n");
  }
  if (t == 1)
    forklifsChecker(map);
  return;
}

int main() {
  FILE *file;
  char line[138];
  file = fopen("adventofcode/2025/4day_secret.txt", "r");

  int map[137][137];
  int row = 0;
  int k = 0;
  if (file != NULL) {
    while (fgets(line, sizeof(line), file)) {
      size_t len = strlen(line);
      if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
        len--;
      }

      if (len == 0)
        continue;
      if (len != 137)
        continue;

      if (strlen(line) == 137) {
        for (int i = 0; i < 137; i++) {
          map[row][i] = (line[i] == '@') ? 1 : 0;
        }
      }
      row++;
    }
  } else {
    printf("Unable to open file\n");
  }
  printf("\n\n");
  printf("-------------------------------------\n");
  forklifsChecker(map);
  printf("Result - %d\n", res);
  return 0;
}
