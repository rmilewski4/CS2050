#include <stdio.h>
#include <stdlib.h>

float * readFloatFileIntoArray(FILE *fptr, int *length,  int * funcstatus);
void freeFloatArray(float * * arr);