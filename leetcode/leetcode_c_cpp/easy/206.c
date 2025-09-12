/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

#include <stdlib.h>
#include <stdio.h>
#include <mylinkedlist.h>

struct ListNode* reverseListOLD(struct ListNode* head) {
    if (head == NULL) return 0;
    int listSize = listLenght(head)-1;
    if (listSize == 0) return head;
    struct ListNode* curr = head;
    int loopCnt = listSize/2;
    int temp = 0;
    if (loopCnt == 0) {
        temp = getIntValueByIndex(curr, 1);
        setIntValueByIndex(curr, 1, getIntValueByIndex(curr, listSize - 1));
        setIntValueByIndex(curr, listSize - 1, temp);
    } else {
        for (int i = 0; i < loopCnt; i++) {
            temp = getIntValueByIndex(curr, i);
            setIntValueByIndex(curr, i, getIntValueByIndex(curr, listSize- i));
            setIntValueByIndex(curr, listSize - i, temp);
        }
    }

    return curr;
}


struct ListNode* reverseList_old_old(struct ListNode* head) {
    if (head == NULL) return 0;
    int listSize = listLenght(head);
    printf("Size - %d\n", listSize);
    if (listSize == 0) return head;
    
    struct ListNode* res = NULL;
    int *array = (int *)malloc(sizeof(int) * listSize);
    for (int i = 0; i < listSize; i++) {
        array[i] = getIntValueByIndex(head, listSize-i-1);
    }

    for (int i = 0; i < listSize; i++) {
        printf("%d ", array[i]);
        res = insertInt(res, array[i]);
    }
    return res;
}

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return head;
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* tempNext = NULL;

    while (curr != NULL)
    {
        tempNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tempNext;
    }
    return prev;
}

int main() {
    struct ListNode* head = NULL;
    for (int i = 0; i < 4; i++) {
        head = insertInt(head, 1+i);
    }
    printList(head);
    printf("\n");
    struct ListNode* result = reverseList(head);
    printf("\n");
    printList(result);
    return 0;
}