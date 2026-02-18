/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this: (you may want to display this pattern in a fixed font for better
legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number
of rows:

string convert(string s, int numRows);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows) {
  if (numRows == 1) {
    return s;
  }

  int len = strlen(s);
  char *res = (char *)malloc(sizeof(char) * len + 1);
  int idx = 0;
  for (int i = 0; i < numRows; i++) {
    for (int j = i; j < len; j += 2 * (numRows - 1)) {
        res[idx++] = s[j];
        if (i > 0 && i < numRows - 1 && j + 2 * (numRows - 1) - 2 * i < len) {
            res[idx++] = s[j + 2 * (numRows - 1) - 2 * i];
        }
    }
  }
  return res;
}

int main() {
  char *text = "PAYPALISHIRING";
  int rowNum = 3;
  char *result = convert(text, rowNum);

  printf("Result - %s\n", result);
    //PAHNA L I GYIR
    //PAHNAPLSIIGYIR
    //PAHNAPLSIIGYIR
  return 0;
}