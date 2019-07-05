#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

void * f1(void *);
void * f2(void *);

pthread_t tid[2];
sem_t sem;
int sell, product;
int MSSV = 86; // 17521176
int main(int argc, char * argv[])
{
	int i;
	sell = 0;
	product = 0;
	sem_init(&sem, 0, 0);
	pthread_create(&tid[1],NULL,f1,NULL);
	pthread_create(&tid[0],NULL,f2,NULL);
	for(i=0;i<2;i++)
		pthread_join(tid[i],NULL);
	return 0;
}

void *f1(void *arg)
{
	while(sell <= product) {	
		sem_wait(&sem);
		sell++;
		printf("sell: %d\n", sell);
	}
}
void *f2(void *arg)
{	
	while (product <= sell + MSSV) {
		product++;
		sem_post(&sem);
		printf("product: %d\n", product);
	}
}