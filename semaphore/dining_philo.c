# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>

# define MAX 5
 int THINKING =  0;
 int EATING = 1;
 int HUNGRY = 2;

sem_t m;
sem_t pm[MAX];
int state[MAX];

int right(int i){
	return (i + 1) % MAX;
}


int left(int i){
	return (i - 1 + MAX) % MAX;
}

void think(int i){
	printf("Philosopher %d is Thinking\n",i);
}

void eat(int i){
	printf("Philosopher %d is Eating using %d and %d forks\n",i,left(i),right(i));
}

void test(int i){
	if(state[i]==HUNGRY && state[left(i)] != EATING && state[right(i)] != EATING){
		state[i] = EATING;
		sem_post(&pm[i]);
		sleep(2);
	}
}


void takeforks(int i){
	sem_wait(&m);
	state[i]=HUNGRY;
	printf("Philosopher %d is Hungry\n", i);
	test(i);
	sem_post(&m);
	sem_wait(&pm[i]);
	sleep(1);
}

void putforks(int i){
	sem_wait(&m);
	state[i]=THINKING;
	test(left(i));
	test(right(i));
	sem_post(&m);
}

void philosopher(void * temp){
	int *j = (int *)temp;
	int i = *j;
	while(1){
		think(i);
		sleep(1);
		takeforks(i);
		eat(i);
		sleep(0);
		putforks(i);
	}
}

int main(){
	sem_init(&m, 0,1);
	for(int i=0;i<MAX;i++){
		sem_init(&pm[i],0,0);
		state[i] = THINKING;
	}
	
	pthread_t P[MAX];
    	
    	for(int i=0;i<MAX;i++){
    		pthread_create(&P[i], NULL, (void *)philosopher, &i);
    	}
    	
    	for(int i=0;i<MAX;i++){
    		pthread_join(P[i], NULL);
    	}
	return 0;
}
