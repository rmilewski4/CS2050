#include "prelab5.h"

Employee * readEmployeeArray(FILE *fp) {
    int size = 0;
    fscanf(fp,"%d",&size);
    int * emparray = malloc(sizeof(Employee)*size + sizeof(int));
    if(emparray==NULL) {
        return NULL;
    }
    emparray[0] = size;
    emparray++;
    Employee * array = (Employee *) emparray;
    for(int i = 0; i<size;i++) {
        fscanf(fp, "%d, %d, %f",&array[i].empID,&array[i].jobType,&array[i].salary);
    }
    return((Employee *) emparray);
}

int getEmployeeSize(Employee * arr) {
    int * intarray = (int *) arr;
    return(intarray[-1]);
}



void freeEmployeeArray(Employee * arr) {
    int * intarray = (int *) arr;
    intarray--;
    arr = (Employee *) intarray;
    free(arr);
}

Employee * getEmployeeByID(Employee * arr, int empID) {
    int size = getEmployeeSize(arr);
    for(int i = 0; i<size;i++) {
        if(arr[i].empID == empID) {
            return &arr[i];
        }
    }
    return NULL;
}

int setEmpSalary(Employee * arr, int empID, float salary) {
    arr = getEmployeeByID(arr,empID);
    if(arr==NULL) {
        return 1;
    }
    arr->salary = salary;
    return 0;
}
int getEmpSalary(Employee * arr, int empID, float *salary) {
    arr = getEmployeeByID(arr,empID);
    if(arr==NULL) {
        return 1;
    }
    *salary = arr->salary;
    return 0;
}

int setEmpJobType(Employee * arr, int empID, int job) {
    arr = getEmployeeByID(arr,empID);
    if(arr==NULL) {
        return 1;
    }
    arr->jobType = job;
    return 0; 
}

int getEmpJobType(Employee * arr, int empID, int *job) {
    arr = getEmployeeByID(arr,empID);
    if(arr==NULL) {
        return 1;
    }
    *job = arr->jobType;
    return 0;
}