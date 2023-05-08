/*****************************************************************************
 * CS2050
 * SP2022
 * Lab 7
 * By Ryan Milewski (rsmbby)
 * March 18, 2022
 *****************************************************************************/

#include "lab7.h"
//This function will start a linked list with a dummy node at the start of it.
Node * initList() {
    //We have to create our dummy node and check for malloc errors.
    Node * dummy = malloc(sizeof(Node));
    if(dummy == NULL) {
        return NULL;
    }
    //we then create a size variable that will be stored in the dummy node's data pointer and set it to zero.
    int * size = malloc(sizeof(int));
    *size = 0;
    dummy->data = size;
    //We then set our next pointer in our dummy node to NULL because the list is empty.
    dummy->next = NULL;
    //Finally, we return our dummy node to the user.
    return dummy;
}
//This function will take in a node pointer and return the size of the list without looping.
//There are no error conditions.
int getSize(Node *list) {
    //We create a size pointer that will hold our size variable hidden in list's dummy node.
    int * size;
    size = list->data;
    //Then we just return that value dereferenced.
    return *size;
}
//This function will take a node pointer, a void pointer holding user data, and an index variable at which the node will be inserted.
//If the index is invalid, such as when it is greater than the size of the list, then nothing will occur and 1 will be returned.
//IF the index is equal to the size of the list, the node will be inserted at the tail.
//On success, 0 will be returned.


//TODO: Fix inserting at head instead of tail when index = 0 and size = 1;
int insertAtIndex(Node *list, void *data, int index) {
    //We first check if the index is invalid, as if the index is greater than the size of the list, this is an error
    //If this is the case, we return 0.
    int size = getSize(list);
    if(index > size) {
        return 1;
    }
    //We have special behavior if the list is inserting at head (or 0 index), as we will need to directly modify our dummy node.
    if(index == 0) {
        //The following lines will be repeated throughout the function (I know, I should've used a separate function, oh well)
        //We create our node to be inserted, check for malloc errors.
        Node * nextnode = malloc(sizeof(Node));
        if(nextnode == NULL) {
            return 1;
        }
        //Set the data of the new node to the passed in data.
        nextnode->data = data;
        //We will modify our size by creating a temporary pointer to the dummy's data and adding one to it.
        int * sizeptr = list->data;
        *sizeptr= *sizeptr + 1;
        //We must also consider, if the size is 1 and index is 0, we need to insert at the tail instead of the head which is what this function will do, so we enter this if block
        if(size == 1) {
            //We then traverse to the tail of the list and find one node before the tail.
        Node * onebeforeindex = list;
        while(onebeforeindex->next != NULL) {
            onebeforeindex = onebeforeindex->next;
        }
        //We then set our next in our new node equal to the old node's next (NULL)
        nextnode->next = onebeforeindex->next;
        //And we set the previous node's next equal to the new node.
        onebeforeindex->next = nextnode;
        return 0;
        }
        //If we are just inserting at head, we will then just change our dummy' nodes next accordingly along with our new nodes next.
        //Because this is at the head, we set our next node's pointer equal to the old head of the list stored in the dummy.
        nextnode->next = list->next;
        //We then set the dummy node's head equal to our newly created node and return 0.
        list->next = nextnode;
        return 0;
    }
    //If the index is the same as size, we will insert at tail doing the following steps.
    if(index == size) {
        //Lines 71-77 are identical to above.
        Node * nextnode = malloc(sizeof(Node));
        if(nextnode == NULL) {
            return 1;
        }
        nextnode->data = data;
        int * sizeptr = list->data;
        *sizeptr= *sizeptr + 1;
        //We create a node that will be equal to one before the index.
        Node * onebeforeindex = list;
        //We do a while loop to search through until we find the node that is one before the end of the array.
        while(onebeforeindex->next != NULL) {
            onebeforeindex = onebeforeindex->next;
        }
        //We then set our next in our new node equal to the old node's next (NULL)
        nextnode->next = onebeforeindex->next;
        //And we set the previous node's next equal to the new node.
        onebeforeindex->next = nextnode;
        return 0;
    }
    //Finally, we arrive at the case when you are just inserting somewhere in the list
    //Lines 92-98 are same as above.
    Node * nextnode = malloc(sizeof(Node));
    if(nextnode == NULL) {
        return 1;
    }
    nextnode->data = data;
    int * sizeptr = list->data;
    *sizeptr= *sizeptr + 1;
    //We create a counter to compare to our index.
    int counter = 0;
    Node * onebeforeindex = list->next;
    //If our counter is equal to one before the index, exit the loop, otherwise keep traversing the linked list.
    while(counter != (index-1)) {
        onebeforeindex = onebeforeindex->next;
        counter++;
    }
    //Once we are at one before our index, we set our new node's next equal to the current index's next.
    nextnode->next = onebeforeindex->next;
    //We then set our one before index's next equal to our current node and return 0.
    onebeforeindex->next = nextnode;
    return 0;
}
//This function will take in a node pointer and an index and return the data at that index.
//NULL will be returned if the index is invalid.
void * getAtIndex(Node *list, int index) {
    Node * p;
    int size = getSize(list);
    //If the size is 0 or the index is greater than the size, this means the index is invalid, so we should return NULL.
    if(index > size || size == 0) {
        return NULL;
    }
    //We create a counter and traverse our linked list starting after the dummy node.
    int counter = 0;
    for(p = list->next;p->next != NULL; p = p->next) {
        //If our counter is equal to the index, return the data at that point
        if(counter == index) {
            return p->data;
        }
        counter++;
    }
    //Otherwise, return NULL.
    return NULL;
}

