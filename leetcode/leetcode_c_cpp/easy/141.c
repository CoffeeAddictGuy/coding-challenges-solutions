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

bool hasCycle(struct ListNode *head) {
  if (!head || !head->next)
    return false;

  struct ListNode *slow = head, *fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;
}

struct Result *ln_search(struct ListNode *head, int val) {
  struct Result *result = malloc(sizeof(struct Result));
  if (head == NULL) {
    return NULL;
  }
  while (head->next != NULL) {
    if (head->val == val) {
      result->curr = head;
      result->parent = NULL;
      return result;
    }
    if (head->next->val == val) {
      result->curr = head->next;
      result->parent = head;
      return result;
    }
    head = head->next;
  }
  if (head->val == val) {
    result->curr = head;
    result->parent = NULL;
    return result;
  }
  return NULL;
}

struct ListNode *removeElements(struct ListNode *head, int val) {
  struct Result *s = ln_search(head, val);
  if (s == NULL) {
    return head;
  }

  while (s != NULL) {
    printf("s is %p with value %d\n", s, s->curr->val);
    if (s != NULL && s->parent != NULL) {
      if (s->curr->next != NULL) {
        s->parent->next = s->curr->next;
      } else {
        s->parent->next = NULL;
      }
      s = ln_search(head, val);
    } else if (s != NULL) {
      if (s->curr->next != NULL) {
        printf("In head!\n");
        struct ListNode *new = head->next;
        head = new;
        s = ln_search(head, val);
      } else if (s->curr->next == NULL) {
        printf("Last in head!\n");
        return head;
      }
    } else {
      printf("Last in hz!\n");
      break;
    }
  }
  return head;
}

int main() {
  struct ListNode *test = ln_init(1);

  ln_print(test);

  struct Result *new = ln_search(test, 22);
  if (new != NULL && new->parent != NULL) {
    printf("Found %p with value %d and parent %p with value %d\n", new->curr,
           new->curr->val, new->parent, new->parent->val);
  } else if (new != NULL) {
    printf("Found in start %p with value %d and child %d\n", new->curr,
           new->curr->val, new->curr->next->val);
  } else {
    printf("Not found!\n");
  }

  test = removeElements(test, 7);
  ln_print(test);

  return 0;
}