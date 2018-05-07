#include <iostream>
using namespace std;

struct Stack
{
	int n;
	int Array[100];
};

void Init (Stack &s)
{
	s.n = 0;
}

int IsEmpty (Stack s)
{
	if (s.n == 0)
		return 1;
	return 0;
}

int IsFull (Stack s)
{
	if (s.n == 100)
		return 1;
	return 0;
}

int Pop (Stack &s)
{
	int x = s.Array[s.n-1];
	s.n--;
	return x;
}

void Push (Stack &s , int x)
{
	s.Array[s.n] = x;
	s.n++;
}

int main()
{
	return 0;
}