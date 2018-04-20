#include <iostream>
#include <cmath>

using namespace std;

struct node
{
	int info;
	struct node *pNext;
	struct node *pPrev;
};


struct List
{
	node *pHEAD;
	node *pTail;
};
//typedef struct List List;

void Init(List &l)
{
	l.pHEAD = NULL;
	l.pTail = NULL;
}

node* GetNode(int x)
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}

void ADDHEAD(List &l, node *p)
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
	Init(L);
	node *p = new node;
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
	node *p = l.pHEAD;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
}

void DeleteNode (List &l, node *q)
{
	cout<<"Deleting"<<endl;
	if ( q == l.pTail)
	{
		l.pTail = q->pPrev;
		l.pTail->pNext = NULL;
		delete q;
		return;
	}
	else
	{
		(q->pPrev)->pNext = q->pNext;
		(q->pNext)->pPrev = q->pPrev;
		q->pNext = NULL;
		q->pPrev = NULL;
		delete q;
		return;
	}
}

void DeleteDuplicate (List &l)
{
	node *p = new node;
	node *q = new node;
	node *t = new node;
	for (p = l.pHEAD; p->pNext != l.pTail ; p = p->pNext)
		for (q = p->pNext; q != NULL ; )
		{
			cout<<p->info<<" "<<q->info<<endl;
			if (q->info == p->info)
				{
					if (q == l.pTail)
						DeleteNode(l,q);
					else
					{
						t = q->pNext;
						DeleteNode (l,q);
						q = t;
					}
					Output(l);
				}
			else
				q = q->pNext;		
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