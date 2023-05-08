#include "prelab4.h"

int main(void) {
    double * arr = createDoubleArray(10);
    for(int i = 0;i<10;i++) {
        arr[i] = i;
        printf("arr[%d] = %f\n",i,arr[i]);
    }
    printf("array pointer is at %p\n",arr);
    printf("array size is %d\n",getDoubleArraySize(arr));
    freeDoubleArray(arr);
    
    float * array = createArray(10,sizeof(float));
    for(int x = 0;x<10;x++) {
        array[x] = x;
        printf("arr[%d] = %f\n",x,array[x]);
    }
    printf("array size is %d\n",getArraySize(array));
    freeArr(array);
}