# include <stdio.h>
# include <stdlib.h>

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

    need = (int **) malloc(p * sizeof(int *));
    max = (int **) malloc(p * sizeof(int *));
    allocation = (int **) malloc(p * sizeof(int *));
    finish = (int *) calloc(p, sizeof(int));
    available = (int *) malloc(r * sizeof(int));
    work = (int *) malloc(r * sizeof(int));


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


    system("clear");

    int end = 1;
    int flag;
    int indic = 1;
    printf("Safe Sequence: ");
    int procs = p;
    while (end) {
        for (int i = 0; i < p; ++i) {
            flag = 0;
            indic = 1;
            if (!finish[i]) {
                for (int j = 0; j < r; ++j) {
                    if (work[j] >= need[i][j]) {
                        flag++;
                    }
                }
                if (flag == r) {
                    printf("P%d ", i + 1);
                    finish[i] = 1;
                    procs--;
                    for (int j = 0; j < r; ++j) {
                        work[j] += allocation[i][j];
                    }
                    indic = 0;
                }
            }
        }
        if (indic) {
            if (procs != 0) {
                printf("Deadlock");
            }
            end = 0;
        }
    }

    printf("\nSystem Snapshot\n");
    for (int i = 0; i < r; ++i) {
        printf("\t R%d", i + 1);
    }
    printf("\t");
    for (int i = 0; i < r; ++i) {
        printf("\t R%d", i + 1);
    }
    printf("\t");
    for (int i = 0; i < r; ++i) {
        printf("\t R%d", i + 1);
    }
    printf("\t");
    for (int i = 0; i < r; ++i) {
        printf("\t R%d", i + 1);
    }
    printf("\n");
    for (int i = 0; i < p; ++i) {
        printf("P%d\t", i + 1);
        for (int j = 0; j < r; ++j) {
            printf("%d\t", *((*(max + i)) + j));
        }
        printf("\t");
        for (int j = 0; j < r; ++j) {
            printf("%d\t", *((*(allocation + i)) + j));
        }
        printf("\t");
        for (int j = 0; j < r; ++j) {
            printf("%d\t", *((*(need + i)) + j));
        }
        printf("\t");
        if (i == 0) {
            for (int j = 0; j < r; ++j) {
                printf("%d\t", available[j]);
            }
        }
        printf("\n");
    }


    for (int i = 0; i < p; ++i) {
        free(max[i]);
        free(allocation[i]);
        free(need[i]);
    }
    free(need);
    free(max);
    free(allocation);
    free(available);

    return 0;
}