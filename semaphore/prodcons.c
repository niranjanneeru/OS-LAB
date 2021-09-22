# include <semaphore.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

sem_t empty; // indicate number of empty blocks in buffer
sem_t full; // indicate number of full blocks in buffer
int in = 0; // input count of producer
int out = 0; // output count of consumer
int *buffer; // storage buffer
int BufferSize; // size of buffer
pthread_mutex_t mutex; // control mutex

void *producer() {
    int item;
    while (1) {
        item = rand() % 1000;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer:- %d at %d\n", item, in);
        in = (in + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer() {
    int item;
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = buffer[out];
        printf("Consumer:- %d at %d\n", item, out);
        out = (out + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main() {

    printf("Enter the buffer size:- ");
    scanf("%d", &BufferSize);
    buffer = (int *) malloc(sizeof(int) * BufferSize);
    sem_init(&empty, 0, BufferSize);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_t ptid, ctid;

    pthread_create(&ptid, NULL, producer, NULL);
    pthread_create(&ctid, NULL, consumer, NULL);
    pthread_join(ptid, NULL);
    pthread_join(ctid, NULL);


    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    free(buffer);
    return 0;
}
