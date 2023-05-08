/*****************************************************************************
 * CS2050
 * SP2022
 * Lab 5
 * By Ryan Milewski (rsmbby)
 * February 25, 2022
 *****************************************************************************/


#include "lab5.h"

//This function will create a generic array of size numElements, storing enough space per element for elementSize.
//It will return a pointer to the beginning of memory to that array as a void pointer to allow it to be used in any situation.
//On failure, it will instead return a NULL pointer.
void * createArray(size_t elementSize, int numElements){
    //create our array as an integer array so we can store the size easier later. We get the size by multiplying the number of elements
    //by the elementSize in place of our usual sizeof(), and as usual we add an additional int to hold our size.
    int * arr = malloc((numElements*elementSize) + sizeof(int));
    //If a malloc error occurs, then return null.
    if(arr == NULL) {
        return NULL;
    }
    //We set our first space in our array equal to our size that was passed in earlier, then move the pointer by 1 integer size to the beginning of the actual array.
    arr[0] = numElements;
    arr++;
    //finally, we return our array casted as a void pointer in case of any weird issues.
    return ((void *) arr);
}


//This function will take in a void pointer array created by the createArray function and return the size of that function as an integer.
//Because we assume that only arrays created by createArray are passed in, there are no failure conditions.
int getSize(void *array) {
    //We create a temporary array and cast our original array as an integer pointer to allow us to access our hidden element.
    int * arr = (int *) array;
    //We return the -1st element of the array becasue that is where we hid our size in createArray.
    return arr[-1];
}
//The function takes in a single Car pointer and returns the vin number of that car.
int getVin(Car *car) {
    //Since car is a pointer, we need to use the arrow operator to access the vin, then all we do is return that number we retrieved with the points to operator.
    return car->vin;
}

//This function takes in a single car pointer and returns the number of miles driven on that car.
float getMilesDriven(Car *car) {
    //Similar to the other getter, we use the arrow operator to access the milesDriven element and return it to the calling program.
    return car->milesDriven;
}

//This function takes in a single car pointer and returns the number of accidents that that car has been in.
int getNumberOfAccidents(Car *car) {
    //Just like the other getters, we use the arrow operator and return the number of accidents by that car in 1 line.
    return car->numberOfAccidents;
}
//This function takes in a single car pointer and a floating point number that will be the number of miles to add to the cars milesDriven.
//The function will not return anything, but will add the number given to the milesDriven already on the car.
void updateMilesDriven(Car *car, float milesToAdd) {
    //Here we use the arrow operator to access the milesDriven element and set it equal to itself plus the milesToAdd variable.
    car->milesDriven += milesToAdd;
    //Because the function is void, we don't have to return anything.
}

//This function will take in a single car pointer and add 1 to the number of accidents on that car.
void incrementNumberOfAccidents(Car *car) {
    //We access the numberOfAccidents member by using the arrow operator and set it equal to itself plus one.
    car->numberOfAccidents += 1;
    //Just like the previous function we don't need to return anything since the function is set to void.
}
//This function will take in the specified car array created previously and a VIN number to look for.
//If a car matching that VIN number is found in the array, a pointer to that element of the array will be returned
//If a car is not found matching that VIN in the array, the function will return NULL.
Car * getCarByVIN(Car *array, int VIN) {
    //We need to know the size of the array first, to be able to traverse it. So we call our previously created getSize function.
    int size = getSize(array);
    //Using our size, we are able to use a for loop to traverse the array.
    for(int i = 0; i<size;i++) {
        //We use our getVin getter function to retrieve the VIN of the current element in the array and check if it is the same as the input VIN.
        if(getVin(&array[i]) == VIN) {
            //If they are the same, then return the address of the current element in the array.
            return &array[i];
        }
    }
    //If no matches were found throughout the entire array, then we are able to just return NULL.
    return NULL;
}
//This function will take an array of Car structs and return a pointer of the car struct that has the most Miles driven on it.
//It is assumed that the array that is passed was created by createArray, so there are no error conditions
Car * getWithMostMilesDriven(Car *array) {
    //We create a temporary Car pointer and set it equal to NULL.
    Car * mostDrivenCar = NULL;
    //Like our other functions, we need to retrieve the size from our getSize function.
    int size = getSize(array);
    //We check if the size is greater than 1 or equal to 1 before we access a member of the array to avoid potentially reading memory that isn't ours.
    if(size >= 1) {
        //If the size is greater, we set our temporary variable equal to the first element in our array.
        mostDrivenCar = &array[0];
    }
    //We are now able to traverse our array.
    for(int i = 0; i< size; i++) {
        //If the miles driven of the current element of the array is greater than the miles driven of our temporary variable...
        if(getMilesDriven(&array[i]) > getMilesDriven(mostDrivenCar)) {
            //We set our temporary value equal to the current address of the array element.
            mostDrivenCar = &array[i];
        }
    }
    //Finally, after we traverse our array, we return our mostDrivenCar variable that is now holding the car with the most miles driven.
    return mostDrivenCar;
}
//This function takes in an array of Cars and will print each element's members on it's own line
//It is assumed that the array that is passed was created by createArray, so there are no error conditions
//There are no return values.
void printCars(Car *array) {
    //Just like the previous functions, we need to get the size of the array to be able to traverse the array.
    int size = getSize(array);
    for(int i = 0; i< size; i++) {
        //When we are traversing our array, we just use our getter functions to print each member of the struct for each member of the array.
        printf("array[%d]: VIN = %d, milesDriven = %f, numberOfAccidents = %d\n",i,getVin(&array[i]),getMilesDriven(&array[i]),getNumberOfAccidents(&array[i]));
    }
}
//This function will take in a void * array and free its memory that was allocated by createArray.
//Since it is assumed that it was created by createArray, there are no error possiblities.
//This function will return nothing as it is set to void.
void freeArray(void *array) {
    //Creates a temporary array and casts our input array as an integer so we can move its pointer the right amount.
    int * arr = (int *) array;
    //We are then able to move the pointer to its original memory location and call the free() function on that address to return the memory back to the OS.
    arr--;
    free(arr);
}
