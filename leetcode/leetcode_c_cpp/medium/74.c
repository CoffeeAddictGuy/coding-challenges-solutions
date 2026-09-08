#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize,
                  int target) {
  if (matrix[0][0] > target) {
    return false;
  }

  int curr = 0;

  size_t top = 0, bottom = matrixSize;
  while (top < bottom) {
    size_t mid = top + (bottom - top) / 2;
    curr = mid;
    printf("Mid curr %zu\n", mid);
    if (target == matrix[mid][0]) {
      curr = mid;
      break;
    }
    if (target > matrix[mid][0]) {
      top = mid + 1;
    } else {
      bottom = mid;
    }
  }

  size_t left = 0, right = *matrixColSize - 1;
  while (left <= right) {
    size_t mid = left + (right - left) / 2;
    if (matrix[curr][mid] == target) {
      return true;
    }
    if (target > matrix[curr][mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
}

void free_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int main() {
  int rows = 3, cols = 4;
  int **main = malloc(rows * sizeof(int *));

  for (int i = 0; i < rows; i++) {
    main[i] = malloc(cols * sizeof(int));
  }

  main[0][0] = 1;
  main[0][1] = 3;
  main[0][2] = 5;
  main[0][3] = 7;

  main[1][0] = 10;
  main[1][1] = 11;
  main[1][2] = 16;
  main[1][3] = 20;

  main[2][0] = 23;
  main[2][1] = 30;
  main[2][2] = 34;
  main[2][3] = 60;

  bool res = searchMatrix(main, rows, &cols, 3);
  printf("Result: %s", res ? "true" : "false");
  free_matrix(main, rows, cols);
  return 0;
}