#include <stdio.h>
#include <stdlib.h>

void * createArray(int n, int elemSize) {
    int *p;
    p = malloc(n*elemSize + sizeof(int));
    p[0] = n;
    p++;
    return(p);
}
int getArraySize(void * array) {
    return (((int *)array)[-1]);
}
void freeArray(void * array) {
    free(((int*)array)-1);
    array = NULL;
}
int main(void) {
    double * arr;
    arr = createArray(100,sizeof(double));
    printf("Size of array is %d\n", getArraySize(arr));
    freeArray(arr);
    if(arr == NULL) {
    printf("Freed array!\n");
    }
    else {
    printf("free failed!\n");
    }
}