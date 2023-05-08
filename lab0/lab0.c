#include "lab0.h"

/* REQUIRED CODE GOES HERE */
int countOccurrences(int size, int array[], int query) {
    //counter variable to return
    int counter = 0;
    //for loop traverseing the size of the array and iterating by one each time
    for(int i = 0; i < size; i++) {
        //if the current array element is equal to the queried element, add one to the counter
        if(*(array + i) == query) {
            counter++;
        }
    }
    //after the for loop is complete, return the counter.
    return counter;
}
