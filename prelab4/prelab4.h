#include <stdio.h>
#include <stdlib.h>

double * createDoubleArray(int n);

int getDoubleArraySize(double * arr);

void freeDoubleArray(double * arr);

void * createArray(int n, int dataTypeSize);

int getArraySize(void * arr);

void freeArr(void * arr);