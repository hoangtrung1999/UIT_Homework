#include <iostream>
#include <vector>
using namespace std;

int Convert(int n)
{
	int x = 8;
	vector <int> Array;
	while ( n != 0 )
	{
		Array.push_back(n%2);
		n = n / 2;
		x--;
	}
	for (int i = 0 ; i < x ; i++)
		cout<<"0";
	for (int i = Array.size() - 1 ; i > -1 ; i--)
		cout<<Array[i];
	return 0;
}

int main()
{
	int n;
	cout<<"Nhap vao so N o he thap phan: ";
	cin>>n;
	cout<<"So N o he nhi phan la: ";
	Convert(n);
	return 0;
}