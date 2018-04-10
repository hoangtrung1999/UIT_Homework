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

bool CheckOdd(LIST l)
{
	NODE *p = l.pHead;
	do
	{
		if (p->pNext->info % 2 != 0)
			return true;
		p = p->pNext;
	} while (p != l.pHead);
	return false;
}

void IndexOfMin(LIST l)
{
	NODE *p = l.pHead;
	int min = p->info;
	do
	{
		if (min > p->info)
			min = p->info;
		p = p->pNext;
	} while (p != l.pHead);
	cout << &(p) << endl;
}

int main()
{
	LIST l;
	Init(l);
	ifstream file;
	file.open("TestCase.dat", ifstream::binary | ifstream::in | ifstream::app);
	if (!file)
	{
		cout << "File not found" << endl;
		system("pause");
		return -1;
	}

	Input(l, file);
	Output(l);
	if (CheckOdd(l))
		cout << "DSLK co ton tai so le." << endl;
	else
		cout << "DSLK khong ton tai so le." << endl;
	cout << "Dia chi cua node nho nhat trong dslk la: ";
	IndexOfMin(l);
	system("pause");
	return 0;
}