
#include "lab7.h"
void printList(Node * list);
int main(void) {
    Node * head = initList();
    int data = 7;
    /*int ec = 0;
    ec = insertAtIndex(head,&data, 5);
    if(ec == 1) {
        printf("ERROR!\n");
    }
    printList(head);
    ec = insertAtIndex(head, &data, 0);
    if(ec == 1) {
        printf("ERROR!\n");
    }*/
    printList(head);
    //removeAtIndex(head,0);
    insertAtIndex(head,&data,0);
    printList(head);
    //int size = getSize(head);
    //printf("The size is %d\n", size);
    insertAtIndex(head,&data,0);
    int newdataindex = 10;
    insertAtIndex(head,&data,1);
    insertAtIndex(head,&newdataindex,1);
    int * dataatindex;
    dataatindex = getAtIndex(head, 1);
    printf("Data at index 1 is %d\n",*dataatindex);
    printList(head);
    insertAtIndex(head,&newdataindex,0);
    printf("Added node at 0\n");
    printList(head);
    printf("Removed node at 0\n");
    removeAtIndex(head,0);
    printList(head);
    printf("Removed node at 2\n");
    removeAtIndex(head,2);
    printList(head);
    //size = getSize(head);
   // printf("The size is %d\n", size);
    freeList(&head);
}