#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void fibonacci(int n) {
    int a = 0, b = 1;

    printf("F:- ");
    while (b < n) {
        printf("%d ", b);
        int temp = b;
        b = a + b;
        a = temp;
    }
    printf("\n");
}

void prime(int n) {

    printf("P:- ");
    for (int i = 2; i < n; i++) {
        int flag = 0;

        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            printf("%d ", i);
    }
    printf("\n");
}

void main() {
    int n = 10;

    if (fork() == 0) // Child
        fibonacci(n);
    else { // Parent
        prime(n);
        wait(NULL);
    }
    neeru@Prof - Moriarty:~ / programs$
    cat
    1.c

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

    void fibonacci(int n) {
        int a = 0, b = 1;

        printf("F:- ");
        while (b < n) {
            printf("%d ", b);
            int temp = b;
            b = a + b;
            a = temp;
        }
        printf("\n");
    }

    void prime(int n) {

        printf("P:- ");
        for (int i = 2; i < n; i++) {
            int flag = 0;

            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
                printf("%d ", i);
        }
        printf("\n");
    }

    void main() {
        int n = 10;

        if (fork() == 0) // Child
            fibonacci(n);
        else { // Parent
            prime(n);
            wait(NULL);
        }
    }
}