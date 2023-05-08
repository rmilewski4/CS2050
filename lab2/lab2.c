/*****************************************************************************
 * CS2050
 * SP2022
 * Lab 2
 * By Ryan Milewski (rsmbby)
 * February 4, 2022
 *****************************************************************************/

#include "lab2.h"
//This function will create an integer array from a file that has integers in it with the number of integers
//on the first line of that file. The function will take in a file pointer that is assumed to be valid and open
//it will also take in the address of a integer that will pass back the size of the array to the main function
//On failure, the function will set the array equal to NULL and the size equal to -1
int * createIntArrayFromFile(FILE *file, int *size) {
    int * arr = NULL;
    //if the file pointer is actually opened, then we can use it, otherwise it will be set to null and we won't.
    //enter to do the function.
    if(NULL != file) {
        //getting size of the function from the first line using fscanf and storing it in the size variable.
        fscanf(file,"%d", size);
        //initalizing the array using malloc. Setting malloc equal to the size of an int times the dereferenced size.
        arr = malloc(sizeof(int) * (*size));
        //checking for malloc errors, as if malloc was unsucessful, it will automatically set arr equal to NULL.
        if(arr == NULL) {
            arr = NULL;
            //setting our size equal to -1 to indicate error along with the already set NULL to arr
            *size = -1;
            //returning the null array to escape the function and not execute the rest of the instructions
            return arr;
        }
        //creating a temporary int that will be used in the loop as a placeholder for the array.
        int tempint;
        // go along the entire array to place the values
        for(int i = 0; i < *size; i++) {
            //using fscanf place the number in the file inside of the temporary int.
            fscanf(file,"%d",&tempint);
            //finally, set the array at that spot equal to the tempint.
            arr[i] = tempint;
        }
    }
    //if no errors were encounted throughout the entire program, then return the array as found.
    return arr;
}
//this function will look for the last occurence of a given element in the array. It will take in the integer array
//its size, an integer double pointer (int **), to return the address of the given element for later use, and the element to search for
//On failure, the function will set the result pointer equal to NULL. the function will return 0 if the number is found,
//and return 1 if the number was not found in the array. result will also be NULL if the number was not found. 
int lastAddressOf(int *array, int size, int **result, int element) {
    //setting our default variables up. Setting result equal to NULL and result found equal to 1 (nothing found)
    //as if nothing was found in the function itself, these values will be returned.
    *result = NULL;
    int resultFound = 1;
    //traversing the array through a for loop
    for(int i = 0; i < size;i++) {
        printf("the address of arr[%d] is %p\n",i,&array[i]);
        //if the current array value is equal to the element that is being searched for, enter this if
        if(array[i] == element) {
            printf("result found! num == %d\n",array[i]);
            //set our result found to 0 to indicate that a result was found
            resultFound = 0;
            //derefrence our result pointer to store the address of the current array element
            *result = &array[i];

        }
    }
    //finally, return the result found
    return resultFound;
}
//this function takes in an integer pointer that was set to a malloc'd address earlier and returns nothing. The array
//will be freed by this function
void freeArray(int *array) {
    //freeing the array... Even if the array was set to NULL earlier due to an error, it will still execute the
    //free command, however nothing will result of the execution, otherwise the memory is restored to the OS.
    free(array);
}