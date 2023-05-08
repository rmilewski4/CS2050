#include "prelab9.h"

Employee ** copyArray(Employee ** arr, int size) {
    Employee ** array2 = malloc(sizeof(Employee *) * size);
    for(int i = 0; i< size; i++) {
        array2[i] = malloc(sizeof(Employee));
        array2[i]->empID = arr[i]->empID;
        array2[i]->ssn = arr[i]->ssn;
    }
    return array2;
}

EmpDatabase createSearchableEmployeeDB(Employee ** arr, int size) {
    EmpDatabase database;
    Employee ** arr2 = copyArray(arr,size);
   // memcpy(arr2,arr,sizeof(*arr));
    database.arraySortedByID = sortWithIndicator(arr,size,2);
    database.arraySortedBySSN = sortWithIndicator(arr2,size,1);
    database.size = size;
    return database;
}
//sortIndicate 1 = sort by ssn, sortIndicate = 2 sort by ID
Employee ** sortWithIndicator(Employee ** arr, int size, int sortIndicate) {
    Employee * hold;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j< size-1; j++) {
            switch(sortIndicate) {
                case 1:
                    if(arr[j]->ssn > arr[j+1]->ssn) {
                    hold = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = hold;
                    }
                break;
                case 2:
                    if(arr[j]->empID > arr[j+1]->empID) {
                    hold = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = hold;
                    }
                break;

                default:
                break;
            }
        }
    }
    return arr;
}
int BinarySearch(int key, Employee ** arr, int min, int max, int type) {
    if(min == max) {
        return -1;
    }
    int mid = min + (max-min)/2;
    printf("Current value of mid is %d\n",mid);
    if(type == 1) {
        if(arr[mid]->ssn > key) {
        return BinarySearch(key,arr,min,mid,type);
    }
    if(arr[mid]->ssn < key) {
        return BinarySearch(key,arr,mid+1,max,type);
    }
    if(arr[mid]->ssn == key) {
        return mid;
    }
    }
    if(type == 2) {
        if(arr[mid]->empID > key) {
        return BinarySearch(key,arr,min,mid,type);
    }
    if(arr[mid]->empID < key) {
        return BinarySearch(key,arr,mid +1,max,type);
    }
    if(arr[mid]->empID == key) {
        return mid;
    }
    }

    return -1;
}
Employee * findEmpBySSN(int SSN, EmpDatabase database) {
    int num = BinarySearch(SSN,database.arraySortedBySSN,0,database.size,1);
    if(num == -1) {
        return NULL;
    }
    return(database.arraySortedBySSN[num]);
}
Employee * findEmpByID(int ID, EmpDatabase database) {
    int num = BinarySearch(ID,database.arraySortedByID,0,database.size,2);
    if(num == -1) {
        return NULL;
    }
    return(database.arraySortedByID[num]);
}
void freeEmpDatabase(EmpDatabase database) {
    for(int i = 0; i< database.size; i++) {
        free(database.arraySortedByID[i]);
        free(database.arraySortedBySSN[i]);
    }
    free(database.arraySortedByID);
    free(database.arraySortedBySSN);
}

void printEmployee(Employee * emp) {
    printf("SSN: %d\t, empID: %d\n",emp->ssn,emp->empID);
}