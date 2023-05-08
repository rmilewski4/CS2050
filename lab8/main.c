#include "lab8.h"


int main(void) {
    int data = 7;
    Queue * q = initQueue();
    printf("Queue size is %d\n",getSize(q));
    if(peek(q) == NULL ) {
        printf("Peek working\n");
    }
    if(deQueue(q) == NULL) {
        printf("Dequeue working when queue empty\n");
    }

    enQueue(q, &data);
    printf("Queue size is %d\n",getSize(q));
    if(peek(q) == &data) {
        printf("Peek working correctly!\n");
    }
    int moredata = 10;
    enQueue(q, &moredata);
    printf("Enqueing\nQueue size is %d\n",getSize(q));
    int * dataptr = deQueue(q);
    if(dataptr == &data) {
        printf("DEQUEUE WORKING!\n");
    }
    printf("Dequeing\nQueue size is %d\n",getSize(q));
    if(peek(q) == &moredata) {
        printf("Peek still working correctly!\n");
    }
    int * moredataptr = deQueue(q);
    if(moredataptr == &moredata) {
        printf("DEQUEUE WORKING!\n");

    }
    printf("Queue size is %d\n",getSize(q));
    freeQueue(q);
}