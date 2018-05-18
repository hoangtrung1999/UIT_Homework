#include <iostream>
using namespace std;
struct Node
{
	int data;
	int frequency;
	struct Node* pLeft;
	struct Node* pRight;
};
typedef Node* Tree;

void Init ( Tree &t);
bool IsEmpty (Tree t);
Node* GetNode (int x);
int InsertNode (Tree &t , int x );
void Input (Tree &t);
Node* SearchNode (Tree t, int x);


int main()
{
	Tree t;
	int x;
	Node* p;
	Input(t);

	cout<<"Nhap nut X can tim: ";
	cin>>x;
	p = SearchNode(t,x);
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
	p->frequency = 0;
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
		if (t->data	== x)
			t->frequency++;
	   return 0;
	}
	t = GetNode(x);
	if (t->data	== x)
		t->frequency++;
	if (t == NULL)
	   return -1;
	return 1;
}

void Input (Tree &t)
{
	int n;
	cout<<"Nhap n: "<<endl;
	cin>>n;
	Init(t);
	for (int i = 0 ; i < n ; i++)
	{
		int x;
		cin>>x;
		InsertNode(t,x);
	}
}

Node* SearchNode (Tree t, int x)
{	
	if (t == NULL)
	{
		cout<<"Not Found"<<endl;
		return NULL;
	}
	else if ( t->data == x )
	{
		cout<<"Found X"<<endl;
		cout<<"Frequency of X is: "<<t->frequency<<endl;
		return t;
	}
	else
	{
		if (t->data > x)
			return SearchNode(t->pLeft , x);
		return SearchNode(t->pRight, x);
	}
	return NULL;
}