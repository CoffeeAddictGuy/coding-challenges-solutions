/*
Given the head of a linked list, remove the nth node from the end of the list
and return its head.
*/

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

int finder(struct ListNode *head, int n) {
  struct ListNode *parent = head;
  struct ListNode *curr = head;
  // int t = n;

  if (head->next != NULL) {
    curr = curr->next;
    n = finder(head->next, n);
  }

  n -= 1;

  printf("Step %d\n", n);

  if (parent != NULL && curr != NULL) {
    printf("Parent %d and curr %d and step %d\n", parent->val, curr->val, n);
  }

  if (n == 0) {
    printf("Need to remove!\n");
    if (parent == NULL) {
      printf("Head!\n");
      head = curr;
    } else {
      parent->next = curr->next;
    }
  }

  return n;
}
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  printf("N - %d\n", n);
  int test = finder(head, n + 1);
  if (test > 0) {
    printf("Test head %d and next %d\n", head->val, head->next->val);
    return head->next;
  }
  printf("Test %d\n", test);
  return head;
}

int main() {
  struct ListNode *head_l1 = ListNodeInit(1);
  ListNodeAdd(head_l1, 2);
  ListNodeAdd(head_l1, 3);
  ListNodeAdd(head_l1, 4);
  ListNodeAdd(head_l1, 5);

  int n = 5;

  printList(head_l1);
  head_l1 = removeNthFromEnd(head_l1, n);
  printList(head_l1);
  return 0;
}