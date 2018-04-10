#include <iostream>
using namespace std;

void InputArray(int Array[100], int &n)
{
	cout<<"Nhap so luong phan tu cua mang: ";
	cin>>n;
	for (int i = 0 ; i < n ; i++)
	{
		cout<<"Nhap vao phan tu tai vi tri "<<i<<endl;
		cin>>Array[i];
	}
}

void PrintArray (int Array[100], int n)
{
		cout<<"Xuat mang: "<<endl;
	for (int i = 0 ; i < n ; i++)
		cout<<Array[i]<<" ";
	cout<<endl;
}

void DeleteMember (int Array[100], int &n , int k)
{
	if ( k == n - 1)
		{
			n--;
			return;
		}
	else
	{
		for (int i = k ; i < n - 1 ; i++)
			Array[i] = Array[i+1];
		n--;
	}

}

void FindMax (int Array[100], int n)
{
	int Max = Array[0];
	cout<<"Vi tri nhung phan tu mang gia tri lon nhat trong mang: ";
	for (int i = 0 ; i < n ; i++)
		if (Max < Array[i])
			Max = Array[i];
	for (int j = 0 ; j < n ; j++)
		if (Max == Array[j])
			cout<<j<<" ";
	cout<<endl;

}

void FindMin (int Array[100], int n)
{
	int Min = Array[0];
	cout<<"Vi tri nhung phan tu mang gia tri nho nhat trong mang: ";
	for (int i = 0 ; i < n ; i++)
		if (Min > Array[i])
			Min = Array[i];
	for (int j = 0 ; j < n ; j++)
		if (Min == Array[j])
			cout<<j<<" ";
	cout<<endl;
}

int CountNegative (int Array[100] , int n )
{
	int k = 0 ;
	for (int i = 0 ; i < n ; i++)
		if (Array[i] < 0)
			k++;
	return k;
}

int MaxNegative (int Array[100], int n )
{
	int Max;
	int i;
	int j;
	for (i = 0 ; i < n ; i++)
		if (Array[i] < 0)
		{
			Max = Array[i];
			break;
		}
	for (j = i ; j < n ; j++)
		if (Array[j] < 0 && Array[j] > Max)
			Max = Array[j];
	return Max;
}

int MinPositive (int Array[100] , int n )
{
	int Min;
	int i;
	int j;
	for (i = 0 ; i < n ; i++)
		if (Array[i] > 0)
		{
			Min = Array[i];
			break;
		}
	for (j = i ; j < n ; j++)
		if (Array[j] > 0 && Array[j] < Min)
			Min = Array[j];
	return Min;
}

int CountSame (int Array[100] , int n , int x)
{
	int k = 0 ;
	for (int i = 0 ; i < n ; i++)
		if (Array[i] == x)
			k++;
	return k;
}

void BubbleSortArray(int Array[100] , int n )
{
	cout<<"BubbleSort: "<<endl;
	int temp;
	for (int i = 0 ; i < n ; i++)
	{
			for (int j = n - 1 ; j > i ; j--)
		{
			if (Array[j] < Array[j-1])
			{ // Swap
				temp = Array[j-1];
				Array[j-1] = Array[j];
				Array[j] = temp;
			}
		}
	}

}

int FindBinary(int Array[100], int a , int b , int n , int x)
{
	while(1)
	{
		int mid = a + (b - a)/2;
		if (Array[mid] > x)
			b = mid - 1;
		else if (Array[mid] < x)
			a = mid + 1;
		else if (Array[mid] == x)
		{
			break;
			return mid;
		}
	}
	
}

int FindLinear (int Array[100] , int n , int x)
{
	for (int i = 0 ; i < n ; i++)
		if (Array[i] == x)
			return i;
}

int main()
{
	int n;
	int k;
	int Array[100];

	int choice;
	InputArray(Array,n);
	cout<<"Nhap vao lua chon cua ban: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			PrintArray(Array,n);
			break;
		case 2:
			cout<<"Nhap vao vi tri K can xoa: ";
			cin>>k;
			DeleteMember(Array,n,k);
			PrintArray(Array,n);
			break;
		case 3:
			FindMax(Array,n);
			break;
		case 4:
			FindMin(Array,n);
			break;
		case 5:
			cout<<"So phan tu am trong mang la: "<<CountNegative(Array,n)<<endl;
			break;
		case 6:
			cout<<"So am lon nhat trong mang la: "<<MaxNegative(Array,n)<<endl;
			break;
		case 7:
			cout<<"So duong nho nhat trong mang la: "<<MinPositive(Array,n)<<endl;
			break;
		case 8:
			cout<<"Nhap vao phan tu can tim: (Linear Search) ";
			cin>>k;
			cout<<"Phan tu can tim xuat hien tai vi tri: "<<FindLinear(Array,n,k)<<endl;
			break;
		case 9:
			cout<<"Nhap vao phan tu X can dem: ";
			cin>>k;
			cout<<"So phan tu giong phan tu X la: "<<CountSame(Array,n,k)<<endl;
			break;
		case 10:
			BubbleSortArray(Array,n);
			PrintArray(Array,n);
			break;
		case 11:
			cout<<"Nhap vao phan tu can tim: ";
			cin>>k;
			cout<<"Phan tu can tim xuat hien tai vi tri: "<<FindBinary(Array,0,n-1,n,k)<<endl;
			break;

	}
	return 0;
}