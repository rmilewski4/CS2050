#include "prelab8.h"

int getQueueErrorCode(Queue queue) {
    return queue.info->ec;
}

Queue queueInit() {
    Queue queue;
    QueueInfo * info = malloc(sizeof(QueueInfo));
    if(info == NULL) {
        return queue;
    }
    queue.info = info;
    queue.info->head = NULL;
    queue.info->tail = NULL;
    queue.info->size = 0;
    queue.info->ec = 0;
    return queue;
}

int enqueue(void * data, Queue queue) {
    Node * node = malloc(sizeof(Node));
    if(node == NULL) {
        queue.info->ec = 1;
        return 1;
    }
    node->data = data;
    node->next = NULL;
    if(queue.info->size == 0) {
        queue.info->head = node;
        queue.info->tail = node;
        queue.info->size += 1;
        queue.info->ec = 0;
        return 0;
    }
    Node * tail = queue.info->tail;
    tail->next = node;
    queue.info->tail = node;
    queue.info->size += 1;
    queue.info->ec = 0;
    return 0;

}

void * dequeue(Queue queue) {
    if(queue.info->size == 0) {
        queue.info->ec = 2;
        return NULL;
    }
    Node * remove = queue.info->head;
    queue.info->head = remove->next;
    if(queue.info->size == 1) {
        queue.info->tail = remove->next;
    }
    void * data = remove->data;
    free(remove);
    queue.info->size -= 1;
    return data;
}

int getQueueSize(Queue queue) {
    return queue.info->size;
}

void freeQueue(Queue queue) {
    Node * p = queue.info->head;
    while(p != NULL) {
        Node * temp = p;
        p = p->next;
        free(temp);
    }
    free(queue.info);
}