#include <iostream>
using namespace std;

void Input (int ArrayA[] , int ArrayB[] , int ArrayC[] , int &n)
{
	cout<<"Nhap kich thuoc mang: ";
	cin>>n;
	cout<<"Nhap cac phan tu cua mang:"<<endl;
	for (int i = 0 ; i < n ; i++)
		cin>>ArrayA[i];
	copy(ArrayA,ArrayA+n,ArrayB);
	copy(ArrayA,ArrayA+n,ArrayC);
}

void Output(int Array[], int n)
{
	cout<<"Mang gom cac phan tu: ";
	for (int i = 0 ; i < n ; i++)
		cout<<Array[i]<<" ";
	cout<<endl;
}

int Partition (int Array[] , int Low , int High , int n , int &loop , int &Iswap)
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
			Iswap++;
		}
		loop++;
	}
	swap (Array[i+1],Array[High]);
	Iswap++;
	return i + 1;
}

void QuickSort (int Array[] , int Low , int High,int n , int &loop , int &swap)
{
	if (Low < High)
	{
		int i = Partition (Array,Low,High,n,loop,swap);
		QuickSort (Array,Low,i-1,n,loop,swap);
		QuickSort (Array,i+1,High,n,loop,swap);
	}
}

void Merge (int Array[] , int Left , int Mid , int Right, int &loop, int &swap)
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
		loop++;
	}
	for (int i = 0 ; i < Index ; i++)
		Array[Left+i] = temp[i];
	delete[] temp;
}

void MergeSort (int Array[] , int Left , int Right, int &loop, int &swap)
{
	if (Left < Right)
	{
		int Mid = (Left + Right)/2;
		MergeSort (Array,Left,Mid,loop,swap);
		MergeSort (Array,Mid+1,Right,loop,swap);
		Merge (Array,Left,Mid,Right,loop,swap);
		loop++;
	}
}

void RadixSort (int Array[], int n)
{

	int *temp = new int[n];
	int *temp1 = new int[n];
	int Max = Array[0];
	int Iswap = 0 ;
	int loop = 0;
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
					Iswap++;
				}
			}
		loop++;
		Max /= 10;
	} while (Max != 0);
	delete[] temp1;
	delete[] temp;
	cout<<"Radix Sort loops "<<loop<<" times"<<endl;
	cout<<"Radix Sort swaps "<<Iswap<<" times"<<endl;
}

int main()
{
	int n;
	int ArrayA[100];
	int ArrayB[100];
	int ArrayC[100];
	int loop = 0;
	int swap = 0;
	Input(ArrayA,ArrayB,ArrayC,n);

	cout<<"Quick Sort"<<endl;
	QuickSort (ArrayA,0,n-1,n,loop,swap);
	Output (ArrayA,n);
	cout<<"Quick Sort loops "<<loop<<" times"<<endl;
	cout<<"Quick Sort swaps "<<swap<<" times"<<endl;

	loop =0;
	swap =0;
	cout<<"Merge Sort"<<endl;
	MergeSort(ArrayB,0,n-1,loop,swap);
	Output (ArrayB,n);
	cout<<"Quick Sort loops "<<loop<<" times"<<endl;
	cout<<"Quick Sort swaps "<<swap<<" times"<<endl;

	cout<<"Radix Sort"<<endl;
	RadixSort(ArrayC,n);
	Output(ArrayC,n);
	return 0;
}