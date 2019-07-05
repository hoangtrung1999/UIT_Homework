	#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

int n = 0;
int a[100];
int Generator();

void* ThreadOne(void* );
void* ThreadTwo(void* );

pthread_t threads[2];
int main()
{
	pthread_create(&threads[0],NULL,ThreadOne,NULL);
	pthread_create(&threads[1],NULL,ThreadTwo,NULL);
	for (int i = 0; i < 2; i++)
		pthread_join(threads[i],NULL);
	return 0;
}

int Generator ()
{
	int random = rand() % 100 + 1;
	return random;
}

void*ThreadOne (void* arg)
{
	while (n < 99)
	{
		int x = Generator();
		a[n] = x;
		n++;
	}
}

void* ThreadTwo(void* arg)
{
	while (n > 0)
	{
		int x = a[n-1];
		n--;
		if (n > 0)
			printf("Size of a: %d\n", n);
		else
			printf("Nothing in array a\n");
	}

}
