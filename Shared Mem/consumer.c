# include <stdio.h>
# include <stdlib.h>
# include <sys/shm.h>
# include <sys/ipc.h>
# include <unistd.h>

int main(){
    const char * name = "shm";
    key_t key = ftok(name,65);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    int *temp = (int *)shmat(shmid,(void *)0,0);
    int out = 0;
    int max = 100;
    int loop = 6;
    while(loop--){
        printf("Consumer: %d\n",temp[out]);
        out = (out + 1)%100;
        sleep(rand()%2+1);
    }
      
    shmdt(temp);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}