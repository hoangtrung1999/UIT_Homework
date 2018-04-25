#include <iostream>
#include <cmath>

using namespace std;

struct Node
{
	int info;
	struct Node *pNext;
	struct Node *pPrev;
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
void DeleteNode (List &l , Node *p);
Node* GetDuplicate (List l , Node* p);
void DeleteDuplicate(List &l);

int main()
{
	List l;
	Input(l);
	Output(l);
	DeleteDuplicate(l);
	Output(l);
	system("pause");
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
	p->pPrev = NULL;
	return p;
}

void ADDHead(List &l, Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
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

void DeleteNode (List &l , Node *p)
{
	if (p == l.pTail)
	{
		l.pTail = p->pPrev;
		l.pTail->pNext = NULL;
		p->pPrev = NULL;
		// NULL <- p -> NULL
		delete p;
	}
	else
	{
		(p->pPrev)->pNext = p->pNext;
		(p->pNext)->pPrev = p->pPrev;
		p->pPrev = NULL;
		p->pNext = NULL;
		delete p;
	}
}

Node* GetDuplicate (List l , Node* p)
{
	Node* Index = new Node;
	for (Index = p->pNext ; Index != NULL ; Index = Index->pNext)
		if (Index->info == p->info)
			return Index;
	return NULL;
}	

void DeleteDuplicate(List &l)
{
	Node *p = new Node;
	Node *q = new Node;
	for ( p = l.pHead ; p != NULL ;)
	{
		q = GetDuplicate(l,p);
		if ( q != NULL)
		{
			DeleteNode(l,q);
			p = l.pHead;
		}
		else
			p = p->pNext;
	}
}