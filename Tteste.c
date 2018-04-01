#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaforo;
pthread_mutex_t matrix;


void * thread(void* args){
	sem_wait(&semaforo);
	pthread_mutex_lock(&matrix);
	for (int i = 0; i < 10; ++i)
	{
		printf("hello thread one\n");
	}
	sem_post(&semaforo);
	pthread_mutex_unlock(&matrix);
}

void * thread2(void* args){
	sem_wait(&semaforo);
	pthread_mutex_lock(&matrix);
	for (int i = 0; i < 10; ++i)
	{
		printf("hello thread diferenciada\n");
	}
	sem_post(&semaforo);
	pthread_mutex_unlock(&matrix);

}

int main(int argc, char const *argv[]){
	sem_init (&semaforo,0,1);
	pthread_t t1,t2;
	pthread_mutex_init(&matrix,NULL);
	printf("main\n");
	pthread_create(&t1,NULL,thread,NULL);
	pthread_create(&t2,NULL,thread2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;
}
