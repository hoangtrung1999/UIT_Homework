#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void RandomInputArray(int ArrayA[], int ArrayB[], int ArrayC[], int &n)
{
	cout<<"Nhap vao kich thuoc mang: ";
	cin>>n;
	srand(time(NULL));
	for (int i = 0 ; i < n ; i++)
		{
			int x = rand() % 100;
			ArrayA[i] = x;
		}
	cout<<"Random Input: ";
	for (int i = 0 ; i < n ; i++)
		cout<<ArrayA[i]<<" ";
	cout<<endl;

	copy(ArrayA,ArrayA + n,ArrayB);
	copy(ArrayA,ArrayA + n,ArrayC);
}

void Output(int Array[], int n)
{
	cout<<"Mang gom cac phan tu: ";
	for (int i = 0 ; i < n ; i++)
		cout<<Array[i]<<" ";
	cout<<endl;
}

int Partition (int Array[] , int Low , int High , int n)
{
	int pivot = Array[High];
	int i = Low - 1;
	int j = Low;

	for (; j < High ; j++)
	{
		if ( Array[j] <= pivot)
		{
			i++;
			swap (Array[i], Array[j]);
		}
	}

	swap (Array[i+1],Array[High]);
	return i + 1;
}

void QuickSort (int Array[] , int Low , int High,int n)
{
	if (Low < High)
	{
		int i = Partition (Array,Low,High,n);
		QuickSort (Array,Low,i-1,n);
		QuickSort (Array,i+1,High,n);
	}
}

void Merge (int Array[] , int Left , int Mid , int Right)
{
	int *temp = new int[(Right-Left) + 1];
	int Index = 0;
	int i = Left;
	int j = Mid + 1;

	while ( !(i > Mid && j > Right) )
	{
		if ( i <= Mid && j <= Right && Array[i] < Array[j] || j > Right)
			temp[Index++] = Array[i++];
		else
			temp[Index++] = Array[j++];
	}
	for (int i = 0 ; i < Index ; i++)
		Array[Left+i] = temp[i];
	delete[] temp;
}

void MergeSort (int Array[] , int Left , int Right)
{
	if (Left < Right)
	{
		int Mid = (Left + Right)/2;
		MergeSort (Array,Left,Mid);
		MergeSort (Array,Mid+1,Right);
		Merge (Array,Left,Mid,Right);
	}
}

void RadixSort (int Array[], int n)
{

	int *temp = new int[n];
	int *temp1 = new int[n];
	int Max = Array[0];
	for (int i = 0; i < n ; i++)
		if (Max < Array[i])
			Max = Array[i];
	for (int i = 0 ; i < n ; i++)
		temp[i] = Array[i];
	do
	{
		for (int i = 0 ; i < n; i++)
		{
			temp1[i] = temp[i] % 10;
			temp[i] = temp[i] / 10;
		}
		for (int i = 0 ; i < n - 1 ; i++)
			for (int j = i + 1 ; j < n ; j++)
			{
				if (temp1[j] < temp1[i])
				{
					swap(Array[i],Array[j]);
					swap(temp1[i], temp1[j]);
					swap(temp[i],temp[j]);
				}
			}
		Max /= 10;
	} while (Max != 0);
	delete[] temp1;
	delete[] temp;
}

int main()
{
	int n;
	int ArrayA[100];
	int ArrayB[100];
	int ArrayC[100];
	clock_t start;
	clock_t end;

	RandomInputArray(ArrayA,ArrayB,ArrayC,n);

	start = clock();
	cout<<"Quick Sort"<<endl;
	QuickSort (ArrayA,0,n-1,n);
	end = clock();
	Output (ArrayA,n);
	cout<<"Quick Sort runs in "<<((double) end-start)/CLOCKS_PER_SEC<<"s"<<endl;

	start = clock();
	cout<<"Merge Sort"<<endl;
	MergeSort(ArrayB,0,n-1);
	end = clock();
	Output (ArrayB,n);
	cout<<"Merge Sort runs in "<<((double) end-start)/CLOCKS_PER_SEC<<"s"<<endl;

	start = clock();
	cout<<"Radix Sort"<<endl;
	RadixSort(ArrayC,n);
	end = clock();
	Output(ArrayC,n);
	cout<<"Radix Sort runs in "<<((double) end-start)/CLOCKS_PER_SEC<<"s"<<endl;

	return 0;
}