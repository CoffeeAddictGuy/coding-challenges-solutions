/*
Given the binary representation of an integer as a string s, return the number
of steps to reduce it to 1 under the following rules:

    If the current number is even, you have to divide it by 2.

    If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.
*/

#include <stdio.h>
#include <string.h>

int numSteps(char *s) {
  int steps = 0;
  int carry = 0;
  int n = strlen(s);

  for (int i = n - 1; i > 0; i--) {
    int bit = s[i] - '0';
    if (bit + carry == 1) {
      steps += 2;
      carry = 1;
    } else {
      steps += 1;
    }
  }
  return steps + carry;
}

int main() {
  char n[58] = "1111011110000011100000110001011011110010111001010111110001";
  int result = numSteps(n);
  printf("Result is %d\n", result);

  return 0;
}