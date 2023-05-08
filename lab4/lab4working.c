#include "lab4.h"

int * createIntArray(size_t size) {
    int * arr = malloc(size*sizeof(int) + sizeof(size_t));
    if(arr == NULL) {
        return NULL;
    }
    size_t * sizetarr = (size_t *) arr;
    sizetarr[0] = size;
    sizetarr++;
    arr = (int *) sizetarr;
    return arr;
}

size_t getSize(int *array) {
    size_t * sizetarr = (size_t *) array;
    return(sizetarr[-1]);
}

void printArray(int *array) {
    size_t size = getSize(array);
    for(size_t i = 0; i<size;i++) {
        printf("%d ",array[i]);
    }
    printf("\n");
}

int sumOddIndices(int *array) {
    int sumOdd = 0;
    size_t size = getSize(array);
    for(size_t i = 0; i<size;i++) {
        if((array[i] % 2) == 1) {
            sumOdd += array[i];
        }
    }
    return sumOdd;
}

void freeArray(int *array) {
    size_t * sizetarr = (size_t *) array;
    sizetarr--;
    array = (int *) sizetarr;
    free(array);
}