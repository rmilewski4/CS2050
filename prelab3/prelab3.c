#include "prelab3.h"

double * createDoubleArray(int minVal, int maxVal) {

    double * arr = malloc(sizeof(double)*(maxVal-minVal));
    if(!arr) {
        printf("malloc failed!\n");
        return arr;
    }
    arr -= minVal;
    return(arr);
}
void freeDoubleArray(double * arr, int minVal) {
    arr += minVal;
    free(arr);
}