#include <iostream>
using namespace std;

int Calculate (int Array[10])
{
	int count = 0;
	for (int i = 0 ; i < 10 ; i++)
		if (!(Array[i] & 1))
			count++;
	return count;
}

int main()
{
	int Array[10];
	for (int i = 0 ; i < 10 ; i++)
		cin>>Array[i];
	cout<<Calculate(Array);
	return 0;
}