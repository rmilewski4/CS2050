#include "prelab4.h"

double * createDoubleArray(int n) {
    double * arr = malloc(sizeof(double)*n + sizeof(int));
    if(!arr) {
        printf("malloc failed!\n");
        return NULL;
    }
    *((int *) arr) = n;
    //arr[0] = n; //check if need to cast this as anint to fix size!
    //(int *) arr = (int *)arr + 1;
    printf("array pointer is at %p\n",arr);
    return ((double*)((int*)arr + 1));
}

int getDoubleArraySize(double * arr) {
    int * array = (int *) arr;
    //array--;
    return (*(array-1));
}

void freeDoubleArray(double * arr) {
    free((((int *)arr)-1));
}

void * createArray(int n, int dataTypeSize) {
    int * arr = malloc(n*dataTypeSize + sizeof(int));
    if(!arr) {
        printf("malloc failed!\n");
        return NULL;
    }
    arr[0] = n;
    arr++;
    return arr;
}

int getArraySize(void * arr) {
    int * array = arr;
    return (array[-1]);
}

void freeArr(void * arr) {
    int * array = arr;
    array--;
    free(array);
}