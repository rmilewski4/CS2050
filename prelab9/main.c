#include "prelab9.h"

int main(void) {
    int size = 10;
    Employee ** arr = malloc(sizeof(Employee *) * size);
    for(int i = 0; i< size; i++) {
        int random = rand() % 50;
        arr[i] = malloc(sizeof(Employee));
        arr[i]->ssn = 100000000 + random;
        random = rand() % 50;
        arr[i]->empID = random;
        printEmployee(arr[i]);
    }
    arr[3]->empID = 48;
    arr[2]->ssn = 100000049;
    EmpDatabase database = createSearchableEmployeeDB(arr, size);
    printf("Printing sorted ID list\n");
    for(int x = 0 ; x < size; x++) {
        printEmployee(database.arraySortedByID[x]);
    }
    printf("Printing sorted SSN List\n");
    for(int y = 0; y < size; y++) {
        printEmployee(database.arraySortedBySSN[y]);
    }
    Employee * temp = findEmpByID(23,database);
    printf("\nGetting Employee with ID 23\n");
    if(temp != NULL) {
        printEmployee(temp);
    }
    else{
        printf("Value not found!\n");
    }
    printf("\nGetting Employee with SSN 100000024\n");
    temp = findEmpBySSN(100000024, database);
    if(temp != NULL) {
        printEmployee(temp);
    }
    else {
        printf("Value not found!\n");
    }
    freeEmpDatabase(database);
}