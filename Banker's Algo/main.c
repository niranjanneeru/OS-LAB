# include <stdio.h>
# include <stdlib.h>
# include "bankers.h"

int main() {
    int p, r;

    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    int **need;
    int **max;
    int **allocation;
    int *available;
    int *finish;
    int *work;
    int *request;

    need = (int **) malloc(p * sizeof(int *));
    max = (int **) malloc(p * sizeof(int *));
    allocation = (int **) malloc(p * sizeof(int *));
    finish = (int *) calloc(p, sizeof(int));
    available = (int *) malloc(r * sizeof(int));
    work = (int *) malloc(r * sizeof(int));
    request = (int *) malloc(r * sizeof(int));


    printf("Enter Max Allocation Data\n");
    for (int i = 0; i < p; ++i) {
        printf("Enter Max Allocation Data for Process %d\n", i + 1);
        max[i] = (int *) malloc(r * sizeof(int));
        for (int j = 0; j < r; ++j) {
            printf("Enter the Resource %d Allocation Data: ", j + 1);
            scanf("%d", (*(max + i)) + j);
        }
    }

    printf("Enter Allocated Data\n");
    for (int i = 0; i < p; ++i) {
        printf("Enter Allocated Data for Process %d\n", i + 1);
        allocation[i] = (int *) malloc(r * sizeof(int));
        for (int j = 0; j < r; ++j) {
            printf("Enter the Allocated Resource %d Data: ", j + 1);
            scanf("%d", (*(allocation + i)) + j);
        }
    }

    printf("Enter Available Resources Data\n");
    for (int i = 0; i < r; ++i) {
        printf("Enter Available Data for Resource %d: ", i + 1);
        scanf("%d", (available + i));
        work[i] = available[i];
    }

    for (int i = 0; i < p; ++i) {
        need[i] = (int *) malloc(r * sizeof(int));
        for (int j = 0; j < r; ++j) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    if (!(bankers(allocation, need, finish, work, p, r))) {
        printf("\nDeadlock\n");
    }

    system("clear");

    printSysSnap(max,allocation,need,available,p,r);

    free(finish);
    for (int i = 0; i < r; ++i) {
        work[i] = available[i];
    }
    finish = (int *) calloc(p, sizeof(int));
    int choice = 1;
    int snap_choice = 0;
    int pid;
    int n_flag = 0;
    int a_flag = 0;
    while (choice) {
        printf("Do you want to perform Resource Request Algorithm? ( 1 / 0 ): ");
        scanf("%d", &choice);
        if (choice) {
            printf("Enter the process for which you want to perform the Algorithm: ");
            scanf("%d", &pid);
            if (!(pid > 0 && pid <= p)) {
                printf("Invalid PID\n");
                continue;
            }
            for (int i = 0; i < r; ++i) {
                printf("Enter Request for Resource %d: ", i + 1);
                scanf("%d", request + i);
                if (request[i] <= need[pid - 1][i]) {
                    n_flag++;
                }
                if (request[i] <= available[i]) {
                    a_flag++;
                }
            }
            if (n_flag != r) {
                printf("Error: Process has exceeded it's claim\n");
                continue;
            }
            if (a_flag != r) {
                printf("Error: Process has requested for more than the available resource\n");
                continue;
            }
            for (int i = 0; i < r; ++i) {
                available[i] -= request[i];
                allocation[pid - 1][i] += request[i];
                need[pid-1][i] -= request[i];
            }
            if (!(bankers(allocation, need, finish, work, p, r))) {
                printf("\nRequest can't be handled since it leads to an unsafe state\n");
            } else {
                printf("\nRequest can be handled\n");
            }
            printf("Do you want to print the System Snap Shot? (1/0): ");
            scanf("%d",&snap_choice);
            if(snap_choice){
                printSysSnap(max,allocation,need,available,p,r);
            }
            for (int i = 0; i < r; ++i) {
                available[i] += request[i];
                allocation[pid - 1][i] -= request[i];
                need += request[i];
            }
        }
    }

    printf("Exiting...");


    for (int i = 0; i < p; ++i) {
        free(max[i]);
        free(allocation[i]);
        free(need[i]);
    }
    free(need);
    free(max);
    free(allocation);
    free(available);
    free(request);

    return 0;
}