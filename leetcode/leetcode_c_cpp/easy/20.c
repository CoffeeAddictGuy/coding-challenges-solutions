#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isOpenBracket(char b) {
  if (b == '{' || b == '(' || b == '[') {
    return true;
  } else {
    return false;
  }
}

bool isBracketTwin(char a, char b) {
  if ((a == '{' && b == '}') || (a == '(' && b == ')') ||
      (a == '[' && b == ']')) {
    return true;
  }
  return false;
}

bool isValid(char *s) {
  if (!isOpenBracket(s[0])) {
    printf("First element is closed bracket\n");
    return false;
  }

  int str_len = strlen(s);
  printf("String Len %d\n", str_len);
  int *stack = malloc(sizeof(int) * str_len);
  int top = -1;
  for (int i = 0; i < str_len; i++) {
    if (top >= 0 && !isOpenBracket(s[i]) && !isBracketTwin(s[stack[top]], s[i])) {
      printf("%c != %c\n", s[stack[top]], s[i]);
      return false;
    } else if (top >= 0 && !isOpenBracket(s[i]) &&
               isBracketTwin(s[stack[top]], s[i])) {
                printf("%c == %c\n", s[stack[top]], s[i]);
      top--;
    } else {
      stack[++top] = i;
      printf("First element in stack %c\n", s[stack[top]]);
    }
  }

  if (top >= 0) {
    return false;
  } else {
    return true;
  }
}

int main() {
  char *text = "([])";
  bool result = isValid(text);

  if (result) {
    printf("Valid!");
  } else {
    printf("Not Valid!");
  }

  return 0;
}