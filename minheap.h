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
    int smallest = i;
    if (left <= h->heap_size && h->arr[left]->bt < h->arr[smallest]->bt) {
        smallest = left;
    }
    if (right <= h->heap_size && h->arr[right]->bt < h->arr[smallest]->bt) {
        smallest = right;
    }
    if (smallest != i) {
        process *temp = h->arr[i];
        h->arr[i] = h->arr[smallest];
        h->arr[smallest] = temp;
        heapify(h, smallest);
    }

}

void insert(heap *h, process *p) {
    h->arr[h->heap_size] = p;
    if (h->heap_size != 1) {
        heapify(h, h->heap_size / 2);
    }
    (h->heap_size)++;
}

process *removeMin(heap *h) {
    process * p = h->arr[1];
    h->heap_size--;
    h->arr[1] = h->arr[h->heap_size];
    if (h->heap_size != 1) {
        heapify(h, 1);
    }
    return p;
}