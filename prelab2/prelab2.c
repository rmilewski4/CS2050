#include "prelab2.h"

float * readFloatFileIntoArray(FILE *fptr, int *length,  int * funcstatus) {
    if(NULL != fptr) {
        fscanf(fptr,"%d",length);

    }
    float * arr = malloc(sizeof(float) * *length);
    if(!arr) {
        *funcstatus = 1;
        return arr;
    }
    char tempchar[255];
    for(int i = 0;i < *length;i++) {
        fgets(tempchar,255,fptr);
        arr[i] = strtof(tempchar, NULL);
        //fscanf(fptr,"%f",arr[i]);
    }
    *funcstatus = 0;
    return arr;
}

void freeFloatArray(float * *arr) {
    free(*arr);
    *arr = NULL;
}