# include <stdio.h>
# include <stdlib.h>
# include "process.h"

typedef struct q {
    process *data;
    struct q *link;
} queue;

int isEmpty(queue *d) {
    if (NULL == d) {
        return 1;
    }
    return 0;
}

void enqueue(queue **front, queue **rear, process *val) {
    queue *next = (queue *) malloc(sizeof(queue));
    next->data = val;
    next->link = NULL;
    if (!*rear) {
        *front = next;
    } else {
        (*rear)->link = next;
    }
    *rear = next;
}

process * dequeue(queue ** front, queue ** rear){
    if(isEmpty(*front)){
        return NULL;
    }
    process  * p = (*front)->data;
    queue * ptr = *front;
    *front = (*front)->link;
    if(isEmpty(*front)){
        *rear = NULL;
    }
    free(ptr);
    return p;
}