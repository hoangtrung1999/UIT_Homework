#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

int n = 0;
int a[10];
int Generator();

void* f1(void*);
void* f2(void*);
sem_t sem;
pthread_t threads[2];
int main()
{
	printf("Start\n");
	sem_init(&sem,0,0);
	pthread_create(&threads[0],NULL,f2,NULL);
	pthread_create(&threads[1],NULL,f1,NULL);
	for (int i = 0; i < 2; i++)
		pthread_join(threads[i],NULL);
	return 0;
}

int Generator ()
{
	int random = rand() % 100 + 1;
	return random;
}

void* f1 (void* arg)
{
	while(1)
	{
		sem_post(&sem);
		int x = Generator();
		printf("f1: Size of a: %d\n", n);
		a[n] = x;
		n++;
	};
}

void* f2(void* arg)
{
	while(1)
	{
		sem_wait(&sem);
		int x = a[n-1];
		n--;
		if (n > 0)
			printf("f2: Size of a: %d\n", n);
		else
			printf("f2: Nothing in array a\n");
		
	};
}
