#include <iostream>
using namespace std;

void Init (int &n)
{
	n = 0;
}

int IsEmpty (int n)
{
	if (n == 0)
		return 1;
	return 0;
}

int IsFull (int n)
{
	if (n == 99)
		return 1;
	return 0;
} 

void EnQueue (int Array[], int &n, int x)
{
	Array[n] = x;
	n++;
}

int DeQueue (int Array[], int &n)
{
	int x = Array[0];
	for (int i = 0 ; i < n-1 ; i++)
		Array[i] = Array[i+1];
	n--;
	return x;
}

int main()
{
	int Array[100];
	int n;

	return 0;
}