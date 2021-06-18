# include <stdio.h>
# include <stdlib.h>
# include "maxheap.h"

int main() {
    int n;
    process **collection;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    collection = (process **) malloc(n * sizeof(process *));


    for (int i = 0; i < n; i++) {
        collection[i] = (process *) malloc(sizeof(process));
        printf("Process %d \n", i + 1);
        collection[i]->pid = i + 1;

        printf("Enter the Arrival Time: ");
        scanf("%d", &((*(collection + i))->at));
        printf("Enter the Burst Time: ");
        scanf("%d", &((*(collection + i))->bt));

        printf("Enter the Priority: ");
        scanf("%d", &((*(collection + i))->priority));

        collection[i]->rem_bt = collection[i]->bt;
        collection[i]->ct = 0;
        collection[i]->tat = 0;
        collection[i]->wt = 0;
        collection[i]->state = 0;
    }

    sort(collection, 0, n - 1, "at", 'a', "priority");

    heap process_heap;
    process_heap.length = n + 1;
    process_heap.heap_size = 1;
    process_heap.arr = (process **) malloc(process_heap.length * sizeof(process *));

    int curr = 0;

    for (int i = 0; i < n; ++i) {
        if (collection[i]->at > curr) {
            curr = collection[i]->at;
        }

        for (int j = 0; j < n; ++j) {
            if (collection[j]->at <= curr && collection[j]->state == 0) {
                printf("Current Time : %d Process %d Queued\n", curr, collection[j]->pid);
                insert(&process_heap, collection[j]);
                printf("Size of Heap : %d\n", process_heap.heap_size - 1);
                collection[j]->state = 1;
            }
        }

        process *p = removeMax(&process_heap);
        curr += p->bt;
        p->ct = curr;
        p->tat = p->ct - p->at;
        p->wt = p->tat - p->bt;

    }

    while (process_heap.heap_size != 1) {
        process *p = removeMax(&process_heap);
        curr += p->bt;
        p->ct = curr;
        p->tat = p->ct - p->at;
        p->wt = p->tat - p->bt;
    }

    printf("Prio \t AT \t BT \t CT \t TAT \t WT\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d \n", collection[i]->pid);
        printf("%d \t %d \t %d \t %d \t %d \t %d\n", collection[i]->priority,collection[i]->at, collection[i]->bt, collection[i]->ct,
               collection[i]->tat, collection[i]->wt);
    }

    int wt = 0;
    int tat = 0;
    for (int i = 0; i < n; i++) {
        wt += collection[i]->wt;
        tat += collection[i]->tat;
    }

    float wt_avg = (float) wt / n;
    float tat_avg = (float) tat / n;

    printf("Average Waiting Time: %.2f\n", wt_avg);
    printf("Average Turn Around Time: %.2f", tat_avg);


    for (int i = 0; i < n; ++i) {
        free(collection[i]);
    }
    free(collection);
    free(process_heap.arr);
    return 0;

}