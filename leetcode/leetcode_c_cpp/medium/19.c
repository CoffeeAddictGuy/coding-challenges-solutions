#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct Result {
  struct ListNode *parent;
  struct ListNode *curr;
};

struct ListNode *ln_init(int val) {
  struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
  new->val = val;
  new->next = NULL;
  return new;
}

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
  return head;
}

int main() {
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

  return 0;
}