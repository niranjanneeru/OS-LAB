# include <stdio.h>
# include <stdlib.h>
# include <sys/shm.h>
# include <sys/ipc.h>
# include <semaphore.h>

# include <unistd.h>

int main(){
    const char * name = "shm";
    key_t key = ftok(name,65);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    int *temp = (int *)shmat(shmid,(void *)0,0);
    int in = 0;
    int max = 100;
    int loop = 6;
    while(loop--){
        temp[in] = rand() % 1000;
        printf("Producer : %d\n",temp[in]);
        in= (in+1)%max;
        sleep(rand()%2+1);
    }
    shmdt(temp);
    return 0;
}