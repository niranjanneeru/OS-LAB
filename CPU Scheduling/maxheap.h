# include <stdio.h>
# include <stdlib.h>
# include "process.h"


typedef struct {
    int length;
    int heap_size;
    process **arr;
} heap;

void heapify(heap *h, int i) {
    int left = 2 * i;
    int right = left + 1;
    int largest = i;
    if (left <= h->heap_size && h->arr[left]->priority > h->arr[largest]->priority) {
        largest = left;
    }
    if (right <= h->heap_size && h->arr[right]->priority > h->arr[largest]->priority) {
        largest = right;
    }
    if (largest != i) {
        process *temp = h->arr[i];
        h->arr[i] = h->arr[largest];
        h->arr[largest] = temp;
        heapify(h, largest);
    }

}

void insert(heap *h, process *p) {
    h->arr[h->heap_size] = p;
    if (h->heap_size != 1) {
        heapify(h, h->heap_size / 2);
    }
    (h->heap_size)++;
}

process *removeMax(heap *h) {
    process * p = h->arr[1];
    h->heap_size--;
    h->arr[1] = h->arr[h->heap_size];
    if (h->heap_size != 1) {
        heapify(h, 1);
    }
    return p;
}