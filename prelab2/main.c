#include "prelab2.h"

int main(void) {
    FILE * fptr;
    fptr = fopen("numbers.txt","r");
    int length;
    int funcstatus;
    float * arr = readFloatFileIntoArray(fptr,&length,&funcstatus);
    fclose(fptr);
    if(funcstatus == 1) {
        printf("Error malloc'ing please check the first file number\n");
        return 0;
    }
    for(int i = 0;i<length;i++) {
        printf("arr[%d] = %f\n",i,arr[i]);
    }
    freeFloatArray(&arr);
}