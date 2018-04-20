
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



int main()
{
	List L;

	Input(L);
	PrintList(L);

	return 0;
}