#include <mylinkedlist.h>
#include <time.h>
#include <string.h>


int main() {
    srand(time(NULL));
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    l1 = insert(l1, 9);
    l2 = insert(l2, 1);
        l2 = insert(l2, 9);
        l2 = insert(l2, 9);
        l2 = insert(l2, 9);
        l2 = insert(l2, 9);
        l2 = insert(l2, 9);
        l2 = insert(l2, 9);
        l2 = insert(l2, 9);
        l2 = insert(l2, 9);
        l2 = insert(l2, 9);
    printList(l1);
    printf("\n");
    printList(l2);

    printf("\n");
    printf("Linked list size = %d", listLenght(l1));
    printf("\n");
    printf("Linked list size = %d", listLenght(l2));

    printf("\n");
    addTwoNumbers(l1, l2);
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (listLenght(l1) == 1 && listLenght(l2) == 1) {
        struct ListNode *result = NULL;
        int res = l1->val + l2 -> val;
        char sumAll[listLenght(l1)+listLenght(l2)];
        sprintf(sumAll, "%d", res);
        int k = strlen(sumAll)-1;
        while (k >= 0) {
            //printf("%d", sumAll[k] - '0');
            result = insert(result, sumAll[k] - '0');
            k--;
        }
        printList(result);
        return result;
    }
    int lenRes;
    int len = listLenght(l1);
    lenRes+=len;
    char* one = malloc(len + 1);
    struct ListNode* curr1 = l1;

    for (int i = 0; i < len; i++) {
        one[i] = curr1->val + '0';
        curr1 = curr1->next;
    }
    one[len] = '\0';
    printf("First linken list to char - %s", one);

    int l = 0;
    int r = strlen(one) - 1;
    char temp;
    while (l < r) {
        temp = one[l];
        one[l] = one[r];
        one[r] = temp;
        l++;
        r--;
    }
    printf("\n");
    printf("First linken list to char reverse - %s", one);

    len = listLenght(l2);
    lenRes+=len;
    char* sec = malloc(len + 1);
    struct ListNode* curr2 = l2;

    for (int i = 0; i < len; i++) {
        sec[i] = curr2->val + '0';
        curr2 = curr2->next;
    }
    sec[len] = '\0';
    printf("\n");
    printf("Second linken list to char - %s", sec);

    l = 0;
    r = strlen(sec) - 1;
    while (l < r) {
        temp = sec[l];
        sec[l] = sec[r];
        sec[r] = temp;
        l++;
        r--;
    }
    printf("\n");
    printf("Second linken list to char reverse - %s", sec);

    long long num1 = atoll(one);
    long long num2 = atoll(sec);
    long long res = num1 + num2;
    free(one);
    free(sec);
    printf("\nResult - %d", res);
    printf("\n");

    struct ListNode *result = NULL;
    if (res == 0) {
        return createList(0);
    }

    while (res > 0) {
        int digit = res % 10;
        result = insert(result, digit);
        res /= 10;
    }
    printf("\n");

    printList(result);

    return result;
}