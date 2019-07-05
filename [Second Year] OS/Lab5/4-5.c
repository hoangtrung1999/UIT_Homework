#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

pthread_t tid[7]; // 7 phep tinh
sem_t sem[5];	  // 5 lan waiting
int A, B, C, D, E, F, Ans; // Ket qua 7 phep tinh

int x1 = 1;
int x2 = 2;
int x3 = 3;
int x4 = 4;
int x5 = 5;
int x6 = 6;

void* fnA() {
	A = x1 * x2;
	printf("A = %d\n", A);
	sem_post(&sem[0]); // open semaphore 0
	sem_post(&sem[0]); // open semaphore 0
}

void* fnB() {
	B = x3 * x4;
	printf("B = %d\n", B);
	sem_post(&sem[1]); 
	sem_post(&sem[1]); 
}

void* fnC() {
	
	sem_wait(&sem[1]); // wait B
	C = B * x5;
	printf("C = %d\n", C);
	sem_post(&sem[2]); // open semaphore 2
	sem_post(&sem[2]); // open semaphore 2
}

void* fnD() {
	sem_wait(&sem[1]); // wait B
	D = B * x6;
	printf("D = %d\n", D);
	sem_post(&sem[3]); // open semaphore 3
}

void* fnE() {
	sem_wait(&sem[0]); // wait sem A
	sem_wait(&sem[2]); //  và sem C
	E = A * C;
	printf("E = %d\n", E);
}

void* fnF() {
	sem_wait(&sem[0]); // wait sem A
	sem_wait(&sem[3]); // wait D
	F = A * D;
	printf("F = %d\n", F);
	sem_post(&sem[4]); // open semaphore 4
}

void* fnAns() {
	sem_wait(&sem[2]); // wait C
	sem_wait(&sem[5]); // wait F
	Ans = C + F;
	printf("Answer = %d\n", Ans);
}

int main(int argc, char* argv[])
{
	int i;
	sem_init(&sem[0], 0, 0);
	sem_init(&sem[1], 0, 0);
	sem_init(&sem[2], 0, 0);
	sem_init(&sem[3], 0, 0);
	sem_init(&sem[4], 0, 0);
 

	pthread_create(&tid[0], NULL, fnA, NULL);
	pthread_create(&tid[1], NULL, fnB, NULL);
	pthread_create(&tid[2], NULL, fnC, NULL);
	pthread_create(&tid[3], NULL, fnD, NULL);
	pthread_create(&tid[4], NULL, fnE, NULL);
	pthread_create(&tid[5], NULL, fnF, NULL);
	pthread_create(&tid[6], NULL, fnAns, NULL);

	for (i = 0; i < 7; i++)
		pthread_join(tid[i], NULL);

	return 1;
}

