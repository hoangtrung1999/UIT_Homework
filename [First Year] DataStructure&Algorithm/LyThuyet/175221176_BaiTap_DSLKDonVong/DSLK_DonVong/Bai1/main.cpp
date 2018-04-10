#include <iostream>
#include <fstream>
using namespace std;

struct NODE
{
	int info;
	struct NODE* pNext;
};

struct LIST
{
	struct NODE* pHead;
	struct NODE* pTail;
};

void Init(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void AddHead(LIST &l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
		l.pTail->pNext = p;
	}
}

NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = p;
	return p;
}

void Input(LIST &l, ifstream &file)
{
	cout << "Nhap danh sach lien ket don vong" << endl;
	int n;
	file >> n;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		int x;
		file >> x;
		NODE *p = GetNode(x);
		if (p != NULL)
			AddHead(l, p);
	}
}

void Output(LIST l)
{
	if (l.pHead == NULL)
		return;
	NODE *p = l.pHead;
	do
	{
		cout << p->info << " ";
		p = p->pNext;
	} while (p != l.pHead);
	cout << endl;

}

bool isPrime(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

bool isPerfect(int n)
{
	int temp = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			temp += i;

	if (temp == n)
		return true;
	return false;
}

int CountPrimeNumber(LIST l)
{
	int count = 0;
	NODE *p = l.pHead;
	do
	{
		if (isPrime(p->info))
			count++;
		p = p->pNext;
	} while (p != l.pHead);
	return count;
}

int SumPerfectNumber(LIST l)
{
	int count = 0;
	NODE *p = l.pHead;
	do
	{
		if (isPerfect(p->info))
			count += p->info;
		p = p->pNext;
	} while (p != l.pHead);
	return count;
}

int main()
{
	LIST l;
	Init(l);
	ifstream file;
	file.open("TestCase.dat", ifstream::binary | ifstream::in| ifstream::app);
	if (!file)
	{
		cout << "File not found" << endl;
		system("pause");
		return -1;
	}
	
	Input(l, file);
	Output(l);
	cout << "So luong cac so nguyen to trong DSLK la: " << CountPrimeNumber(l) << endl;
	cout << "Tong cac so hoan thien trong danh sach: " << SumPerfectNumber(l) << endl;
	system("pause");
	return 0;
}