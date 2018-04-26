#include <iostream>
using namespace std;
#define MaxNS 2

struct NS
{
	int maso;
	char* hoten;
	int thamnien;
	float hesoluong;
	float luongcoban;
};

struct Node
{
	NS info;
	Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

void Init (List &l);
void AddTail (List &l , Node *p);
Node* GetNode ();
void Input (List &l);
void PrintList (List l);
Node* GetPrev (List l,Node *p);
void SwapNS (List &l, Node *p , Node *q);
void SortList (List &l);
float AvgSalary (List l);

int main()
{
	List l;
	Input(l);
	SortList(l);
	PrintList(l);
	cout<<"Luong trung binh cua nhan vien la: "<<AvgSalary(l)<<endl;

	return 0;
}

void Init (List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void AddTail (List &l , Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
		l.pTail->pNext = NULL;
	}
}

Node* GetNode ()
{
	Node *p = new Node;
	if ( p == NULL)
		return NULL;

	int maso;
	char* hoten = new char[256];
	int thamnien;
	float hesoluong;
	float luongcoban;

	cout<<"Nhap vao thong tin nhan su"<<endl;
	cout<<"Nhap ma so nhan su: ";
	cin>>maso;
	getchar();
	cout<<"Nhap ho ten nhan su: ";
	cin.getline(hoten,255);
	cout<<"Nhap so nam tham nien: ";
	cin>>thamnien;
	cout<<"Nhap he so luong: ";
	cin>>hesoluong;
	cout<<"Nhap luong co ban: ";
	cin>>luongcoban;
	(p->info).maso = maso;
	(p->info).hoten = hoten;
	(p->info).thamnien = thamnien;
	(p->info).hesoluong = hesoluong;
	(p->info).luongcoban = luongcoban;
	p->pNext = NULL;
	return p;
}

void Input (List &l)
{
	Init(l);
	Node *p = new Node;
	if ( p == NULL)
		return;
	for (int i = 0 ; i < MaxNS ; i++)
	{
		p = GetNode();
		AddTail(l,p);
	}
}

void PrintList (List l)
{
	cout<<"Thong tin nhan su"<<endl;
	Node *p = l.pHead;

	while (p != NULL)
	{
		cout<<"Ma so nhan su: "<<(p->info).maso<<endl;
		cout<<"Ho ten nhan su: "<<(p->info).hoten<<endl;
		cout<<"So nam tham nien: "<<(p->info).thamnien<<endl;
		cout<<"He so luong: "<<(p->info).hesoluong<<endl;
		cout<<"Luong co ban: "<<(p->info).luongcoban<<endl;
		p = p->pNext;
	}
}

Node* GetPrev (List l,Node *p)
{
	Node *q = new Node;
	Node *r = new Node;
	// Can't Use q->pNext != p;
	for ( q = l.pHead ; q != p ;q = q->pNext)
		 r = q;
		return r ;
}

void SwapNS (List &l, Node *p , Node *q)
{
	// swap pPrev node
	Node *t = new Node;
	Node *r = new Node;
	t = GetPrev(l,p);
	r = GetPrev(l,q);
	t->pNext = q;
	r->pNext = p;
	// swap pNext node
	t = p->pNext;
	p->pNext = q->pNext;
	q->pNext = t;
	// Set head or tail
	if ( p == l.pHead)
		l.pHead = q;
	else if (q == l.pHead)
		l.pHead = p;
	if ( p == l.pTail)
	{
		l.pTail = q;
		l.pTail->pNext = NULL;
	}
	else if ( q == l.pTail)
	{
		l.pTail = p;
		l.pTail->pNext = NULL;
	}

}

void SortList (List &l)
{
	Node *p = new Node;
	Node *q = new Node;
	for (p = l.pHead ; p->pNext != NULL ; p = p->pNext)
		for ( q = p->pNext ; q != NULL ; q = q->pNext)
			if ((q->info).thamnien > (p->info).thamnien)
			{
				SwapNS(l,p,q);
				p = q;
			}
}

float AvgSalary (List l)
{
	Node *p = l.pHead;
	float Avg = 0;
	do
	{
		Avg += (p->info).luongcoban * (p->info).hesoluong;
		p = p->pNext;
	}while (p!= NULL);
	Avg /= MaxNS;
	return Avg;
}