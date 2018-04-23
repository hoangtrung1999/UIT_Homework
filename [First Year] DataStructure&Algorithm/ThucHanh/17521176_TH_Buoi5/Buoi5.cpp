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

void SwapDoc (Node *p , Node *q)
{
	Node *t;
	/*(t->doc).Index = (p->doc).Index;
	(t->doc).Name = (p->doc).Name;
	(t->doc).Amount = (p->doc).Amount;

	(p->doc).Index = (q->doc).Index;
	(p->doc).Name = (q->doc).Name;
	(p->doc).Amount = (q->doc).Amount;

	(q->doc).Index = (t->doc).Index;
	(q->doc).Name = (t->doc).Name;
	(q->doc).Amount = (t->doc).Amount;*/
	t = q;
	t->pNext = q->pNext;
	q = p;
	q->pNext = p->pNext;
	p = t;
	p->pNext = t->pNext;

}

void SortList (ListDocs &l)
{
	Node *p = new Node;
	Node *q = new Node;
	for (p = l.pHead ; p->pNext != NULL ; p = p->pNext)
		for ( q = p->pNext ; q != NULL ; q = q->pNext)
			if ((q->doc).Amount < (p->doc).Amount)
			{
				SwapDoc(p,q);
			}
}

