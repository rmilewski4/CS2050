#include "prelab0.h"

int findNumber(int arr[], int size, int num) {
    int counter = 0;
    for(int i = 0; i< size; i++) {
        if(*(arr + i)>=num) {
            counter++;
        }
    }
    return counter;
}