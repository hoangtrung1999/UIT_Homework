
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

void Convert (List &L , int n)
{
	Init(L);
	Node *p = new Node;
	if (p == NULL)
		return;
	int left = 0;
	do
	{
	   left = n % 2;
	   n = n / 2;
	   p = GetNode(left);
	   if (p != NULL)
	   	  AddHead(L,p);
	}while (n > 0);
}

void PrintList (List L)
{
	Node* p = new Node;
	if (p == NULL)
		return;
	p = L.pHead;
	do
	{
		cout<<p->info;
		p = p->pNext;
	}while(p != NULL);
	cout<<endl;
}

int main()
{
	List L;
	int n;
	cout<<"Input the number that need to be converted: ";
	cin>>n;
	Convert(L,n);
	PrintList(L);

	return 0;
}