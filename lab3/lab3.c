/*****************************************************************************
 * CS2050
 * SP2022
 * Lab 3
 * By Ryan Milewski (rsmbby)
 * February 11, 2022
 *****************************************************************************/

#include "lab3.h"
//This function will create an array of an odd size, and move the beginning index to the middle of the array.
//This function will return null on an error or if the array could not be created for any reason (i.e. the size was even or malloc failure)
int * createCenteredArray(int size) {
    //getting our middle value, we can figure out that our two edges of the array is just half of the size (the decimal will get chopped off, but this is okay for our purposes)
    int halfsize = size / 2;

    //if the size is an even number, return null.
    if((size % 2) == 0) {
        return NULL;
    }
    //otherwise create our array and malloc it to the given size.
    int * arr = NULL;
    arr = (int *) malloc(sizeof(int) * size);
    //if malloc fails after this, then return null.
    if(arr == NULL) {
        return NULL;
    }
    //move the beginning of our array pointer up to half the size of the array. when the decimal gets chopped off, this will place
    //the array pointer exactly on the beginning of the 0th element.
    arr += halfsize;
    return arr;
}
//This function will take in an array, its size, and the given index and return the number at that given index.
//The function will return 1 on error, if the index given is not in the bounds of the array.
int getAtIndex(int *array, int size, int index) {
    //once again, finding our edges of the array by dividing the size by 2.
    int half = size/2;
    //if the index given is greater than the half or less than the negative half, then return an error because an improper index was given.
    //for example, if the array size is 3, then half will be 1 via integer division. If the index given is -2, this is less than the -half condition so it will return 1
    //if the index is 5, this is greater than 1 so it will return a 1.
        if((index > (half)) || (index < -half)) {
            return 1;
        }
    //if we pass the bounds checking, then we can return the array at the given index.
    return array[index];
}
//This function will take in an array pointer, and the size and will return a float value of the average of the upperhalf of the elements (including 0).
//This means that if the array is 3 elements long, it will take the average of 0 and 1, since they are positive.
float averageUpperHalf(int *array, int size) {
    //finding the upperbound of our array by dividing the size by 2.
    int upperhalf = size/2;
    //creating variables to add up the numbers and count how many numbers are tracked.
    float summation = 0;
    int count = 0;
    //from 0 which is our first element, through the upperhalf index (including it though), we will go through and add these values to our summation variable.
    for(int i = 0; i<=upperhalf;i++) {
        summation +=  array[i];
        count++;
    }
    //finally, we will return the average by dividing the summation total divided by the count (passed as float to ensure float division).
    return (summation / (float) count);
}
//This function will take an array and its size and free its given array that was allocated via malloc.
void freeCenteredArray(int *array, int size) {
    //just like what we did earlier, we have to reverse the size that we did in the first function, so we will subtract the array pointer
    //by half the size
    array -= ((size/ 2));
    //once our pointer is back at its original spot, we are free to call the free function and return the memory back to the OS.
    free(array);
}