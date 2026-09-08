#include <mysortlib.h>
#include <mylittlelib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int arraySize = rand() % 10 + 1;
    int* arrays = malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++) {
        arrays[i] = rand() % 100 + 1;
    }

    // int arrays[4] = { 99, 95, 5, 1}; 
    // int arraySize = 4;
    printf("Array before - ");
    printArray(arrays, arraySize);
    coctailSort(arrays, 0, arraySize);
    printf("Array after - ");
    printArray(arrays, arraySize);

    //free(arrays);
    return 0;
}