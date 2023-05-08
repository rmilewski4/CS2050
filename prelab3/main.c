#include "prelab3.h"

int main(void) {
    double * arr = createDoubleArray(2000,2022);
    for(int i = 2000; i < 2022; i++) {
        arr[i] = i;
    }
    for(int x = 2000; x < 2022;x++) {
        printf("arr[%d] = %f\n",x,arr[x]);
    }
    freeDoubleArray(arr, 2000);
}