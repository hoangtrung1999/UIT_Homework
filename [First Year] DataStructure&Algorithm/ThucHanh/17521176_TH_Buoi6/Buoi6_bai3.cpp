#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
	int data;
	struct Node* pLeft;
	struct Node* pRight;
};
typedef Node* Tree;

void Init ( Tree &t);
bool IsEmpty (Tree t);
Node* GetNode (int x);
int InsertNode (Tree &t , int x );
void Input (Tree &t,ifstream& File);
void PrintLRN (Tree t);

int main()
{
	Tree t;
	ifstream File;
	File.open("Text.txt");
	Input(t, File);
	PrintLRN(t);
	File.close();
	return 0;
}

void Init ( Tree &t)
{
	t = NULL;
}

bool IsEmpty (Tree t)
{
	if (t == NULL)
	   return t;
	return 0;
}
Node* GetNode (int x)
{
	Node *p = new Node;
	if (p == NULL)
	   return NULL;
	p->data = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

int InsertNode (Tree &t , int x )
{
	if (t != NULL)
	{
	   if (t->data < x)
		return InsertNode (t->pRight, x);
	   if (t->data > x)
		return InsertNode (t->pLeft,x);
	   return 0;
	}
	t = GetNode(x);
	if (t == NULL)
	   return -1;
	return 1;
}

void Input (Tree &t, ifstream& File)
{
	int n;
	if (File)
		File>>n;
	Init(t);
	for (int i = 0 ; i < n ; i++)
	{
		int x;
		if (File)
			File>>x;
		InsertNode(t,x);
	}
}
void PrintLRN (Tree t)
{

	if (t == NULL)
		return;
	PrintLRN(t->pLeft);
	PrintLRN(t->pRight);
	cout<<t->data<<" ";
}