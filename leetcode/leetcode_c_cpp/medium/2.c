/**
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include <asm-generic/errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *ListNodeInit(int value) {
  struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
  new->val = value;
  new->next = NULL;
  return new;
}

struct ListNode *ListNodeAdd(struct ListNode *list, int value) {
  if (list == NULL) {
    return ListNodeInit(value);
  }
  if (list->next != NULL) {
    ListNodeAdd(list->next, value);
  } else {
    struct ListNode *next = ListNodeInit(value);
    list->next = next;
  }
  return list;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *result = NULL;
  int d = 0;

  struct ListNode *first = l1;
  struct ListNode *second = l2;

  while (first != NULL && second != NULL) {
    int sum = first->val + second->val + d;
    if (sum > 9) {
      d = 1;
      sum = sum - 10;
      result = ListNodeAdd(result, sum);
    } else {
      d = 0;
      result = ListNodeAdd(result, sum);
    }
    first = first->next;
    second = second->next;
  }

  if (first != NULL && second == NULL) {
    while (first != NULL) {
      int sum = first->val + d;
      if (sum > 9) {
        d = 1;
        sum = sum - 10;
        result = ListNodeAdd(result, sum);
      } else {
        d = 0;
        result = ListNodeAdd(result, sum);
      }
      first = first->next;
    }
  }

  if (second != NULL && first == NULL) {
    while (second != NULL) {
      int sum = second->val + d;
      if (sum > 9) {
        d = 1;
        sum = sum - 10;
        result = ListNodeAdd(result, sum);
      } else {
        d = 0;
        result = ListNodeAdd(result, sum);
      }
      second = second->next;
    }
  }

  if (d != 0) {
    result = ListNodeAdd(result, d);
  }
  return result;
}

void ListNodePrint(struct ListNode *list) {
  struct ListNode *temp = list;
  while (temp != NULL) {
    if (temp->next == NULL) {
      printf("%d", temp->val);
    } else {
      printf("%d -> ", temp->val);
    }
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct ListNode *head_l1 = ListNodeInit(9);
  ListNodeAdd(head_l1, 9);
  ListNodeAdd(head_l1, 1);

  struct ListNode *head_l2 = ListNodeInit(1);

  ListNodePrint(head_l1);
  printf("=============\n");
  ListNodePrint(head_l2);

  printf("=============\n");
  struct ListNode *result = addTwoNumbers(head_l1, head_l2);
  ListNodePrint(result);

  return 0;
}