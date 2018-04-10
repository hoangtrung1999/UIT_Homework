
//D:\Project C++\ThucHanhUIT
#include <iostream>
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

void AddTail (List &L)
{
	cout<<"Add Tail"<<endl;
	Node *p = new Node;
	Node *q = new Node;
	if (p == NULL)
		return;
	int data;
	cin>>data;
	p = GetNode(data);
	AddHead(L,p);
	p = L.pHead;
	q = p->pNext;
	do
	{
		p->info = q->info;
		p = p->pNext;
		q = p->pNext;
		if (q == NULL)
		{
			p->info = data;
			break;
		}
	}while(q != NULL);
}

void Input (List &L)
{
	cout<<"Input"<<endl;
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
	   	  AddHead(L,p);
	}while (data > -1);
}

void PrintList (List L)
{
	Node* p = new Node;
	if (p == NULL)
		return;
	p = L.pHead;
	do
	{
		cout<<p->info<<" ";
		p = p->pNext;
	}while(p != NULL);
	cout<<endl;
}

int CountNode (List L)
{
	int count = 0 ;
	Node *p = new Node;
	p = L.pHead;
	do
	{
		count++;
		p = p->pNext;
	}while(p != NULL);
	return count;
}

int FindNode (List L)
{
	cout<<"Input X: ";
	int X;
	cin>>X;
	Node *p = new Node;
	p = L.pHead;
	do
	{
		if (p->info == X)
			return X;
		p = p->pNext;
	}while (p != NULL);
	return 0;
}

void DeleteTail (List &L)
{
	Node *p = new Node;
	Node *q = new Node;
	Node *r = new Node;
	if (p == NULL || q == NULL)
		return;
	p = L.pHead;
	q = p->pNext;
	r = q->pNext;
	do
	{	
		p = p->pNext;
		q = p->pNext;
		r = q->pNext;
	} while(r!= NULL);
	p->pNext = NULL;
	L.pTail = p;
}

void DeleteHead (List &L)
{
	Node *p = new Node;
	Node *q = new Node;
	if (p == NULL)
		return;
	p = L.pHead;
	q = p->pNext;
	do
	{
		p->info = q->info;
		p = p->pNext;
		q = p->pNext;
	}while(q != NULL);
	DeleteTail(L);
}

void DeleteNode (List &L)
{
	int x = FindNode(L);
	if (x)
		{
			Node *p = new Node;
			Node *q = new Node;
			p = L.pHead;
			do
			{
				if (p->info == x)
					break;
				p = p->pNext;
			}while (p != NULL);

			if (p->info == L.pTail->info)
				DeleteTail(L);
			else if (p->info == L.pHead->info)
				DeleteHead(L);
			else
			{
				q = p->pNext;
				do
				{
					p->info = q->info;
					p = p->pNext;
					q = p->pNext;
				}while (q != NULL);
				DeleteTail(L);
			}
		}
}

void SortList (List &L)
{
	Node *p = new Node;
	Node *q = new Node;
	if (p == NULL || q == NULL)
		return;
	p = L.pHead;
	for (; p != NULL ; p = p->pNext)
		for (q = p->pNext; q != NULL ; q = q->pNext)
			if (p->info > q->info)
				swap(p->info,q->info);
}

void InsertNode (List &L)
{
	Node *p = new Node;
	Node *q = new Node;
	if ( p != NULL)
	{
		int data;
		cin>>data;
		p = GetNode(data);
		AddHead(L,q);
		q = L.pHead;
		do
		{
			q->info = q->pNext->info;
			q = q->pNext;
		}while(q != NULL && q->pNext->info < p->info);
		q->info = p->info;
	}
}

int main()
{
	List L;

	Input(L);
	PrintList(L);

	AddTail(L);
	PrintList(L);

	cout<<"Singly Linked List Has "<<CountNode(L)<<" nodes"<<endl;

	FindNode(L)? cout<<"Found X"<<endl : cout<<"Not Found X"<<endl;

	cout<<"Delete Tail"<<endl;
	DeleteTail(L);
	PrintList(L);

	cout<<"Delete Head"<<endl;
	DeleteHead(L);
	PrintList(L);

	cout<<"Delete X"<<endl;
	DeleteNode(L);
	PrintList(L);

	cout<<"Sort List"<<endl;
	SortList(L);
	PrintList(L);

	cout<<"Insert Node"<<endl;
	InsertNode(L);
	PrintList(L);
	return 0;
}