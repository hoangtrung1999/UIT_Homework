#include <iostream>
using namespace std;

float Power (int x , int n)
{
	int T = 1;
	for (int i = 0 ; i < n ; i++)
		T *= x;
	return T;
}

float Calculate(int x , int n )
{
	float S = 0;
	float temp = 0;
	for (int i = 1 ; i <= n ; i++)
	{	
		temp += i;
		S += Power(-1,i) * ( Power(x,i)/ temp);
	}
	return S;

}
int main()
{
	int x,n;
	cin>>x>>n;
	cout<<Calculate(x,n);
	return 0;
}