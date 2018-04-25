#include <iostream>
#include <string>
using namespace std;

struct Doc
{
	int Index;
	string Name;
	int Amount;
};

struct Node
{
	Doc doc;
	Node *pNext;
};

struct ListDocs
{
	Node *pHead;
	Node *pTail;
};


void Init (ListDocs &l);
void AddHead (ListDocs &l , Node *p);
Node* InputDoc ();
void InputList (ListDocs &l , int n);
void PrintList (ListDocs l);
void SwapDoc (Node *p , Node *q);
void SortList (ListDocs &l);


int main()
{
	ListDocs l;
	int n;
	cout<<"Nhap vao so loai tai lieu: ";
	cin>>n;
	getchar();
	InputList(l,n);
	PrintList(l);
	cout<<"Ho so sau khi sap xep: "<<endl;
	SortList(l);
	PrintList(l);
	return 0;
}


void Init (ListDocs &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void AddHead (ListDocs &l , Node *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

Node* InputDoc ()
{
	int Index;
	string Name;
	int Amount;

	Node *p = new Node;

	if ( p == NULL)
		return NULL;

	cout<<"Nhap vao ma so ho so"<<endl;
	cin>>Index;
	getchar();
	cout<<"Nhap vao ten ho so"<<endl;
	getline(cin,Name);
	cout<<"Nhap vao so luong ho so"<<endl;
	cin>>Amount;
	getchar();

	(p->doc).Index = Index;
	(p->doc).Name = Name;
	(p->doc).Amount = Amount;
	p->pNext = NULL;
	return p;
}

void InputList (ListDocs &l , int n)
{
	Init(l);
	for (int i = 0 ; i < n ; i++)
	{
		Node *p = new Node;
		p = InputDoc();
		AddHead (l,p);
	}
}

void PrintList (ListDocs l)
{
	Node *p = l.pHead;
	cout<<"Thong tin ho so"<<endl;
	do
		{
			cout<<"Ma so: "<<(p->doc).Index<<endl;
			cout<<"Ten tai lieu: "<<(p->doc).Name<<endl;
			cout<<"So luong tai lieu: "<<(p->doc).Amount<<endl;
			cout<<endl;
			p = p->pNext;
		} while (p != NULL);
}

Node* GetPrev (ListDocs l,Node *p)
{
	Node *q = new Node;
	Node *r = new Node;
	// Can't Use q->pNext != p;
	for ( q = l.pHead ; q != p ;q = q->pNext)
		 r = q;
		return r ;
}

void SwapDoc (ListDocs &l, Node *p , Node *q)
{
	// swap pPrev node
	Node *t = new Node;
	Node *r = new Node;
	t = GetPrev(l,p);
	r = GetPrev(l,q);
	t->pNext = q;
	r->pNext = p;
	// swap pNext node
	t = p->pNext;
	p->pNext = q->pNext;
	q->pNext = t;

	if ( p == l.pHead)
		l.pHead = q;
	else if (q == l.pHead)
		l.pHead = p;
	if ( p == l.pTail)
	{
		l.pTail = q;
		l.pTail->pNext = NULL;
	}
	else if ( q == l.pTail)
	{
		l.pTail = p;
		l.pTail->pNext = NULL;
	}

}

void SortList (ListDocs &l)
{
	Node *p = new Node;
	Node *q = new Node;
	for (p = l.pHead ; p->pNext != NULL ; p = p->pNext)
		for ( q = p->pNext ; q != NULL ; q = q->pNext)
			if ((q->doc).Amount < (p->doc).Amount)
			{
				cout<<(q->doc).Amount<<" "<<(p->doc).Amount<<endl;
				SwapDoc(l,p,q);
				p = q;
			}
}

