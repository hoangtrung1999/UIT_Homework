#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int x1 = 1;
int x2 = 2;
int x3 = 3;
int x4 = 4;
int x5 = 5;
int x6 = 6;
int W, V, Y, Z, ANS;
pthread_t tid[7];
sem_t sem[6];
// mutex[0]: 
// mutex[1]:
// mutex
void* f1 (void*);
void* f2 (void*);
void* f3 (void*);
void* f4 (void*);
void* f5 (void*);
void* f6 (void*);
void* f7 (void*);
void printResult(char c,int x);
int main()
{
	sem_init(&sem[0], 0, 0);
	sem_init(&sem[1], 0, 0);
	sem_init(&sem[2], 0, 0);
	sem_init(&sem[3], 0, 0);
	sem_init(&sem[4], 0, 0);
	sem_init(&sem[5], 0, 0);

	pthread_create(&tid[0],NULL,f1,NULL);
	pthread_create(&tid[1],NULL,f2,NULL);
	pthread_create(&tid[2],NULL,f3,NULL);
	pthread_create(&tid[3],NULL,f4,NULL);
	pthread_create(&tid[4],NULL,f5,NULL);
	pthread_create(&tid[5],NULL,f6,NULL);
	pthread_create(&tid[6],NULL,f7,NULL);



	for (int i = 0; i < 7; i++)
		pthread_join(tid[i],NULL);

	return 0;
}

void printResult(char c,int x)
{
	printf("%c: %d\n",c,x);
}

void* f1 (void* arg)
{
	W = x1 * x2;
	printResult('a',W);
	sem_post(&sem[0]);
	sem_post(&sem[0]);
}

void* f2 (void* arg)
{
	
	V = x3 * x4;
	printResult('a',V);
	sem_post(&sem[1]);
	sem_post(&sem[1]);
}

void* f3 (void* arg)
{
	sem_wait(&sem[1]);
	Y = V * x5;
	printResult('b',Y);
	sem_post(&sem[2]);
	sem_post(&sem[2]);
}

void* f4 (void* arg)
{
	sem_wait(&sem[1]);
	Z = V * x6;
	printResult('c',Z);
	sem_post(&sem[3]);
}

void* f5 (void* arg)
{
	sem_wait(&sem[0]);
	sem_wait(&sem[2]);
	Y = W * Y;
	sem_post(&sem[2]);
	printResult('d',Y);
	//sem_post(&sem[4]);
}

void* f6 (void* arg)
{
	sem_wait(&sem[0]);
	sem_wait(&sem[3]);
	Z = W * Z;
	sem_post(&sem[5]);
	printResult('e',Z);
	sem_post(&sem[4]);
}

void* f7 (void* arg)
{
	sem_wait(&sem[2]);
	sem_wait(&sem[5]);
	ANS = Y + Z;
	printResult('f',ANS);
}

