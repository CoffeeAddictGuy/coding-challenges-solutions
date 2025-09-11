#include <mybinarytree.h>


int main() {
    struct binaryTree* node = NULL;
    int *nums = malloc(20*sizeof(int));
    int c_nums = 0;
    nums[c_nums++] = -10;
    nums[c_nums++] = -3;
    nums[c_nums++] = 0;
    nums[c_nums++] = 5;
    nums[c_nums++] = 9;

    for (int i = 0; i < c_nums; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    node = sortedArrayToBST(nums, c_nums);
    binaryPrint(node);
    
    return 0;
}