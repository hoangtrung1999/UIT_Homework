#include <iostream>
#include <fstream>
using namespace std;

struct NODE
{
	float info;
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

NODE* GetNode(float x)
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
		float x;
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

bool CheckNegative(LIST l)
{
	NODE *p = l.pHead;
	do
	{
		if (p->info < 0)
			return false;
		p = p->pNext;
	} while (p != l.pHead);
	return true;
}

void SortList(LIST &l)
{
	NODE* p;
	NODE* q;
	NODE* pivot = l.pHead;
	while (pivot->pNext != l.pTail)
	{
		pivot = pivot->pNext;
	}
	
	for (p = l.pHead ; p != pivot ; p = p->pNext)
	{ 
		for (q = p->pNext; q != l.pHead; q = q->pNext)
			if (q->info < p->info)
			{
				float temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		Output(l);
	}
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
	if (CheckNegative(l))
		cout << "DSLK toan so duong." << endl;
	else
		cout << "DSLK co so am." << endl;
	SortList(l);
	Output(l);
	system("pause");
	return 0;
}