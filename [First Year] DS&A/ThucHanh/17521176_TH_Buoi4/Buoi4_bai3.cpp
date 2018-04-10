
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
	char left = 0;
	do
	{
	   left = n % 16;
	   n = n / 16;
	   if (left > 9)
	   {
	   	switch(left)
	   	{
	   		case 10:
	   			left = 65;
	   			break;
	   		case 11:
	   			left = 66;
	   			break;
	   		case 12:
	   			left = 67;
	   			break;
	   		case 13:
	   			left = 68;
	   			break;
	   		case 14:
	   			left = 69;
	   			break;
	   		case 15:
	   			left = 70;
	   			break;
	   	}
	   }
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
		if (p->info > 40)
			cout<<char(p->info);
		else
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