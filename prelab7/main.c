#include "prelab7.h"

int main(void) {
    int ec;
    List list = initList(&ec);
    if(ec == 1) {
        printf("ERROR!\n");
    }
    int data = 5;
    removeTail(list);
    insertAtTail(&data,list);
    removeTail(list);
    insertAtHead(&data, list);
    removeTail(list);
    removeHead(list);
    data = 7;
    insertAtHead(&data,list);
    insertAtTail(&data,list);
    freeList(list);
}