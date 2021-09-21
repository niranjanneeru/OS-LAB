#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
    printf("A: %d\n", getpid());
    if (fork() == 0) {
        printf("B: %d forked by %d\n", getpid(), getppid());
        if (fork() == 0) {
            printf("D: %d forked by %d\n", getpid(), getppid());
            if (fork() == 0) {
                printf("H: %d forked by %d\n", getpid(), getppid());
                if (fork() == 0) {
                    printf("I: %d forked by %d\n", getpid(), getppid());
                } else
                    wait(NULL);
            } else
                wait(NULL);
        } else if (fork() == 0) {
            printf("E: %d forked by %d\n", getpid(), getppid());
        } else if (fork() == 0) {
            printf("F: %d forked by %d\n", getpid(), getppid());
        } else
            wait(NULL);
    } else if (fork() == 0) {
        printf("C: %d forked by %d\n", getpid(), getppid());
        if (fork() == 0) {
            printf("G: %d forked by %d\n", getpid(), getppid());
        } else
            wait(NULL);
    } else
        wait(NULL);
}