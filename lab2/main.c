#include "lab2.h"

int main() {
    FILE * fptr;
    fptr = fopen("numbers.txt","r");
    int length;
    int lastNum;
    int * arr = createIntArrayFromFile(fptr, &length);
    fclose(fptr);
    if(arr == NULL) {
        printf("Error malloc'ing please check the first file number\n");
        return 0;
    }
    for(int i = 0;i<length;i++) {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    int * lastAddress = NULL;
    lastNum = 1;
    int result = lastAddressOf(arr,length,&lastAddress,lastNum);
    if(result == 0) {
        printf("The last address of %d was found at %p! it is %d\n",lastNum, lastAddress, *lastAddress);
    }
    else {
        printf("No instance of %d could be found\n",lastNum);
    }
    freeArray(arr);
}

