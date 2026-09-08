/*
You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single
digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct Stack {
  int top;
  int data[100];
};

struct ListNode *ln_init(int value) {
  struct ListNode *ln = malloc(sizeof(struct ListNode));
  ln->val = value;
  ln->next = NULL;
  return ln;
}

struct ListNode *ln_add(struct ListNode *ln, int value) {
  if (ln == NULL) {
    return ln_init(value);
  }
  struct ListNode *curr = ln;
  struct ListNode *new = ln_init(value);
  new->next = curr;
  return new;
}

void ln_print(struct ListNode *ln) {
  while (ln != NULL) {
    printf("%d -> ", ln->val);
    ln = ln->next;
  }
  printf("\n");
}

struct Stack *stack_init() {
  struct Stack *s = malloc(sizeof(struct Stack));
  s->top = -1;
  return s;
}

void stack_push(struct Stack *stk, int value) { stk->data[++stk->top] = value; }

int stack_pop(struct Stack *stk) {
  int tmp = stk->data[stk->top];
  stk->top--;
  return tmp;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  if (l1 == NULL) {
    return l2;
  } else if (l2 == NULL) {
    return l1;
  }

  struct Stack *f_stack = stack_init();
  struct Stack *s_stack = stack_init();
  struct ListNode *answer = NULL;

  while (l1 != NULL || l2 != NULL) {
    if (l1 != NULL) {
      stack_push(f_stack, l1->val);
      l1 = l1->next;
    }
    if (l2 != NULL) {
      stack_push(s_stack, l2->val);
      l2 = l2->next;
    }
  }

  int carry = 0;

  while (f_stack->top >= 0 || s_stack->top >= 0) {
    int f = 0, s = 0;
    if (f_stack->top >= 0 && s_stack->top >= 0) {
      f = stack_pop(f_stack);
      s = stack_pop(s_stack);
    } else if (f_stack->top >= 0 && s_stack->top < 0) {
      f = stack_pop(f_stack);
    } else if (f_stack->top < 0 && s_stack->top >= 0) {
      s = stack_pop(s_stack);
    }

    int result = f + s + carry;
    if (result > 9) {
      result -= 10;
      carry = 1;
    } else {
      carry = 0;
    }

    answer = ln_add(answer, result);
    printf("DEBUG: %d + %d = %d (with carry %d)\n", f, s, result, carry);
  }

  if (carry != 0) {
    answer = ln_add(answer, carry);
  }

  free(f_stack);
  free(s_stack);
  return answer;
}

int main() {
  struct ListNode *tf_head = malloc(sizeof(struct ListNode));
  struct ListNode *tf_second = malloc(sizeof(struct ListNode));
  struct ListNode *tf_third = malloc(sizeof(struct ListNode));
  struct ListNode *tf_four = malloc(sizeof(struct ListNode));
  tf_head->val = 7;
  tf_head->next = tf_second;
  tf_second->val = 2;
  tf_second->next = tf_third;
  tf_third->val = 4;
  tf_third->next = tf_four;
  tf_four->val = 3;
  tf_four->next = NULL;

  struct ListNode *ts_head = malloc(sizeof(struct ListNode));
  struct ListNode *ts_second = malloc(sizeof(struct ListNode));
  struct ListNode *ts_third = malloc(sizeof(struct ListNode));
  ts_head->val = 5;
  ts_head->next = ts_second;
  ts_second->val = 6;
  ts_second->next = ts_third;
  ts_third->val = 4;
  ts_third->next = NULL;

  struct ListNode *result = addTwoNumbers(tf_head, ts_head);
  ln_print(result);

  while (tf_head != NULL) {
    struct ListNode *t = tf_head->next;
    free(tf_head);
    tf_head = t;
  }
  while (ts_head != NULL) {
    struct ListNode *t = ts_head->next;
    free(ts_head);
    ts_head = t;
  }

  return 0;
}