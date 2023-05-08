#include "prelab8.h"


int main(void) {
    Queue q = queueInit();
    int ec = enqueue(NULL, q);
    printf("Size is %d\n",getQueueSize(q));
    ec = enqueue(NULL, q);
        printf("Size is %d\n",getQueueSize(q));
    dequeue(q);
        printf("Size is %d\n",getQueueSize(q));
    printf("EC = %d\n",ec);
    freeQueue(q);
}