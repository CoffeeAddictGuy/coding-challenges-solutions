/**
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

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

struct ListNode *ListNodeAdd_Old(struct ListNode *list, int value) {
  if (list == NULL) {
    return ListNodeInit(value);
  }
  if (list->next != NULL) {
    ListNodeAdd_Old(list->next, value);
  } else {
    struct ListNode *next = ListNodeInit(value);
    list->next = next;
  }
  return list;
}

struct ListNode *ListNodeAdd(struct ListNode *list, int value) {
  struct ListNode *new = ListNodeInit(value);
  if (list == NULL) {
    return new;
  }
  list->next = new;
  return new;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *head = NULL;
  struct ListNode *tail = NULL;
  int d = 0;

  struct ListNode *first = l1;
  struct ListNode *second = l2;

  while (first != NULL || second != NULL) {
    int sum = 0;
    if (first != NULL && second != NULL) {
      sum = first->val + second->val + d;
      first = first->next;
      second = second->next;
    } else if (first != NULL && second == NULL) {
      sum = first->val + d;
      first = first->next;
    } else {
      sum = second->val + d;
      second = second->next;
    }

    if (sum > 9) {
      d = 1;
      sum = sum - 10;
    } else {
      d = 0;
    }

    if (head == NULL) {
      head = ListNodeAdd(head, sum);
      tail = head;
    } else {
      tail = ListNodeAdd(tail, sum);
    }
  }

  if (d != 0) {
    tail = ListNodeAdd(tail, d);
  }
  return head;
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
  ListNodeAdd_Old(head_l1, 9);
  ListNodeAdd_Old(head_l1, 9);
  ListNodeAdd_Old(head_l1, 9);
  ListNodeAdd_Old(head_l1, 9);
  ListNodeAdd_Old(head_l1, 9);
  ListNodeAdd_Old(head_l1, 9);


  struct ListNode *head_l2 = ListNodeInit(9);
  ListNodeAdd_Old(head_l2, 9);
  ListNodeAdd_Old(head_l2, 9);
  ListNodeAdd_Old(head_l2, 9);


  ListNodePrint(head_l1);
  printf("=============\n");
  ListNodePrint(head_l2);

  printf("=============\n");
  struct ListNode *result = addTwoNumbers(head_l1, head_l2);
  ListNodePrint(result);

  return 0;
}