#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int empID, jobType;
    float salary;
} Employee;

Employee * readEmployeeArray(FILE *fp);
int getEmployeeSize(Employee * arr);
void freeEmployeeArray(Employee * arr);
Employee * getEmployeeByID(Employee *, int empID);

int setEmpSalary(Employee *, int empID, float salary);
int getEmpSalary(Employee *, int empID, float *salary);
int setEmpJobType(Employee *, int empID, int job);
int getEmpJobType(Employee *, int empID, int *job);