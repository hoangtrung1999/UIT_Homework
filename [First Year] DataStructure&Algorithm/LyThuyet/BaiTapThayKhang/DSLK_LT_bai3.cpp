#include <iostream>
#include <cmath>

using namespace std;

struct Node
{
	int info;
	struct Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};
//typedef struct List List;
void Init(List &l);
Node* GetNode(int x);
void ADDHead(List &l, Node *p);
void Input (List &L);
void Output(List l);
void CreateEvenList (List &l , List &l1);
Node* FindPrevNode (List l , Node* p);
void PutEvenNode (List &l , List &l1 , Node* p);

int main()
{
	List l;
	List l1;
	Input(l);
	Output(l);
	CreateEvenList(l,l1);
	cout<<"After divide"<<endl;
	Output(l);
	Output(l1);
	return 0;
}

void Init(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

Node* GetNode(int x)
{
	Node *p = new Node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void ADDHead(List &l, Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void Input (List &L)
{
	cout<<"Input"<<endl;
	cout<<"Enter -1 to finish input"<<endl;
	Init(L);
	Node *p = new Node;
	if (p == NULL)
		return;
	int data;
	do
	{
	   cin>>data;
	   p = GetNode(data);
	   if (p != NULL && data > -1)
	   	  ADDHead(L,p);
	}while (data > -1);
}

void Output(List l)
{
	Node *p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
}

void CreateEvenList (List &l , List &l1)
{
	Init(l1);
	Node *p = l.pHead;
	Node *q;
	if (p->info % 2 == 0)
	{
		PutEvenNode(l,l1,p);
		p = p->pNext;
	}
	Output(l);
	Output(l1);
	do
	{
		if (p->info % 2 == 0)
		{
			q = FindPrevNode(l,p);
			PutEvenNode(l,l1,p);
			p = q;
		}
		else
			p = p->pNext;
	}while (p);
}
Node* FindPrevNode (List l , Node* p)
{
	if (p == l.pHead)
		return NULL;
	Node* q = l.pHead;
	do
	{
		q = q->pNext;
	}while(q->pNext != p);
	return q;
}

void PutEvenNode (List &l , List &l1 , Node* p)
{
	if ( p == l.pHead)
	{
		l.pHead = p->pNext;
		ADDHead(l1,p);
	}
	Node* q = FindPrevNode(l,p);
	if (q == l.pTail)
		q->pNext = NULL;
	else
	{
		q->pNext = p->pNext;
		p->pNext = NULL;
		ADDHead(l1,p);
	}
}