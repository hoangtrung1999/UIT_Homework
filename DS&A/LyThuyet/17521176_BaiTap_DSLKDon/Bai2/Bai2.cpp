#include <iostream>
#include <cmath>

using namespace std;

struct NODE
{
	int info;
	struct NODE *pNext;
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
	return p;
}

void ADDHEAD(LIST &l, NODE *p)
{
	if (l.pHEAD == NULL)
		l.pHEAD = l.PTAIL = p;
	else
	{
		p->pNext = l.pHEAD;
		l.pHEAD = p;
	}
}

void INPUT(LIST &l)
{
	cout << "Nhap DSLK don cac so nguyen" << endl;
	int n;
	cout << "Nhap so luong cac so nguyen: ";
	cin >> n;
	Init(l);

	int x;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu so nguyen: ";
		cin >> x;
		NODE *p = GETNODE(l, x);
		if (p != NULL)
			ADDHEAD(l, p);
	}
}

void OUTPUT(LIST l)
{
	cout << "DSLK gom nhung phan tu:" << endl;
	NODE *p = l.pHEAD;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
}

bool CheckOdd(LIST l)
{
	NODE *p = l.pHEAD;
	while (p != NULL)
	{
		if (p->pNext->info % 2 != 0)
			return true;
		p = p->pNext;
	}
	return false;
}

void IndexOfMin(LIST l)
{
	NODE *p = l.pHEAD;
	int min = p->info;
	while (p != NULL)
	{
		if (min > p->info)
			min = p->info;
		p = p->pNext;
	}
	cout << &(p)<<endl;
}

int main()
{
	LIST l;
	INPUT(l);
	OUTPUT(l);
	if (CheckOdd(l))
		cout << "DSLK co ton tai so le." << endl;
	else
		cout << "DSLK khong ton tai so le." << endl;
	cout << "Dia chi cua node nho nhat trong dslk la: "; 
	IndexOfMin(l);
	system("pause");
	return 0;
}