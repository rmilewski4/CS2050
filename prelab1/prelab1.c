#include "prelab1.h"

int findLEQ(float * array, int size, float num, float * result) {
    float LEQ = array[0];
    for(int x = 0; x<size;x++) {
        if(array[x] < LEQ) {
            LEQ = array[x];
        }
    }
    int numfound = 0;
    for(int i = 0; i< size; i++) {
        if((array[i] < num) && (array[i] >= LEQ)) {
            LEQ = array[i];
            numfound = 1;
        }
    }
    *result = LEQ;
    return numfound;
}