#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

pthread_mutex_t mutex;
void* f1(void *);
void* f2(void *); 
pthread_t tid[2];
int x;
int main(int argc, char * argv[])
{
	int i;
	x = 0;
	if (pthread_mutex_init (&mutex, NULL) != 0)
		printf("Mutex init has failed\n");

	pthread_create(&tid[0],NULL,f1,NULL);
	pthread_create(&tid[1],NULL,f2,NULL);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);

	pthread_mutex_destroy(&mutex);
	return 0;
	
}

void* f1(void *arg)
{
	pthread_mutex_lock(&mutex);
	while (1)
	{
		x=x+1;
		if (x==20) 
		{ 
			x = 0;
		}
		printf("%d ",x);
	}
	pthread_mutex_unlock(&mutex);
}

void* f2(void *arg)
{
	pthread_mutex_lock(&mutex);
	while (1)
	{
		x = x + 1;
		if (x == 20)
		{
			x = 0;
		}
		printf("%d",x);
	}
	pthread_mutex_unlock(&mutex);
}
