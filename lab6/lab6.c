/*****************************************************************************
 * CS2050
 * SP2022
 * Lab 6
 * By Ryan Milewski (rsmbby)
 * March 11, 2022
 *****************************************************************************/

#include "lab6.h"

//This function does not accept any parameters and will return an empty list pointer. There are no possibilties for errors.
Node * initList() {
    //All we need to do is return NULL since we aren't using a placeholder node (or dummy node).
    return NULL;
}

//This function will accept a list pointer as a parameter and return how long the linked list is by number of nodes
//If the list is empty, then it will return 0.
int getSize(Node *list) {
    //Checking if the list is empty and if so, return a size of 0.
    if(list == NULL) {
        return 0;
    }
    //Otherwise, we are going to traverse the linked list using a for loop and a counter, and add 1 to the counter for each node we encounter
    int counter = 0;
    for(Node * p = list; p != NULL; p = p->next) {
        counter++;
    }
    //Finally, we just return our count that we got from the for loop.
    return counter;
}
//This function will take a list node that has been passed by reference (or another pointer to it), and some pointer that holds data and will create a new node that will become the head of the list.
//The function will return 0 on success or 1 on error.
int insertAtHead(Node **list, void *data) {
    //A note: I don't need to check if *list is null because I take adavantage of it being NULL and setting this NULL equal to our first node's next value, and the code works even when the list is empty.
    //We create our new node using malloc and check if it has been correctly allocated. If it has not been correctly allocated, return 1 and exit the function.
    Node * newHead = malloc(sizeof(Node));
    if(newHead == NULL ) {
        return 1;
    }
    //We will add our user data to the newly created node by setting the data pointer in newHead to the passed in data.
    newHead->data = data;
    //Since this node is being added to the beginning of the list, it will become the new "head" of the list. This means that the former "head" of the list will become the next pointer in our new head.
    newHead->next = *list;
    //Finally, we set our original list equal to the newHead pointer and because it is passed by reference, the user will recieve their modified list with the new data at the head of the list.
    *list = newHead;
    //And of course, because we didn't encounter any errors, we are able to leave the function with a success code (or 0).
    return 0;
}

//This function will take a list that was passed by reference (double *) and will remove the head of the list. The function will then return the data that was held in the deleted node.
//If the list is unpopulated and has no nodes, NULL will be returned.
void * removeFromHead(Node **list) {
    //First we check if the list is empty and if so, we return NULL.
    if(*list == NULL) {
        return NULL;
    }
    //We create a temp node that will hold the head of the list that will be deleted.
    Node * temp = *list;
    //We then need a pointer that will hold the data that will be returned, because otherwise the pointer will be lost if we free the node itself.
    void * data = (temp)->data;
    //We then move our list "head" to the node that follows the deleted node by referencing its next pointer and setting it equal as the new head.
    *list = (*list)->next;
    //After all of this is done, we are able to free our newly deleted node and return the data that was formerly inside of it.
    free(temp);
    return data;
}
//This function will take in a list passed by reference (double *) and free all of the nodes associated with it, and when done set the passed list equal to NULL.
//If the list is empty, no action is preformed.
void freeList(Node **list) {
    //If the list is empty, we preform no action and just exit the function.
    if(*list == NULL) {
        return;
    }
    //We create a temp variable that will hold a node after we move onto the next node.
    Node * temp;
    //While the list is not equal to NULL (no more nodes left), do this:
    while(*list != NULL) {
        //Set our temp equal to the head that is about to be freed so we can move onto the next pointer inside of it before we free it and it is lost.
        temp = *list;
        //Set our list equal to the next node in the list.
        *list = (*list)->next;
        //Finally, we are able to free our node that is no longer associated with the list and continue on until the list is empty.
        free(temp);
    }
    //As specified by the description, we then set our list pointer equal to NULL to know that there is no data associated with it anymore.
    *list = NULL;
}




//CAR FUNCTIONS

//The function takes in a single Car pointer and returns the vin number of that car.
int getVin(Car *car) {
    //Since car is a pointer, we need to use the arrow operator to access the vin, then all we do is return that number we retrieved with the points to operator.
    return car->vin;
}

//This function takes in a single car pointer and returns the number of miles driven on that car.
float getMilesDriven(Car *car) {
    //Similar to the other getter, we use the arrow operator to access the milesDriven element and return it to the calling program.
    return car->milesDriven;
}

//This function takes in a single car pointer and returns the number of accidents that that car has been in.
int getNumberOfAccidents(Car *car) {
    //Just like the other getters, we use the arrow operator and return the number of accidents by that car in 1 line.
    return car->numberOfAccidents;
}


//This function will take in a list pointer and return the car pointer that has the least number of miles driven. If the list is empty, NULL will be returned.
Car * getWithLeastMilesDriven(Node *list) {
    //Check if the list is NULL and if so, return NULL.
    if(list == NULL) {
        return NULL;
    }
    //We create a temporary Car pointer and set it equal to NULL.
    Car * leastDrivenCar = NULL;
    //Set our listDrivenCar equal to the car pointer stored at the head for our comparisons.
    leastDrivenCar = list->data;
    //We are now able to traverse our list.
    for(Node * p = list; p != NULL; p = p->next) {
        //We use our getter functions here and compare if the MilesDriven of the current leastDrivenCar is greater than the milesDriven of the current node of the list.
        if(getMilesDriven(leastDrivenCar) > getMilesDriven(p->data)) {
            //If this ends up being the case, we have a new car that has the lowest amount of miles driven, so we set that car's pointer inside of our leastDrivenCar Variable.
            leastDrivenCar = p->data;
        }
    }
    //Finally, after we traverse our list, we return our LeastDrivenCar variable that is now holding the car with the least miles driven.
    return leastDrivenCar;
}

//This function will accept a list pointer as a condition and print the cars that it holds as its data. If the list is empty, then the function will produce a message and do nothing else.
void printCars(Node *list) {
    //Check if the list is empty and if so alert the user to this and leave the function.
    if(list == NULL) {
        printf("There are no nodes in the list!\n");
        return;
    }
    //We use a counter to label each of our nodes as to not get confused between them.
    int counter = 0;
    //Traverse the linked list using a for loop.
    for(Node * p = list; p!=NULL; p = p->next) {
        //When we are traversing our list, we just use our getter functions to print each member of the struct for each member of the list.
        printf("Node %d: VIN = %d, milesDriven = %f, numberOfAccidents = %d\n",counter,getVin(p->data),getMilesDriven(p->data),getNumberOfAccidents(p->data));
        //And of course, we need to add one to our counter.
        counter++;
    }
}