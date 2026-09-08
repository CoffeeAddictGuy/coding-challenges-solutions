<<<<<<< HEAD
#include <stdbool.h>
#include <stdint.h>
=======
/*
Given the head of a linked list, remove the nth node from the end of the list
and return its head.
*/

>>>>>>> 7f9e21e83215ddfa9009b99c15709948d935c458
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

<<<<<<< HEAD
struct Result {
  struct ListNode *parent;
  struct ListNode *curr;
};

struct ListNode *ln_init(int val) {
  struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
  new->val = val;
=======
struct ListNode *ListNodeInit(int value) {
  struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
  new->val = value;
>>>>>>> 7f9e21e83215ddfa9009b99c15709948d935c458
  new->next = NULL;
  return new;
}

<<<<<<< HEAD
struct ListNode *ln_insert(struct ListNode *ln, int val) {
  if (ln == NULL) {
    return ln_init(val);
  }
  struct ListNode *curr = ln;
  struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));

  if (new == NULL) {
    return NULL;
  }

  new->val = val;
  new->next = curr;
  ln = new;
  return new;
}

void ln_print(struct ListNode *ln) {
  while (ln != NULL) {
    printf("%d -> ", ln->val);
    ln = ln->next;
  }
  printf("\n");
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  if (head == NULL) {
    return NULL;
  }
  int c = 1;
  struct ListNode *p = head;

  if (head->next == NULL) {
    return head;
  }

  head = head->next;
  while (head != NULL) {
    if (c == n && head->next != NULL) {
      printf("Found %d\nParent %d and next %d", head->val, p->val,
             head->next->val);
      p->next = head->next;
    } else if (c == n && head->next == NULL) {
      p->next = NULL;
    }
    c++;
    p = head;
    head = head->next;
  }
=======
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
>>>>>>> 7f9e21e83215ddfa9009b99c15709948d935c458
  return head;
}

int main() {
<<<<<<< HEAD
  struct ListNode *test = ln_init(1);
  test = ln_insert(test, 2);
  test = ln_insert(test, 3);
  test = ln_insert(test, 4);
  test = ln_insert(test, 5);
  test = ln_insert(test, 6);
  test = ln_insert(test, 7);

  ln_print(test);
  test = removeNthFromEnd(test, 1);
  ln_print(test);

=======
  struct ListNode *head_l1 = ListNodeInit(1);
  ListNodeAdd(head_l1, 2);
  ListNodeAdd(head_l1, 3);
  ListNodeAdd(head_l1, 4);
  ListNodeAdd(head_l1, 5);

  int n = 5;

  printList(head_l1);
  head_l1 = removeNthFromEnd(head_l1, n);
  printList(head_l1);
>>>>>>> 7f9e21e83215ddfa9009b99c15709948d935c458
  return 0;
}