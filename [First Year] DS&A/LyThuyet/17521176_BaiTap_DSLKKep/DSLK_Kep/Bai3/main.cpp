#include <iostream>
#include <fstream>
#include <cmath>

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

bool CheckNegative(LIST l)
{
	NODE *p = l.pHEAD;
	while (p != NULL)
	{
		if (p->info < 0)
			return false;
		p = p->pNext;
	}
	return true;
}

void SortList(LIST &l)
{
	for (NODE*p = l.pHEAD; p->pNext; p = p->pNext)
	{
		NODE *pivot = p;
		for (NODE *q = p; q; q = q->pNext)
			if (q->info < pivot->info)
				pivot = q;
		float temp = p->info;
		p->info = pivot->info;
		pivot->info = temp;
	}
}

int main()
{
	LIST l;
	ifstream file;
	file.open("TestCase.dat", fstream::in | fstream::out | fstream::app | fstream::binary);
	INPUT(l,file);
	OUTPUT(l);
	if (CheckNegative(l))
		cout << "DSLK toan so duong." << endl;
	else
		cout << "DSLK co so am." << endl;
	cout << "Danh sach sau khi sap xep" << endl;
	SortList(l);
	OUTPUT(l);
	system("pause");
	return 0;
}