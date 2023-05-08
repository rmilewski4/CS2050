#include <stdio.h>
#include <stdlib.h>

typedef struct listStruct { 
    void *object; 
    struct listStruct *next; 
} List;

typedef struct {
    int empID, jobType;
    float salary;
} Employee; 

void  initList(int*, List * dummy);

List  insertAtHead(void*, List, int*);

void * getAtIndex(int, List);

int getListLength(List);

List  freeList(List);

void readEmpRecordFromFile(FILE *fp, Employee *);

void freeEmployees(List);