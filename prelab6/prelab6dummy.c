#include "prelab6dummy.h"

List * initList(int* ec) {
    List * beginninghead = malloc(sizeof(List));
    if(beginninghead == NULL) {
        *ec = 1;
        return NULL;
    }
    beginninghead->object = NULL;
    beginninghead->next = NULL;
    *ec = 0;
    return beginninghead;
}

List * insertAtHead(void* object, List* linkedlist, int* ec) {
    List * newhead = malloc(sizeof(List));
    if(newhead == NULL) {
        *ec = 1;
        return linkedlist;
    }
    newhead->object = object;
    newhead->next = linkedlist->next;
    linkedlist->next = newhead;

    return linkedlist;
}

void * getAtIndex(int index, List* linkedlist) {
    int counter = 1;
    for(List * p = linkedlist->next; p != NULL;p = p->next) {
        if(counter == index) {
            return p->object;
        }
        counter++;
    }
    return NULL;
}

int getListLength(List* linkedlist) {
    int counter = 0;
    for(List * p = linkedlist->next; p != NULL; p = p->next) {
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