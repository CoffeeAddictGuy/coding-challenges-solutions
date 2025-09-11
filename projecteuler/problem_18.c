#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <mybinarytree.h>


int main() {
    srand(time(NULL));

    struct binaryTree *node = NULL;
    node = insert(node, 8);
    for (int i = 0; i < 10; i++) {
        insert(node, rand() % 100 + 1);
    }
    binaryPrint(node);
    printf("NULL\n");
    int ret_size = 5;
    inorderTraversal(node, &ret_size);
    return 0;
}