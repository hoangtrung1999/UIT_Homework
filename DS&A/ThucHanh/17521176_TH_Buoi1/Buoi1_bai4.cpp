#include <iostream>
#include <vector>
using namespace std;

int Convert(int n)
{
	int x = 8;
	vector <int> Array;
	while ( n != 0 )
	{
		Array.push_back(n%16);
		n = n / 16;
		x--;
	}
	for (int i = 0 ; i < x ; i++)
		cout<<"0";
	for (int i = Array.size() - 1 ; i > -1 ; i--)
	{
		if (Array[i] > 9)
		{
			switch(Array[i])
			{
				case 10:
					cout<<"A";
					break;
				case 11:
					cout<<"B";
					break;
				case 12:
					cout<<"C";
					break;
				case 13:
					cout<<"D";
					break;
				case 14:
					cout<<"E";
					break;
				case 15:
					cout<<"F";
					break;
			}
		}
		else
			cout<<Array[i];
	}
	return 0;
}

int main()
{
	int n;
	cout<<"Nhap vao so N o he thap phan: ";
	cin>>n;
	cout<<"So N o he thap luc la: ";
	Convert(n);
	return 0;
}