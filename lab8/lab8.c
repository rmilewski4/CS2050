/*****************************************************************************
 * CS2050
 * SP2022
 * Lab 8
 * By Ryan Milewski (rsmbby)
 * March 25, 2022
 *****************************************************************************/

/*****************************************************************
* NOTE*** This lab is going to replace my grade for lab 9 (Lab on 4/8) due to me having to travel with a competition team on campus.
* I have asked John if this is okay, and he approved it, but please contact me if there is an issue 
***************************************************************************/
#include "lab8.h"

// -------------------------------- STRUCT DEFINITIONS

typedef struct Node Node;

// suggested implementation (I chose to use these structs as they were given)
struct Queue {
	int size;
	Node *head;
	Node *tail;
};

struct Node {
	void *data;
	Node *next;
};

//This function will return an empty Queue pointer to be mainpulated later. NULL will be returned on error
//This function has O(1) complexity.
Queue * initQueue() {
	//We malloc space for our inital queue struct
	Queue * q = malloc(sizeof(Queue));
	//If malloc fails, return NULL.
	if(q == NULL) {
		return NULL;
	}
	//We then initalize all of the variables stored inside of Queue. We set our size equal to 0 since the Queue is empty
	//We also set our head and tail pointers to NULL to point out an empty Queue.
	q->size = 0;
	q->head = NULL;
	q->tail = NULL;
	//Finally, we return our newly initalized queue that is empty.
	return q;
}
//This function will take in a queue pointer and return the size of the queue that is given. There are no error conditions.
//This function has O(1) complexity.
int getSize(Queue *q) {
	//All we are doing here is returning the size of the queue that was hidden in the implementation of queue itself.
	//Since this is a getter function, we hide the implemention of the function from the user.
	return q->size;
}
//This function will take in a queue pointer and a pointer to some type of data, It will place the data onto the back of the queue.
//On error, 1 will be returned, and 0 will be returned on success.
//This function has O(1) complexity.
int enQueue(Queue *q, void *data) {
	//We malloc space for our new node and check for malloc errors. If errors are found, return 1 as indicated.
	Node * node = malloc(sizeof(Node));
	if(node == NULL) {
		return 1;
	}
	//We set our data into the pointer here, as this is what's most important.
	node->data = data;
	//Since data is always added to the back of the queue, our linked list holding the data will always add data to the rear of the linked list.
	//This means that whatever data is added will have its next pointer equal to NULL since it is at the back.
	node->next = NULL;
	//If the size of the queue is 0, we need to perform special conditions.
	if(q->size == 0) {
		//Since the queue is empty, and head and tail hold NULL we just need to modify the head and tail to hold the newly created node
		//Because the queue will be of size 1, the new node will be both the head and tail of the queue.
		q->head = node;
		q->tail= node;
		//And of course, we need to increase our size by 1 for our Queue, and then return our data code for success.
		q->size += 1;
		return 0;
	}
	//If the size isn't 0, then we already have a tail, so we create a Node variable to hold it and set our current tail inside.
	Node * curTail = q->tail;
	//We increase our size by 1 for the Queue.
	q->size += 1;
	//We then set our current tail's next pointer equal to the address of our newly created node (meaning that the old tail is now pointing to the new tail)
	curTail->next = node;
	//We then update our tail equal to our new tail and return our success code.
	q->tail = node;
	return 0;
}
//This function will take a queue pointer and return the data that is being held at the front of the queue.
//NULL will be returned if the queue is empty. THE DATA IS NOT FREED FROM THE QUEUE AND REMAINS AT THE FRONT
//This function has O(1) complexity.
void * peek(Queue *q){
	//Check if the queue is empty and if so, return NULL
	if(q->size == 0) {
		return NULL;
	}
	//Otherwise, we just return the data that is currently being stored at the head (or front) of the queue.
	return q->head->data;
}

//This function will take a queue pointer and remove the data at the front of queue and return it. The queue will then be shifted and 
//The data behind it will become the front. If the queue is empty, NULL is returned.
//This function has O(1) complexity.
void * deQueue(Queue *q) {
	//Check if queue is empty, and return NULL if so.
	if(q->size == 0) {
		return NULL;
	}
	//Create a temporary node that will hold the node that is being removed.
	Node * removed = q->head;
	//We then set our head equal to the node following the node to be removed.
	q->head = removed->next;
	//We also have to check if the queue is only holding 1 value, because if so the tail was also removed and would be holding the address of a variable that was freed.
	if(q->size == 1) {
		//So if this is the case, update the tail to the removed's next pointer as well (Which would be setting it equal to NULL)
		q->tail = removed->next;
	}
	//We create a variable to hold the data that is being stored in the node so we can free the node.
	void * data = removed->data;
	//We then free the node and decrease our size by 1 since a node was removed.
	free(removed);
	q->size -= 1;
	//Finally we return the data that was just freed.
	return data;
}

//This function will take a queue pointer and free any memory that was allocated to the queue. Nothing is returned
//This is the only function that has O(N) complexity.
void freeQueue(Queue *q) {
	//We create a temp variable that will hold our head pointer
	Node * p = q->head;
	//We then check while the variable is not NULL (i.e. not at the end of the Queue)
	while(p != NULL) {
		//While this is the case, another temp is created to hold the node to be deleted.
		Node * temp = p;
		//We then move our p to the next node in the queue, and then free the original head of the Queue, and repeat this til the queue is empty.
		p = p->next;
		free(temp);
	}
	//Once the Queue is freed, we also need to free our queue variable that was passed in, since it was malloc'd in the first place.
	free(q);
}