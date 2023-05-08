#include "prelab6dummypbv.h"

void  initList(int* ec, List * dummy) {
    dummy->next = NULL;
    *ec = 0;
}

List  insertAtHead(void* object, List dummy, int* ec) {
    List * newhead = malloc(sizeof(List));
    if(newhead == NULL) {
        *ec = 1;
        return dummy;
    }
    newhead->object = object;
    newhead->next = dummy.next;
    dummy.next = newhead;
    *ec = 0;
    return dummy;
}

void * getAtIndex(int index, List linkedlist) {
    int counter = 1;
    for(List * p = linkedlist.next; p != NULL;p = p->next) {
        if(counter == index) {
            return p->object;
        }
        counter++;
    }
    return NULL;
}

int getListLength(List linkedlist) {
    int counter = 1;
    for(List * p = linkedlist.next; p != NULL; p = p->next) {
        counter++;
    }
    return counter;
}


List  freeList(List dummy) {
    List * temp;
    List * linkedlist = dummy.next;
    while(linkedlist != NULL) {
        temp = linkedlist;
        linkedlist = linkedlist->next;
        free(temp);
    }
    return dummy;
}

void readEmpRecordFromFile(FILE *fp, Employee * emp) {
    
    fscanf(fp, "%d, %d, %f",&emp->empID,&emp->jobType,&emp->salary);
}
void freeEmployees(List  linkedlist) {
    for(List * p = linkedlist.next; p != NULL; p = p->next) {
        free(p->object);
    }
}