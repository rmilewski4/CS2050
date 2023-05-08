#include "lab4.h"

int main(void) {
    size_t size = 6;
    int * array = createIntArray(size);
    if(array==NULL) {
        printf("An error has occured!\nExiting\n");
        return 1;
    }
    size_t retrievedsize = getSize(array);
    printf("The size is %zu or %zu\n",retrievedsize,getSize(array));
    for(size_t i = 0; i< retrievedsize;i++) {
        array[i] = (i * 3);
    }
    printArray(array);
    printf("The sum of the odd indicies is %d\n",sumOddIndices(array));
    freeArray(array);
}