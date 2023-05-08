/*****************************************************************************
 * CS2050
 * SP2022
 * Lab 1
 * By Ryan Milewski (rsmbby)
 * January 28, 2022
 *****************************************************************************/

#include "lab1.h"

// REQUIRED FUNCTION IMPLEMENTATIONS

/*
This function will calculate the average of all evens inside of an integer array.
This function takes in an integer array, the size of that array, and a pointer to a float that will hold the result of the function.
The result of the function will be passed by reference through the float pointer.
The function will return the number of elements in the array averaged on success.
On failure (if there are no evens in the array), the function will return 0. 
*/
int avgEven(int *array, int size, float *result) {
    //creating a counter to count the even numbers in the array and a local float to add up the numbers.
    int evenNumbers = 0;
    float myResult = 0;
    //creating a for loop to go through the entire array.
    for(int i = 0;i<size;i++) {
        //When dividing by 2, if the number in the array has a remainder of 0 (which means it's an even), enter the if block
        if((array[i] % 2) == 0) {
            //add one to our even number counter, and add the number in the array to our result float.
            evenNumbers++;
            myResult += array[i];
        }
    }
    //If there were no evens found, then return that 0 as the result and exit the function (to avoid dividing by 0)
    if(evenNumbers == 0) {
        return evenNumbers;
    }
    //otherwise divide the total of the numbers by the number of evens, and place it in the result pointer by derefrencing it
    *result = (myResult / (float) evenNumbers);
    //finally, return the number of elements that were counted
    return evenNumbers;
}