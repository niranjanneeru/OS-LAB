#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
    int n = 4;

    printf("\nParent pid %d at level 0\n", getpid());

    for (int i = 1; i <= n; i++)
        if (fork() == 0)
            printf("C pid %d - P pid %d L - %d\n", getpid(), getppid(), i);
        else if (fork() == 0)
            printf("C pid %d - P pid %d L - %d\n", getpid(), getppid(), i);
        else {
            wait(NULL);
            break;
        }
}