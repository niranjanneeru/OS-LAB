# include <stdio.h>
# include <stdlib.h>
# include "process.h"


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

        collection[i]->ct = 0;
        collection[i]->tat = 0;
        collection[i]->wt = 0;
    }

    sort(collection, 0, n - 1, "at", 'a',"fcfs");
    int curr = 0;
    if (collection[0]->at != 0) {
        curr = collection[0]->at;
    }

    for (int i = 0; i < n; ++i) {
        if (collection[i]->at > curr) {
            curr = collection[i]->at;
        }
        curr += collection[i]->bt;
        collection[i]->ct = curr;
        collection[i]->tat = collection[i]->ct - collection[i]->at;
        collection[i]->wt = collection[i]->tat - collection[i]->bt;
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