/*****************************************************************************
 * CS2050
 * SP2022
 * Lab 4
 * By Ryan Milewski (rsmbby)
 * February 18, 2022
 *****************************************************************************/

#include "lab4.h"

//This function will create an integer array of specified size_t size and return the address to the 0th elemenet of the created array.
//If an error has occurred, the function will return a NULL pointer.
int * createIntArray(size_t size) {
    //To begin, we will start our array as a type of size_t to make pointer arethmetic easier later.
    //We allocate it using malloc and the size we were given times the size of an integer, plus an addition memory space for the size of the array hidden
    size_t * arr = malloc(size*sizeof(int) + sizeof(size_t));
    //If a malloc error occurs, then return null.
    if(arr == NULL) {
        return NULL;
    }
    //We set our first space in our array equal to our size that was passed in earlier, then move the pointer by the single size_t size to the beginning of the actual array.
    arr[0] = size;
    arr++;
    //After we do this, the array is pointing to enough memory to store our int array, so we simply pass the array as an integer pointer which will allow work to be done on it with ints.
    return ((int *) arr);
}
//This function will return the a size_t size of the previously created array using the createIntArray.
//Since it is assumed that only arrays created by the createIntArray are passed in, there are no failure conditions.
size_t getSize(int *array) {
    //Here, we create a size_t array and cast our original array as this type and set it equal to it for easier indexing.
    size_t * sizetarr = (size_t *) array;
    //after this all we have to do is return the -1st element of the size_t array and it will retrieve our size.
    return(sizetarr[-1]);
}
//This function will print the array created by the createIntArray without the user having to enter in the size of the array.
//The array will be formatted on one line with spaces inbetween and a new line following the last element.
void printArray(int *array) {
    //Create a size variable of type size_t that will call our created getSize function and store the size of the created array.
    size_t size = 0;
    size = getSize(array);
    
    //We will index along our array using an index variable of type size_t to our size, but it will function identically to a normal int.
    for(size_t i = 0; i<size;i++) {
        //Here, I am just printing the array itself with a space after itself
        printf("%d ",array[i]);
    }
    //Finally after we are done printing our array elements, we follow it with a newline
    printf("\n");
}
//This function will sum up all of the odd Indicies of the array and return it as an integer. It will take in the previously
//created array created by createIntArray.
int sumOddIndices(int *array) {
    //We create our summation variable to hold all of the addition. We also create a size_t size variable just like in the printArray function,
    //which is calling the getSize function to return the size.
    int sumOdd = 0;
    size_t size = 0;
    size = getSize(array);
    //Similarly as the printArray function, we need to index along our entire array using size_t variables in our for loop.
    for(size_t i = 0; i<size;i++) {
        //If the array indexer has a remainder when dividing by 2 (which means it is odd), then add it to the summation variable.
        if((i % 2) == 1) {
            sumOdd += array[i];
        }
    }
    //finally, return our summation variable.
    return sumOdd;
}
//This function will take in the previously created integer array with the size stored at the beginning of it, and free its memory back to the OS
//Just like the other functions, this freeArray is assumed to be passed an array that was created with createIntArray.
void freeArray(int *array) {

    //Just like in getSize, we will create a size_t array and cast our original array as this type to index it easier and move the pointer back to the one referenced by malloc
    size_t * sizetarr = (size_t *) array;
    //We move the pointer back to the beginning by moving it down 1 element, the opposite of what we did when it was created.
    sizetarr--;
    //After this, the pointer is the same one created by malloc, so we can return the pointer back to the original array and free it with the free() function. 
    array = (int *) sizetarr;
    free(array);
}