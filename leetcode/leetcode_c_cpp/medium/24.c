/*
Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes
(i.e., only nodes themselves may be changed.)
*/

#include <asm-generic/errno.h>
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

void printList(struct ListNode *head) {
  while (head != NULL) {
    if (head->next == NULL) {
      printf("%d\n", head->val);
    } else {
      printf("%d -> ", head->val);
    }
    head = head->next;
  }
}

struct ListNode *swapPairs(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  struct ListNode *curr = head;
  struct ListNode *parent = head;

  while (curr != NULL && curr->next != NULL) {
    struct ListNode *a = curr;
    struct ListNode *b = curr->next;
    struct ListNode *t = b->next;
    b->next = a;
    a->next = t;

    if (head == curr) {
      head = b;
    } else {
      parent->next = b;
    }

    parent = curr;
    curr = curr->next;
  }
  return head;
}

int main() {
  struct ListNode *head_l1 = ListNodeInit(2);
  ListNodeAdd(head_l1, 5);
  ListNodeAdd(head_l1, 3);
  ListNodeAdd(head_l1, 4);
  ListNodeAdd(head_l1, 6);
  ListNodeAdd(head_l1, 2);
  ListNodeAdd(head_l1, 2);

  printList(head_l1);
  // printf("curr.next.next = %d\n", head_l1->next->val);
  head_l1 = swapPairs(head_l1);
  // head_l1 = swapList(head_l1, head_l1 , head_l1->next);
  printList(head_l1);

  return 0;
}