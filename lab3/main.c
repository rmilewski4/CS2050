#include "lab3.h"

int main(void) {
    int size = 5;
    int * array = createCenteredArray(size);
    if(array == NULL) {
        printf("could not create array!\n");
        return 1;
    }
    int z = 3;
    for(int i =-2; i< 3;i++) {
        printf("top of for loop, i = %d\n",i);
        array[i] = z;
        z++;
        printf("array[%d] = %d\n",i,10);
    }
    
    for(int x = -5; x< 10; x++) {
        if(getAtIndex(array,size,x)==1) {
            printf("Error on index %d\n",x);
        }
        else {
            printf("Array[%d] = %d\n",x,getAtIndex(array,size,x));
        }
    }
    printf("average upper half = %f\n",averageUpperHalf(array,size));
    
    freeCenteredArray(array,size);
}