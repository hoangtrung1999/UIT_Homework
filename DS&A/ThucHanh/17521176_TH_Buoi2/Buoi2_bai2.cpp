//C:\Users\ACER\Desktop\CTDL_GT\Github\Data-Structures-and-Algorithms\Sorting Algorithm
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void RandomInputArray(int ArrayA[], int ArrayB[], int ArrayC[], int ArrayD[], int &n)
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
	while (Left < Right)
	{
		for (int i = Left ; i < Right ; i++)
			if (Array[i] > Array[i+1])
			{
				k = i;
				temp = Array[i];
				Array[i] = Array[i+1];
				Array[i+1] = temp;
			}
		Right = k;
		for (int i = Right ; i > Left ; i--)
			if (Array[i] < Array[i-1])
			{
				k = i;
				temp = Array[i];
				Array[i] = Array[i-1];
				Array[i-1] = temp;
			}
		Left = k;
	}
	PrintResult(Array,n);
}

void BubbleSort (int ArrayA[], int n )
{
	cout<<"BubbleSort"<<endl;
	int temp;
	for (int i = 0 ; i < n ; i++)
		for (int j = n - 1 ; j > i ; j--)
			if (ArrayA[j] < ArrayA[j-1])
			{
				temp = ArrayA[j];
				ArrayA[j] = ArrayA[j-1];
				ArrayA[j-1] = temp;
			}
	PrintResult(ArrayA,n);
}

void ShellSort (int Array[], int n)
{
	cout<<"ShellSort"<<endl;
	 // Start with a big gap, then reduce the gap
        for (int gap = n/2; gap > 0; gap /= 2)
        {
           
            for (int i = gap; i < n; i += 1)
            {
              
                int temp = Array[i];

                int j;
                for (j = i; j >= gap && Array[j - gap] > temp; j -= gap)
                    Array[j] = Array[j - gap];

                Array[j] = temp;
            }
        }
	PrintResult(Array,n);
}

void Heaptify (int Array[] , int n , int pos)
{
	while (pos <= n / 2 - 1) // -> chua chay den nut cuoi cung co con trong heap
	{
		cout<<"Vi tri duyet: "<<pos<<endl;
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
	do
	{
		BuildTree(Array,length);
		swap (Array[Index],Array[0]);
		Index--;
		length--;
	}while (length > 1);
	PrintResult(Array,n);
}


int main()
{
	int ArrayA[100];
	int ArrayB[100];
	int ArrayC[100];
	int ArrayD[100];
	int n;
	clock_t start;
	clock_t end;
	RandomInputArray(ArrayA,ArrayB,ArrayC,ArrayD,n);

	// Call And Calculate Running Time
	start = clock();
	BubbleSort(ArrayA,n);
	end = clock();
	cout<<"BubbleSort runs in "<<((double)(end -start))/CLOCKS_PER_SEC<<"s"<<endl;

	start = clock();
	ShakerSort(ArrayB,n);
	end = clock();
	cout<<"ShakerSort runs in "<<((double)(end -start))/CLOCKS_PER_SEC<<"s"<<endl;

	start = clock();
	ShellSort(ArrayC,n);
	end = clock();
	cout<<"ShellSort runs in "<<((double)(end -start))/CLOCKS_PER_SEC<<"s"<<endl;

	start = clock();
	HeapSort(ArrayD,n);
	end = clock();
	cout<<"HeapSort runs in "<<((double)(end - start))/CLOCKS_PER_SEC<<"s"<<endl;
	return 0;
}