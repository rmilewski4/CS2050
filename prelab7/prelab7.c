#include "prelab7.h"
//DONE WITHOUT TAIL POINTER.
//TODO: With tail pointer.

List initList(int *ec) {
    List data;
    Node * head = malloc(sizeof(Node));
    if(head == NULL) {
        *ec = 1;
        data.head = NULL;
        return data;
    }
    data.head = head;
    data.head->next = NULL;
    *ec = 0;
    return data;

}

int insertAtHead(void* data, List list) {
    Node * newhead = malloc(sizeof(Node));
    if(newhead == NULL) {
        return 1;
    }
    Node * currenthead = list.head->next;

    newhead->data = data;
    newhead->next = currenthead;
    list.head->next = newhead;
    return 0;
}

int insertAtTail(void* data, List list) {
    Node * p = list.head->next;
    if(p == NULL) {
        int otherec = insertAtHead(data,list);
        return otherec;
    }
    while(p->next != NULL) {
        p = p->next;
    }
    Node * newtail = malloc(sizeof(Node));
    if(newtail == NULL) {
        return 1;
    }
    newtail->next = NULL;
    newtail->data = data;
    p->next = newtail;
    if(list.head->next == NULL) {
        list.head->next = newtail;
    }
    return 0;
}
void * removeHead(List list) {
    //First we check if the list is empty and if so, we return NULL.
    if(list.head->next == NULL) {
        return NULL;
    }
    //We create a temp node that will hold the head of the list that will be deleted.
    Node * temp = list.head->next;
    //We then need a pointer that will hold the data that will be returned, because otherwise the pointer will be lost if we free the node itself.
    void * data = (temp)->data;
    //We then move our list "head" to the node that follows the deleted node by referencing its next pointer and setting it equal as the new head.
    list.head->next = (temp)->next;
    //After all of this is done, we are able to free our newly deleted node and return the data that was formerly inside of it.
    free(temp);
    return data;
}

void * removeTail(List list) {
    if(list.head->next == NULL) {
        return NULL;
    }
    Node * priortoTail = list.head; //Starting at dummy node
    while(priortoTail->next->next != NULL) {
        priortoTail = priortoTail->next;
    }
    Node * deleted = priortoTail->next;
    void * data = deleted->data;
    priortoTail->next = NULL;
    free(deleted);
    return data;
}

void freeList(List list) {
    Node * temp;
    while((list.head)->next != NULL) {
        temp = list.head->next;
        list.head->next = temp->next;
        free(temp);
    }
    free(list.head);
}