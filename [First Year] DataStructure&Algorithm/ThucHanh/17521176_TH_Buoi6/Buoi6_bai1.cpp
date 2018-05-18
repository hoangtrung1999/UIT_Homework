#include <iostream>
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
void Input (Tree &t);
void PrintLNR (Tree t);
void PrintLRN (Tree t);
void PrintNLR (Tree t);
void PrintNRL (Tree t);
void PrintRNL (Tree t);
void PrintRLN (Tree t);
Node* SearchNode (Tree t, int x);
void DeleteNode (Tree &t);
void CountNode (Tree t, int &count);
void CountLeafs (Tree t, int &count);
void CountFullNodes (Tree t, int &count);
void CountHeight (Tree t , int &count);

int main()
{
	Tree t;
	int x;
	Node* p;
	int count = 0;
	Input(t);

	cout<<"LNR: ";
	PrintLNR(t);
	cout<<endl;

	cout<<"LRN: ";	
	PrintLRN(t);
	cout<<endl;

	cout<<"RNL: ";	
	PrintRNL(t);
	cout<<endl;

	cout<<"RLN: ";
	PrintRLN(t);
	cout<<endl;

	cout<<"NRL: ";	
	PrintNRL(t);
	cout<<endl;

	cout<<"NLR: ";	
	PrintNLR(t);
	cout<<endl;

	cout<<"Nhap X can tim: "<<endl;
	cin>>x;
	p = SearchNode(t,x);

	CountNode(t,count);
	cout<<"So nut trong cay: "<<count<<endl;
	
	count = 0;
	CountLeafs(t,count);
	cout<<"So la trong cay: "<<count<<endl;

	count = 0;
	CountFullNodes(t,count);
	cout<<"So nut co day du 2 con la: "<<count<<endl;

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

void Input (Tree &t)
{
	int n;
	cout<<"Nhap n: "<<endl;
	cin>>n;
	Init(t);
	for (int i = 0 ; i < n ; i++)
	{
		int x;
		cout<<"Nhap Node: ";
		cin>>x;
		InsertNode(t,x);
	}
}

void PrintLNR (Tree t)
{

	if (t == NULL)
		return;
	PrintLNR (t->pLeft);
	cout<<t->data<<" ";
	PrintLNR (t->pRight);
}

void PrintLRN (Tree t)
{

	if (t == NULL)
		return;
	PrintLRN(t->pLeft);
	PrintLRN(t->pRight);
	cout<<t->data<<" ";
}

void PrintNLR (Tree t)
{

	if (t == NULL)
		return;
	cout<<t->data<<" ";
	PrintNLR(t->pLeft);
	PrintNLR(t->pRight);
}

void PrintNRL (Tree t)
{

	if (t == NULL)
		return;
	cout<<t->data<<" ";
	PrintNRL(t->pRight);
	PrintNRL(t->pLeft);
}

void PrintRNL (Tree t)
{

	if (t == NULL)
		return;
	PrintRNL(t->pRight);
	cout<<t->data<<" ";
	PrintRNL(t->pLeft);
}

void PrintRLN (Tree t)
{

	if (t == NULL)
		return;
	PrintRNL(t->pRight);
	PrintRNL(t->pLeft);
	cout<<t->data<<" ";
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

void DeleteNode (Tree &t)
{
	int x;
	Node *p;
	cout<<"Nhap X can tim: "<<endl;
	cin>>x;
	p = SearchNode(t,x);
	if (p)
	{

	}
	else
	{
		cout<<"X not found";
	}
}

void CountNode (Tree t, int &count)
{
	if (t == NULL)
		return;
	CountNode (t->pLeft,count);
	CountNode (t->pRight,count);
	count++;
}

void CountLeafs (Tree t, int &count)
{
	if (t == NULL)
		return;
	if (t->pLeft == NULL && t->pRight == NULL)
		count++;
	CountLeafs (t->pLeft,count);
	CountLeafs (t->pRight,count);
}

void CountFullNodes (Tree t, int &count)
{
	if (t == NULL)
		return;
	if (t->pLeft && t->pRight)
		count++;
	CountFullNodes (t->pLeft,count);
	CountFullNodes (t->pRight,count);
}

void CountHeight (Tree t , int &count)
{
}