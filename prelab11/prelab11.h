#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct _Employee {
    int ssn;
    int empID;
    struct _Employee * left;
    struct _Employee * right;
} Employee;


typedef struct _EmpDatabase {
    Employee * headTreeSortedBySSN;
    Employee * headTreeSortedByID;
    int ec;
} EmpDatabase;

EmpDatabase createSearchableEmployeeDB(); // Just inits your struct 
EmpDatabase insertEmp(Employee *, EmpDatabase);  
Employee * findEmpBySSN(int, EmpDatabase);  
Employee * findEmpByID(int, EmpDatabase);  
void freeEmpDatabase(EmpDatabase);  
int getErrorCode(EmpDatabase); 