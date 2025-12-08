#include <corecrt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector3 {
  int x;
  int y;
  int z;
} Vector3;

typedef struct Pair {
  Vector3 a;
  Vector3 b;
  int euclid_distance;
} Pair;

int main() {
  FILE *pFile;
  errno_t err;
  char line[19];
  Vector3 cubes[1000];
  Pair couple[499500];
  int i = 0;
  err = fopen_s(&pFile, "8day_secret.txt", "r");

  if (err == 0) {
    while (fgets(line, sizeof(line), pFile)) {

      char *pch;
      char *next_token;
      pch = strtok_s(line, ",", &next_token);
      int x, y, z = 0;
      int j = 0;
      while (pch) {
        if (j == 0) {
          x = atoi(pch);
        } else if (j == 1) {
          y = atoi(pch);
        } else if (j == 2) {
          z = atoi(pch);
        }
        pch = strtok_s(NULL, ",", &next_token);
        j++;
      }
      cubes[i] = (Vector3){x, y, z};
      i++;
      printf("\n");
    }

    for (int i = 0; i < 1000; i++) {
      printf("Cube cord - x:%d, y:%d, z:%d\n", cubes[i].x, cubes[i].y,
             cubes[i].z);
    }
    int idx = 0;
    for (int a = 0; a < 1000; a++) {
      for (int b = a + 1; b < 1000; b++) {
        int dx = cubes[a].x - cubes[b].x;
        int dy = cubes[a].y - cubes[b].y;
        int dz = cubes[a].z - cubes[b].z;
        int euclid_distance = dx * dx + dy * dy + dz * dz;
        couple[idx++] = (Pair){cubes[a], cubes[b], euclid_distance};
      }
    }

    // for (int i = 0; i < 499500; i++) {
    //   printf("Pair A(%d,%d,%d) and B(%d,%d,%d) has euclid_distance = %d",
    //          couple[i].a.x, couple[i].a.y, couple[i].a.z, couple[i].b.x,
    //          couple[i].b.y, couple[i].b.z, couple[i].euclid_distance);
    // }

  } else {
    printf("Unable to open file!");
  }

  fclose(pFile);
}