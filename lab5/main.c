#include "lab5.h"

int main(void) {
    int numElements = 10;
    Car * arr = createArray(sizeof(Car),numElements);
    if(arr == NULL) {
        printf("ERROR! COULD NOT ALLOCATE MEMORY! EXITING!\n");
        return EXIT_FAILURE;
    }
    printf("Size = %d\n",getSize(arr));
    if(getSize(arr)==0) {
        printf("ERROR! SIZE = 0, exiting!\n");
        freeArray(arr);
        return EXIT_FAILURE;
    }
    for(int i = 0; i < numElements;i++) {
        arr[i].vin = 102 + i;
        arr[i].milesDriven = 24 + i;
        arr[i].numberOfAccidents = 0 + i;
    }
    printCars(arr); 

    printf("Testing Getters!\n getVin of car 0 = %d, getMilesDriven of car 0 = %f, getNumberOfAccidents of car 0 = %d\n",getVin(&arr[0]),getMilesDriven(&arr[0]),getNumberOfAccidents(&arr[0]));
    Car * specialCar = getCarByVIN(arr,106);
    if(specialCar != NULL) {
        printf("special car!\nVIN = %d, miles = %f, accidents = %d\n",specialCar->vin, specialCar->milesDriven,specialCar->numberOfAccidents);
    }
    else {
        printf("Could not find a car with that VIN!\n");
    }
    updateMilesDriven(&arr[0], 76);
    specialCar = getWithMostMilesDriven(arr);

    printf("Most miles driven: \nVIN = %d, miles = %f, accidents = %d\n",specialCar->vin, specialCar->milesDriven,specialCar->numberOfAccidents);
    incrementNumberOfAccidents(&arr[0]);
    printCars(arr);
    freeArray(arr);
}