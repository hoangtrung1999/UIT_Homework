#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

void* f1(void *);
void* f2(void *); 
pthread_t tid[2];
int x;
int main(int argc, char * argv[])
{
	int i;
	x = 0;
	pthread_create(&tid[0],NULL,f1,NULL);
	pthread_create(&tid[1],NULL,f2,NULL);
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
	
}

void* f1(void *arg)
{
	while (1)
	{
		x=x+1;
		if (x==20) 
		{ 
			x = 0;
		}
		printf("%d ",x);
	}
}

void* f2(void *arg)
{
	while (1)
	{
		x = x + 1;
		if (x == 20)
		{
			x = 0;
		}
		printf("%d",x);
	}
}