//This function will take a Node pointer and an index and return the data stored at the given index, while removing the node at that index and freeing its memory
//The function will return NULL if the index is invalid.
void * removeAtIndex(Node *list, int index) {
    int size = getSize(list);
    //same as above, check if index is within scope of list or if list is empty, if so return NULL
    if(index > size || size == 0) {
        return NULL;
    }
    //If we are removing the head of the list, special conditions are required.
    if(index == 0) {
        //We set our temp equal to the head of the list after the dummy.
        Node * temp = list->next;
        //We then set our dummy's next equal to the node following the one to be removed.
        list->next = temp->next;
        //Then we create a void pointer to hold the data, free the node that was removed
        void * data = temp->data;
        free(temp);
        //We decrease the size by 1 by doing the opposite of what was done in the funcitons above, and we return our data.
        int * sizeptr = list->data;
        *sizeptr= *sizeptr - 1;
        return data;
    }
    //If we aren't removing the head, these will be executed.
    int counter = 0;
    Node * onebeforeindex = list->next;
    //As above, we need the node preceding the one to be removed, so we use a while loop until we arrive at the given index.
    while(counter != (index-1)) {
        onebeforeindex = onebeforeindex->next;
        counter++;
    }
    //These will be similar to above, as we create a removed temp node.
    Node * removed = onebeforeindex->next;
    //Connect our linked list by setting the original next node equal to the node following the one to be removed
    onebeforeindex->next = removed->next;
    //We pull out our data from the node to be removed, and then we free that node.
    void * data = removed->data;
    free(removed);
    //We decrease our size by 1 then return our data.
    int * sizeptr = list->data;
    *sizeptr= *sizeptr - 1;
    return data;
}
//This function will return the data at the tail of the list, and remove the tail node. If the list is empty, NULL will be returned.
void * removeAtTail(Node *list) {
    //check for empty list, if so return NULL.
    if(list->next == NULL) {
        return NULL;
    }
    Node * priortoTail = list->next; //Starting at dummy node
    //We go until we are at 1 node before the tail
    while(priortoTail->next->next != NULL) {
        priortoTail = priortoTail->next;
    }
    //Then we do the same as above by pulling the data out, setting our next pointer equal to null since it's the new tail of the list
    Node * deleted = priortoTail->next;
    void * data = deleted->data;
    priortoTail->next = NULL;
    //free our deleted node, decrease size by 1, then return our data.
    free(deleted);
    int * sizeptr = list->data;
    *sizeptr= *sizeptr - 1;
    return data;
}

//This function will take in a list passed by reference (double *) and free all of the nodes associated with it, and when done set the passed list equal to NULL.
//If the list is empty, no action is preformed.
void freeList(Node **list) {
    //We check the size of the list and since we malloc'd a pointer to hold size in our dummy node, we create a temp variable to free it later.
    int size = getSize(*list);
    int * sizeptr = (*list)->data;
    if(size == 0) {
        //If our size is 0, we just free our size pointer, the list and exit the function.
        free(sizeptr);
        free(*list);
        *list = NULL;
        return;
    }
    //Otherwise we create a temp variable that will hold a node after we move onto the next node.
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
    //After all this is done, and the list is empty, we free our size pointer that was malloc'd in initList
    free(sizeptr);
    //As specified by the description, we then set our list pointer equal to NULL to know that there is no data associated with it anymore.
    *list = NULL;
}

//Helper function I created to print the list
void printList(Node * list) {
    if(getSize(list) == 0) {
        printf("The list is empty!\n");
    }
    int size = getSize(list);
    printf("The size of the list is %d!\n\n",size);
    int counter = 0;
    for(Node * p = list->next; p != NULL; p = p->next) {
        printf("Node %d\nCurrent Node is %p, holding %d, next node is %p\n\n",counter,p,*((int *)(p->data)),p->next);
        counter++;
    }
}