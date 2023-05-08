#include "prelab6.h"

List * initList(int* ec) {
    *ec = 0;
    return NULL;
}

List * insertAtHead(void* object, List* linkedlist, int* ec) {
    List * newhead = malloc(sizeof(List));
    if(newhead == NULL) {
        *ec = 1;
        return linkedlist;
    }
    newhead->object = object;
    newhead->next = linkedlist;
    return newhead;
}

void * getAtIndex(int index, List* linkedlist) {
    int counter = 1;
    for(List * p = linkedlist; p != NULL;p = p->next) {
        if(counter == index) {
            return p->object;
        }
        counter++;
    }
    return NULL;
}

int getListLength(List* linkedlist) {
    int counter = 1;
    for(List * p = linkedlist; p != NULL; p = p->next) {
        counter++;
    }
    return counter;
}


List * freeList(List* linkedlist) {
    List * temp;
    while(linkedlist != NULL) {
        temp = linkedlist;
        linkedlist = linkedlist->next;
        free(temp);
    }
    return linkedlist;
}

void readEmpRecordFromFile(FILE *fp, Employee * emp) {
    
    fscanf(fp, "%d, %d, %f",&emp->empID,&emp->jobType,&emp->salary);
}
void freeEmployees(List * linkedlist) {
    for(List * p = linkedlist; p != NULL; p = p->next) {
        free(p->object);
    }
}