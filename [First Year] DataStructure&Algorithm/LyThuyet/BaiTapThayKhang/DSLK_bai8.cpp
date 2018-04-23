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
	Node *pHEAD;
	Node *pTail;
};
//typedef struct List List;

void Init(List &l)
{
	l.pHEAD = NULL;
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

void ADDHEAD(List &l, Node *p)
{
	if (l.pHEAD == NULL)
		l.pHEAD = l.pTail = p;
	else
	{
		p->pNext = l.pHEAD;
		l.pHEAD->pPrev = p;
		l.pHEAD = p;
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
	   	  ADDHEAD(L,p);
	}while (data > -1);
}

void Output(List l)
{
	Node *p = l.pHEAD;
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
	for ( p = l.pHEAD ; p != NULL ;)
	{
		q = GetDuplicate(l,p);
		if ( q != NULL)
		{
			DeleteNode(l,q);
			p = l.pHEAD;
		}
		else
			p = p->pNext;
	}
}

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