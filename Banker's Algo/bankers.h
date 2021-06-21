# include <stdio.h>
# include <stdlib.h>

int bankers(int **allocation, int **need, int *finish, int *work, int p, int r) {
    int flag;
    int indic = 1;
    printf("Safe Sequence: ");
    int procs = p;
    while (1) {
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
                return 0;
            }
            return 1;
        }
    }
}

void printSysSnap(int **max, int **allocation, int **need, int *available, int p, int r) {
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
}
