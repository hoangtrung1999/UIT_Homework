#include <iostream>
#include <ctime>
using namespace std;

void InputArray(int ArrayA[], int ArrayB[], int ArrayC[], int ArrayD[], int &n)
{
	cout<<"Nhap vao kich thuoc cua mang: ";
	cin>>n;
	cout<<"Nhap vao cac phan tu cua mang: "<<endl;
	for (int i = 0 ; i < n ; i++)
		cin>>ArrayA[i];

	copy(ArrayA,ArrayA + n,ArrayB);
	copy(ArrayA,ArrayA + n,ArrayC);
	copy(ArrayA,ArrayA + n,ArrayD);
}

void PrintResult (int Array[], int n)
{
	cout<<"Result: ";
	for (int j = 0 ; j < n ;j++)
		cout<<Array[j]<<" ";
	cout<<endl;
}

void ShakerSort (int Array[] , int n)
{
	cout<<"ShakerSort"<<endl;
	int Left = 0;
	int Right = n -1;
	int k = 0;
	int temp;
	int loop = 0;
	int swap = 0;
	while (Left < Right)
	{
		for (int i = Left ; i < Right ; i++)
			if (Array[i] > Array[i+1])
			{
				k = i;
				temp = Array[i];
				Array[i] = Array[i+1];
				Array[i+1] = temp;
				swap++;
			}
		Right = k;
		for (int i = Right ; i > Left ; i--)
			if (Array[i] < Array[i-1])
			{
				k = i;
				temp = Array[i];
				Array[i] = Array[i-1];
				Array[i-1] = temp;
				swap++;
			}
		Left = k;
		loop++;
	}
	cout<<"ShakerSort loops in "<<loop<<" times"<<endl;
	cout<<"ShakerSort swaps in "<<swap<<" times"<<endl;
	PrintResult(Array,n);
}

void BubbleSort (int ArrayA[], int n )
{
	cout<<"BubbleSort"<<endl;
	int loop = 0;
	int swap = 0;
	int temp;
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = n - 1 ; j > i ; j--)
			if (ArrayA[j] < ArrayA[j-1])
			{
				temp = ArrayA[j];
				ArrayA[j] = ArrayA[j-1];
				ArrayA[j-1] = temp;
				loop++;
			}
			swap++;
	}
	cout<<"BubbleSort loops in "<<loop<<" times"<<endl;
	cout<<"BubbleSort swaps in "<<swap<<" times"<<endl;
	PrintResult(ArrayA,n);
}

void ShellSort (int Array[], int n)
{
	cout<<"ShellSort"<<endl;
	int loop = 0;
	int swap = 0;

        for (int gap = n/2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i += 1)
            {
                int temp = Array[i];
                int j;
                for (j = i; j >= gap && Array[j - gap] > temp; j -= gap)
                {
                    Array[j] = Array[j - gap];
                    swap++;
                }
                Array[j] = temp;

            }
           	loop++;
        }

    cout<<"ShellSort loops in "<<loop<<" times"<<endl;
	cout<<"ShellSort swaps in "<<swap<<" times"<<endl;
	PrintResult(Array,n);
}

void Heaptify (int Array[] , int n , int pos)
{
	while (pos <= n / 2 - 1) // -> chua chay den nut cuoi cung co con trong heap
	{
		int LeftChild = 2*pos + 1;
		int RightChild = 2*pos + 2;
		int pivot = LeftChild;
		if (RightChild < n // Pham vi xet trong pham vi mang
			&& Array[pivot] < Array[RightChild]) // tim phan tu con lon nhat
			pivot = RightChild;
		if ( Array[pos] < Array[pivot])
			swap (Array[pos], Array[pivot]);
		pos = pivot;
	}
}

void BuildTree (int Array[] , int n)
{
	for (int i = n/2 - 1 ; i >= 0 ; i--)
		Heaptify(Array,n,i);
}

void HeapSort (int Array[] , int n)
{
	int length = n;
	int Index = n - 1;
	int loop = 0;
	int swap1 = 0;
	do
	{
		BuildTree(Array,length);
		swap (Array[Index],Array[0]);
		swap1++;
		loop++;
		Index--;
		length--;
	}while (length > 1);
	cout<<"HeapSort loops in "<<loop<<" times"<<endl;
	cout<<"HeapSort swaps in "<<swap1<<" times"<<endl;
	PrintResult(Array,n);
}

int main()
{
	int ArrayA[100];
	int ArrayB[100];
	int ArrayC[100];
	int ArrayD[100];
	int n;
	InputArray(ArrayA,ArrayB,ArrayC,ArrayD,n);
	// Call And Calculate Running Time
	BubbleSort(ArrayA,n);
	ShakerSort(ArrayB,n);
	ShellSort(ArrayC,n);
	HeapSort(ArrayD,n);

	return 0;
}