#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
	double x;
	double y;
};

struct Square
{
	Point* a;
	Point* b;
	Point* c;
	Point* d;
	double DT;
	Square* pNext;
};

struct List
{
	Square* pHead;
	Square* pTail;
};

Point* GetPoint();
Square* MakeSquare (Point* a, Point* b, Point* c, Point* d);
void AddTail (List& l , Square* S);
void Input (List &l);
void Output(List l);
Square* FindTheBiggest (List l);
Square* FindNode (double X, List l);
Square* FindPrev (List l, double X);
void DeleteNode (List &l);
void SortList (List& l);

int main()
{
	List l;
	Input(l);
	Output(l);
	FindTheBiggest(l);
	DeleteNode(l);
	Output(l);
	cout<<"Sap Xep"<<endl;
	SortList(l);
	Output(l);
	return 0;
}

void Init (List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

Point* GetPoint()
{
	cout<<"Nhap vao toa do diem: "<<endl;
	Point* a = new Point;
	int x;
	cout<<"x: ";
	cin>>x;
	cout<<"y: ";
	int y;
	cin>>y;
	a->x = x;
	a->y = y;
	return a;
}

Square* MakeSquare (Point* a, Point* b, Point* c, Point* d)
{
	Square* S = new Square;
	S->a = a;
	S->b = b;
	S->c = c;
	S->d = d;
	S->pNext = NULL;
	double V1 = sqrt ((a->x - b->x)*(a->x - b->x)+(a->y - b->y)*(a->y - b->y));
	double H1 = sqrt ((a->x - c->x)*(a->x - c->x)+(a->y - c->y)*(a->y - c->y));
	S->DT = V1*H1;
	return S;
}

void AddTail (List& l , Square* S)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = S;
	else
	{
		l.pTail->pNext = S;
		l.pTail = S;
	}
}

void Input (List &l)
{
	Init(l);
	int n;
	Square* S;
	Point* a;
	Point* b;
	Point* c;
	Point* d;
	cout<<"Nhap so luong hcn: ";
	cin>>n;
	for (int i = 0 ; i < n ; i++)
	{
		a = GetPoint();
		b = GetPoint();
		c = GetPoint();
		d = GetPoint();
		S = MakeSquare(a,b,c,d);
		AddTail(l,S);
	}
}

void Output(List l)
{
	cout<<"In hinh chu nhat: "<<endl;
	Square* p = l.pHead;
	do
	{
		cout<<"xA: "<< p->a->x <<" yA: "<< p->a->y <<endl;
		cout<<"xB: "<< p->b->x <<" yB: "<< p->b->y <<endl;
		cout<<"xC: "<< p->c->x <<" yC: "<< p->c->y <<endl;
		cout<<"xD: "<< p->d->x <<" yD: "<< p->d->y <<endl;
		cout<<"Dien tich: "<<p->DT<<endl;
		p = p->pNext;
	}while (p);
}

void SortList (List& l) // Lam au vi het gio :|
{
	Square* p = new Square;
	Square* q = new Square;
	Square* temp = new Square;
	for (p = l.pHead ; p->pNext ; p = p->pNext)
		for (q = p->pNext ; q ; q = q->pNext)
			if (q->DT < p->DT)
			{	
				temp->a = q->a;
				temp->b = q->b;
				temp->c = q->c;
				temp->d = q->d;
				temp->DT = q->DT;
				temp->pNext = q->pNext;

				q->a = p->a;
				q->b = p->b;
				q->c = p->c;
				q->d = p->d;
				q->DT = p->DT;
				q->pNext = p->pNext;

				p->a = temp->a;
				p->b = temp->b;
				p->c = temp->c;
				p->d = temp->d;
				p->DT = temp->DT;
				p->pNext = temp->pNext;
			}

}

Square* FindNode (double X, List l)
{
	Square* p = l.pHead;
	do
	{
		if (p->DT == X)
			return p;
	}while(p);
	return NULL;
}

Square* FindPrev (List l, double X)
{
	Square* p = l.pHead;
	Square* q = NULL;
	do
	{
		if (p->DT == X)
			return q;
		else
		{
			q = p;
			p = p -> pNext;
		}
	}while(p);
	return q;
}

void DeleteNode (List &l) // Chi xoa khi dien tich la so nguyen vi khong the so sanh 2 so double bang nhau chinh xac duoc
{
	cout<<"Nhap vao dien tich cua hinh chu nhat can xoa: ";
	double X;
	cin>>X;
	Square *p = FindNode(X,l);
	if (p->DT == l.pHead->DT)
	{
		l.pHead = p->pNext;
		p->pNext = NULL;
		delete p;
	}
	else if (p->DT == l.pTail->DT)
	{
		Square* temp = FindPrev(l,p->DT);
		temp->pNext = NULL;
		l.pTail = temp;
		delete p;
	}
	else // Bi loi neu xoa o giua 
	{
		Square* temp = FindPrev(l,p->DT);
		Square* next = p->pNext;
		temp->pNext = next;
		p->pNext = NULL;
		delete p;
	}
}

Square* FindTheBiggest (List l)
{
	cout<<"Hinh chu nhat co dien tich lon nhat la: ";
	Square* p = l.pHead;
	double Max = p->DT;
	do
	{
		if (p->DT > Max)
			Max	= p->DT;
		p = p->pNext;
	}while(p);
	cout<<Max<<endl;
	return p;
}


