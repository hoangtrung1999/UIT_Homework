#include <iostream>
using namespace std;
#define MaxNS 1

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

void SortNS (List &l)
{
	Node *p = new Node;
	Node *q = new Node;
	
}

int main()
{
	List l;
	Input(l);
	PrintList(l);
	return 0;
}