#include <stdio.h>
#include <stdlib.h>


typedef struct _Node {
	void *data;
	struct _Node *next;
} Node;

typedef struct{ 
    Node *head; 
} List;



List initList(int *ec);
void freeList(List list);
int insertAtHead(void*, List);
int insertAtTail(void*, List);
void * removeHead(List);
void * removeTail(List);
