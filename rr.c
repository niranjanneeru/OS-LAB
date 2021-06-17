# include <stdio.h>
# include <stdlib.h>
# include "queue.h"

int main() {
    int n,tq;
    process **collection;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    collection = (process **) malloc(n * sizeof(process *));

    printf("Enter the Time Quantum for the Algorithm: ");
    scanf("%d",&tq);

    for (int i = 0; i < n; i++) {
        collection[i] = (process *) malloc(sizeof(process));
        printf("Process %d \n", i + 1);
        collection[i]->pid = i + 1;

        printf("Enter the Arrival Time: ");
        scanf("%d", &((*(collection + i))->at));
        printf("Enter the Burst Time: ");
        scanf("%d", &((*(collection + i))->bt));

        collection[i]->rem_bt = collection[i]->bt;
        collection[i]->ct = 0;
        collection[i]->tat = 0;
        collection[i]->wt = 0;
        collection[i]->state = 0;
    }

    sort(collection, 0, n - 1, "at", 'a', "rr");

    queue *front = NULL;
    queue *rear = NULL;

    int rem = n;

    int curr = 0;
    if (collection[0]->at != 0) {
        curr = collection[0]->at;
    }

    enqueue(&front, &rear, collection[0]);
    printf("Current Time : %d Process %d Queued with remaining BURST TIME = %d\n", curr, collection[0]->pid,collection[0]->rem_bt);
    collection[0]->state = 1;

    while (rem || !isEmpty(front)) {
        process *p = NULL;
        if (!isEmpty(front)) {
            p = dequeue(&front, &rear);
            if (p->rem_bt > tq) {
                p->rem_bt -= tq;
                curr += tq;
            } else {
                curr += (p->rem_bt);
                p->rem_bt = 0;
                p->ct = curr;
                p->tat = p->ct - p->at;
                p->wt = p->tat - p->bt;
                p = NULL;
                rem--;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (collection[i]->at <= curr && collection[i]->state == 0) {
                printf("Current Time : %d Process %d Queued with remaining BURST TIME = %d\n", curr, collection[i]->pid,collection[i]->rem_bt);
                enqueue(&front, &rear, collection[i]);
                collection[i]->state = 1;
            }
        }
        if (p != NULL) {
            enqueue(&front, &rear, p);
            printf("Current Time : %d Process %d Queued with remaining BURST TIME = %d\n", curr, p->pid,p->rem_bt);
        }
        if(isEmpty(front)){
            if(rem !=0){
                curr++;
            }
        }
    }


    printf("AT \t BT \t CT \t TAT \t WT\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d \n", collection[i]->pid);
        printf("%d \t %d \t %d \t %d \t %d\n", collection[i]->at, collection[i]->bt, collection[i]->ct,
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

    return 0;

}