#include <iostream>
using namespace std;

struct Queue
{
	int n;
	int Array[100];
};	

void Init (Queue &q)
{
	q.n = 0;
}

int IsEmpty (Queue q)
{
	if (q.n == 0)
		return 1;
	return 0;
}

int IsFull (Queue q)
{
	if (q.n == 99)
		return 1;
	return 0;
}

void EnQueue (Queue q , int x)
{
	q.Array[q.n] = x;
	q.n++;
}

int DeQueue (Queue q)
{
	int x = q.Array[0];
	for (int i = 0 ; i < q.n -1 ; i++)
		q.Array[i] = q.Array[i+1];
	q.n--;
	return x;
}

int main()
{

	return 0;
}