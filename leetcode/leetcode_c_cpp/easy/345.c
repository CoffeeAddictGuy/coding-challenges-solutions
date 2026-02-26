/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower
and upper cases, more than once.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *reverseVowels(char *s) {
  int size = strlen(s);

  int left = 0, right = size - 1;
  int l_m = 0, r_m = 0;

  while (left < right) {
    if ((s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' ||
         s[left] == 'u' || s[left] == 'A' || s[left] == 'E' || s[left] == 'I' ||
         s[left] == 'O' || s[left] == 'U') &&
        l_m != 1) {
      l_m = 1;
    }

    if ((s[right] == 'a' || s[right] == 'e' || s[right] == 'i' ||
         s[right] == 'o' || s[right] == 'u' || s[right] == 'A' ||
         s[right] == 'E' || s[right] == 'I' || s[right] == 'O' ||
         s[right] == 'U') &&
        r_m != 1) {
      r_m = 1;
    }

    if (l_m == 1 && r_m == 1) {
      printf("Swap %c and %c\n", s[left], s[right]);
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      l_m = 0;
      r_m = 0;
    }

    if (l_m == 0) {
      left++;
    }
    if (r_m == 0) {
      right--;
    }
  }

  return s;
}

int main() {
  char test[8] = "leetcode";
  printf("Main - %s\n", test);
  char *result = reverseVowels(test);
  printf("Result %s\n", result);

  return 0;
}