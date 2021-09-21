# include <stdio.h>
# include <stdlib.h>

int main() {
    int p, n;
    printf("Enter the number of process: ");
    scanf("%d", &p);
    printf("Enter the number of blocks: ");
    scanf("%d", &n);

    int *blocks = (int *) malloc(sizeof(int) * n);
    int *process = (int *) malloc(sizeof(int) * p);
    int *visited = (int *) malloc(sizeof(int) * n);

    printf("Enter the size of blocks: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", blocks + i);
        visited[i] = 1;
    }

    printf("Enter the size of process: ");
    for (int i = 0; i < p; ++i) {
        scanf("%d", process + i);
    }

    printf("First Fit...\n");
    for (int i = 0; i < p; ++i) {
        int flag = 0;
        for (int j = 0; j < n; ++j) {
            if (visited[j] && process[i] <= blocks[j]) {
                visited[j] = 0;
                flag = 1;
                printf("Process %d (%d kb) is allocated to block %d (%d kb) with Internal Fragmentation - %d\n", i + 1,
                       process[i], j + 1, blocks[j], blocks[j] - process[i]);
                break;
            }
        }
        if (!flag) {
            printf("Cant Allocate %d\n", i + 1);
        }
    }


    for (int i = 0; i < n; ++i) {
        visited[i] = 1;
    }


    printf("Best Fit...\n");
    int best;
    for (int i = 0; i < p; ++i) {
        best = INT_MAX;
        int proc = -1;
        for (int j = 0; j < n; ++j) {
            if (visited[j] && process[i] <= blocks[j] && blocks[j] - process[i] < best) {
                best = blocks[j] - process[i];
                proc = j;
            }
        }
        if (best == -1) {
            printf("Cant Allocate %d\n", i + 1);
        } else {
            printf("Process %d (%d kb) is allocated to block %d (%d kb) with Internal Fragmentation - %d\n", i + 1,
                   process[i], proc + 1, blocks[proc], best);
            visited[proc] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        visited[i] = 1;
    }


    printf("Worst Fit...\n");
    int worst;
    for (int i = 0; i < p; ++i) {
        worst = -1;
        int proc = -1;
        for (int j = 0; j < n; ++j) {
            if (visited[j] && process[i] <= blocks[j] && blocks[j] - process[i] > worst) {
                worst = blocks[j] - process[i];
                proc = j;
            }
        }
        if (worst == -1) {
            printf("Cant Allocate %d\n", i + 1);
        } else {
            printf("Process %d (%d kb) is allocated to block %d (%d kb) with Internal Fragmentation - %d\n", i + 1,
                   process[i], proc + 1, blocks[proc], worst);
            visited[proc] = 0;
        }
    }

    free(blocks);
    free(process);
    free(visited);
}
