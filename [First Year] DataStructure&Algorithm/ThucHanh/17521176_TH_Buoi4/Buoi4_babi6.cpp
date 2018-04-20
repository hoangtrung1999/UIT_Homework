#include <iostream>
#include <string>
using namespace std;

struct Node
{	
	int info;
	Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

void Init (List &L)
{
	L.pHead = NULL;
	L.pTail = NULL;
}

Node* GetNode (int data)
{
	Node *p = new Node;
	if (p == NULL)
		return NULL;
	p->info = data;
	p->pNext = NULL;
	return p;
}

void AddHead (List &L ,Node *p)
{
	if (L.pHead == NULL)
		L.pHead = L.pTail = p;
	else
	{
		p->pNext = L.pHead;
		L.pHead = p;
	}
}

void PrintList (List L)
{
	Node* p = new Node;
	if (p == NULL)
		return;
	p = L.pHead;
	for (; p != NULL ; p = p->pNext)
		cout<<p->info;
}

void AddZero (List &l1 , List &l2 , int n1 , int n2)
{
	int n;
	Node *p = new Node;
	if ( n1 > n2)
	{
		n = n1-n2;
		for (int i = 0 ; i < n ; i++)
		{
			p = GetNode(0);
			AddHead(l2,p);
		}
	}
	else
	{
		if ( n1 < n2)
		{
			n = n2-n1;
		for (int i = 0 ; i < n ; i++)
			{
				p = GetNode(0);
				AddHead(l1,p);
			}
		}
	}
}

void AddNumtoList (List &l , char* Sc, int n)
{
	int convert = 0;

	Node *p = new Node;
	for (int i = 0 ; i < n - 1 ; i++)
	{
		convert = Sc[i] - '0';
		p = GetNode(convert);
		AddHead(l,p);	
	}
}

List Sum (List l1, List l2)
{
	int temp = 0;
	int extra = 0;
	int convert;
	List l;
	Init(l);
	Node *p = new Node;
	Node *q = new Node;
	Node *r = new Node;

	for (p = l.pHead , q = l1.pHead , r = l2.pHead; q != NULL && r != NULL ;)
	{
		temp = q->info + r->info + extra;
		convert = temp % 10;
		extra = temp / 10;
		p = GetNode(convert);
		AddHead(l,p);
		q = q->pNext;
		r = r->pNext;
	}
	
	if (extra > 0)
	{
		p = GetNode(extra);
		AddHead(l,p);
	}
	
	return l;
}

int main()
{
	string S1;
	string S2;
	char *S1c;
	char *S2c;
	char c;
	do
	{
		c = getchar();
		S1.push_back(c);
	}while (c != ' ');
	do
	{
		c = getchar();
		S2.push_back(c);
	}while (c != '\n');

	S1c = new char(S1.size());
	S2c = new char(S2.size());

	for (int i = 0 ; i < S1.size() ; i++)
		S1c[i] = S1[i];
	for (int j = 0 ; j < S2.size() ; j++)
		S2c[j] = S2[j];


	List l1;
	List l2;

	AddZero(l1,l2, S1.size(), S2.size());

	AddNumtoList(l1,S1c,S1.size());	
	AddNumtoList(l2,S2c,S2.size());
	List l;
	l = Sum(l1,l2);
	PrintList(l);
	return 0;
}
