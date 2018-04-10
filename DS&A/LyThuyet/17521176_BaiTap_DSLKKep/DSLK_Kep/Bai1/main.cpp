#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct NODE
{
	int info;
	struct NODE *pNext;
	struct NODE *pPrev;
};
//typedef struct node NODE;

struct LIST
{
	NODE *pHEAD;
	NODE *PTAIL;
};
//typedef struct list LIST;

void Init(LIST &l)
{
	l.pHEAD = NULL;
	l.PTAIL = NULL;
}

NODE* GETNODE(LIST &l, int x)
{
	NODE *p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}

void ADDHEAD(LIST &l, NODE *p)
{
	if (l.pHEAD == NULL)
		l.pHEAD = l.PTAIL = p;
	else
	{
		p->pNext = l.pHEAD;
		l.pHEAD->pPrev = p;
		l.pHEAD = p;
	}
}

void INPUT(LIST &l, ifstream &file)
{
	cout << "Nhap DSLK kep cac so nguyen tu file nhi phan" << endl;
	int n;
	file >> n;
	Init(l);

	int x;
	for (int i = 0; i < n; i++)
	{
		file >> x;
		NODE *p = GETNODE(l, x);
		if (p != NULL)
			ADDHEAD(l, p);
	}
}

void OUTPUT(LIST l)
{
	NODE *p = l.pHEAD;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
}

bool isPrime(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i < sqrt(n) + 1; i++)
		if (n % i == 0)
			return false;
	return true;
}

int CountPrimeNumber(LIST l)
{
	int count = 0;
	NODE *p = l.pHEAD;
	while (p != NULL)
	{
		if (isPrime(p->info))
			count++;
		p = p->pNext;
	}
	return count;
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

int SumPerfectNumber(LIST l)
{
	int count = 0;
	NODE *p = l.pHEAD;
	while (p != NULL)
	{
		if (isPerfect(p->info))
			count += p->info;
		p = p->pNext;
	}
	return count;
}

int main()
{
	LIST l;
	ifstream file;
	file.open("TestCase.dat", fstream::in | fstream::out | fstream::app | fstream::binary);
	if (!file)
	{
		cout << "File not found" << endl;
		system("pause");
		return 1;
	}

		INPUT(l, file);
		OUTPUT(l);
		cout << "So luong cac so nguyen to trong DSLK la: " << CountPrimeNumber(l) << endl;
		cout << "Tong cac so hoan thien trong danh sach: " << SumPerfectNumber(l) << endl;
	
	system("pause");
	return 0;
}