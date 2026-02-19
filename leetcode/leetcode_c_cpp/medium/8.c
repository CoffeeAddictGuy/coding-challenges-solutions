/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit
signed integer.

The algorithm for myAtoi(string s) is as follows:

    Whitespace: Ignore any leading whitespace (" ").
    Signedness: Determine the sign by checking if the next character is '-' or
'+', assuming positivity if neither present. Conversion: Read the integer by
skipping leading zeros until a non-digit character is encountered or the end of
the string is reached. If no digits were read, then the result is 0. Rounding:
If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then
round the integer to remain in the range. Specifically, integers less than -2^31
should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded
to 2^31 - 1.

Return the integer as the final result.
*/

#include <ctype.h>
#include <limits.h>
#include <stdio.h>

int myAtoi(char *s) {
  int curr = 0;
  while (s[curr] == ' ') {
    curr++;
  }

  int result = 0;
  int neg = 0;

  if (!isdigit(s[curr])) {
    if (s[curr] == '-') {
      neg = 1;
      curr++;
    } else if (s[curr] == '+') {
      neg = 0;
      curr++;
    }
  }

  while (isdigit(s[curr])) {
    if (result > INT_MAX / 10 || result * 10 > INT_MAX - (s[curr] - '0')) {
      if (neg == 1) {
        return INT_MIN;
      }
      return INT_MAX;
    }
    result = result * 10 + (s[curr] - '0');
    curr++;
  }

  if (neg == 1) {
    result = -result;
  }

  return result;
}

int main() {
  char *s = "21474836460";
  int result = myAtoi(s);
  printf("Result: %d\n", result);
  return 0;
}