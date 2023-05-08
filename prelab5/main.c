#include "prelab5.h"

int main(void) {
    FILE * fp;
    fp = fopen("employee.txt","r");
    if(fp == NULL) {
        printf("Could not open file!");
        return EXIT_FAILURE;
    }
    Employee * array = readEmployeeArray(fp);
    fclose(fp);
    printf("The size is %d\n",getEmployeeSize(array));
    Employee * individualemp = getEmployeeByID(array, 10);
    if(individualemp == NULL) {
        printf("Could not find that employee!\n");
    }
    else {
        printf("The employee is %d, their job type is %d, their salary is %f\n",individualemp->empID, individualemp->jobType, individualemp->salary);
    }
    setEmpJobType(array,10,5);
    setEmpSalary(array,10,205234.4);
    individualemp = getEmployeeByID(array, 10);
    if(individualemp == NULL) {
        printf("Could not find that employee!\n");
    }
    else {
        printf("The employee is %d, their job type is %d, their salary is %f\n",individualemp->empID, individualemp->jobType, individualemp->salary);
    }
    freeEmployeeArray(array);
}