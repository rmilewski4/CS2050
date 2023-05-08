#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



typedef struct _Employee {
    int ssn;
    int empID;

} Employee;


typedef struct _EmpDatabase {
    Employee ** arraySortedBySSN;
    Employee ** arraySortedByID;
    int size;
    int ec;
} EmpDatabase;
int BinarySearch(int key, Employee ** arr, int min, int max, int type);
void printEmployee(Employee *);
Employee ** copyArray(Employee **, int);
Employee ** sortWithIndicator(Employee **, int, int);
// Searches must be done in O(log(N)) time (This means use binary search (which means employees must be sorted for two separate databases for SSN and ID))
EmpDatabase createSearchableEmployeeDB(Employee **, int);  
Employee * findEmpBySSN(int, EmpDatabase);  
Employee * findEmpByID(int, EmpDatabase);  
void freeEmpDatabase(EmpDatabase);  
int getErrorCode(EmpDatabase);