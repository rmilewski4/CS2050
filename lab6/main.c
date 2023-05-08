
#include "lab6.h"


int main(void) {
    Node * head = initList();
    Car * newdata = NULL;
    printf("The size of the list is %d\n",getSize(head));
    newdata = removeFromHead(&head);
    if(newdata == NULL) {
        printf("list is empty!\n");
    }
    freeList(&head);
    newdata = getWithLeastMilesDriven(head);
    if(newdata == NULL) {
        printf("List is empty!\n");
    }
    printCars(head);
    int data = 5;
    int ec = 0;
    //Car * temp = malloc(sizeof(Car));
    for(int i = 0; i< 5; i++) {
        Car * temp = malloc(sizeof(Car));
        temp->milesDriven = i + 100;
        temp->numberOfAccidents = i;
        temp->vin = i;
        if(i == 3) {
            temp->milesDriven = 5;
        }
        ec = insertAtHead(&head,temp);
        if(ec == 1) {
            printf("ERROR!\n");
        }
        data--;
    }
    printf("The size of the list is %d\n",getSize(head));
    printCars(head);
    newdata = getWithLeastMilesDriven(head);
    printf("The car with the lowest miles driven was:\n");
    printf("VIN = %d, milesDriven = %f, numberOfAccidents = %d\n",newdata->vin,newdata->milesDriven,newdata->numberOfAccidents);


    newdata = removeFromHead(&head);
    printf("The data thtat was removed is:\n");
    printf("VIN = %d, milesDriven = %f, numberOfAccidents = %d\n",newdata->vin,newdata->milesDriven,newdata->numberOfAccidents);
    free(newdata);
    printf("The size of the list is %d\n",getSize(head));
    printCars(head);
    Node * temphead = head;
    for(int i = 0; i < 4; i++) {
        free(temphead->data);
        temphead = temphead->next;
    }
    freeList(&head);
    printf("The size of the list is %d\n",getSize(head));
    newdata = removeFromHead(&head);
    if(newdata == NULL) {
        printf("list is empty!\n");
    }
    freeList(&head);
    newdata = getWithLeastMilesDriven(head);
    if(newdata == NULL) {
        printf("List is empty!\n");
    }
    printCars(head);
    
}