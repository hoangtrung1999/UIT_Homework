#include <iostream>
#include <string>
using namespace std;

struct Student
{	
	string Name;
	string MSSV;
	int Score;
};

struct NodeStudent
{
	string Name;
	string MSSV;
	int Score;
	NodeStudent *pNext;
};

struct ListStudent
{
	NodeStudent *pHead;
	NodeStudent *pTail;
};

void Init (ListStudent &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NodeStudent* GetNode (string Name, string MSSV, int Score)
{
	NodeStudent *p = new NodeStudent;
	if (p == NULL)
		return NULL;
	p->Name = Name;
	p->MSSV = MSSV;
	p->Score = Score;
	p->pNext = NULL;
	return p;
}

void AddHead (ListStudent &l , NodeStudent* p)
{
		p->pNext = l.pHead;
		l.pHead = p;
}

void InputInfo (ListStudent &l , int n)
{
	NodeStudent *p = new NodeStudent;
	p = l.pHead;
	string Name;
	string MSSV;
	int Score;
	for (int i = 0 ; i < n ; i++)
	{
		cout<<"Nhap thong tin sinh vien "<<i<<endl;
		cout<<"Ten sinh vien: ";
		getline(cin,Name);
		cout<<"Ma so sinh vien: ";
		getline(cin,MSSV);
		cout<<"Diem so sinh vien: ";
		cin>>Score;
		getchar();
		p = GetNode(Name, MSSV , Score);
		AddHead(l,p);
	}
}

void PrintInfo (ListStudent l)
{
	cout<<"Danh sach sinh vien"<<endl;
	NodeStudent *p = new NodeStudent;
	for (p =l.pHead ; p != NULL ; p = p->pNext)
		cout<<p->Name<<endl;
}

void PrintMaxScores (ListStudent l)
{
	int Max = l.pHead->Score;
	cout<<"Nhung sinh vien co diem trung binh cao nhat la"<<endl;
	NodeStudent *p = new NodeStudent;
	for (p = l.pHead->pNext; p != NULL ; p= p->pNext)
		if (Max < p->Score)
			Max = p->Score;
	for (p = l.pHead->pNext; p != NULL ; p= p->pNext)
		if (Max == p->Score)
			cout<<p->Name<<endl;
}

int AboveMedium (ListStudent l)
{
	int count = 0;
	NodeStudent *p = new NodeStudent;
	for (p = l.pHead; p != NULL ; p = p->pNext)
		if ( p->Score >= 5 )
			count++;
	if (count == 0)
	{
		cout<<"Khong co sinh vien nao tren 5"<<endl;
		return 0;
	}
	else
		return count;
}

void FindSV (ListStudent l)
{
	string NameToFind;
	getline(cin,NameToFind);
	NodeStudent *p = new NodeStudent;
	for (p = l.pHead ; p != NULL ; p = p->pNext)
		if ( NameToFind == p->Name)
		{
			cout<<"Sinh vien co ten trong danh sach"<<endl;
			return;
		}
	cout<<"Khong tim thay sinh vien"<<endl;
}

void DeleteNode (ListStudent &l , NodeStudent *p , NodeStudent *q)
{
	p->pNext = q;
	q->pNext = NULL;
	delete q;
}

void DeleteInfo (ListStudent &l)
{
	string Index;
	bool flag = false;
	cout<<"Nhap MSSV can xoa"<<endl;
	getline(cin,Index);

	NodeStudent *p = new NodeStudent;
	NodeStudent *q = new NodeStudent;
	if (l.pHead->MSSV == Index)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		p->pNext = NULL;
		delete p;
	}
	for (p = l.pHead, q = p->pNext; q != NULL ; p = p->pNext , q = q->pNext)
		if (q->MSSV == Index)
		{
			flag = true;
			break;
		}
	if (flag == false)
		cout<<"Khong tim thay sinh vien"<<endl;
		else
			DeleteNode(l,p,q);
	cout<<"Danh sach sinh vien sau khi xoa la: "<<endl;
	PrintInfo(l);	
}

void SortStudent(ListStudent &l)
{
	cout<<"Sap xep danh sach diem sinh vien"<<endl;
	int temp;
	NodeStudent *p = new NodeStudent;
	NodeStudent *q = new NodeStudent;
	for ( p = l.pHead ; p->pNext != NULL ; p = p->pNext)
		for ( q = p->pNext ; q != NULL ; q = q->pNext)
			if (q->Score < p->Score)
			{
				temp = q->Score;
				q->Score = p->Score;
				p->Score = temp;
			}
	cout<<"Danh sach sau khi duoc sap xep la: "<<endl;
	PrintInfo(l);
}

void InsertSV (ListStudent &l)
{
	NodeStudent *p = new NodeStudent;
	p = l.pHead;
	string Name;
	string MSSV;
	int Score;
	cout<<"Nhap thong tin sinh vien "<<endl;
	cout<<"Ten sinh vien: ";
	getline(cin,Name);
	cout<<"Ma so sinh vien: ";
	getline(cin,MSSV);
	cout<<"Diem so sinh vien: ";
	cin>>Score;
	p->Name = Name;
	p->MSSV = MSSV;
	p->Score = Score;

	if (l.pHead->Score > p->Score)
		AddHead(l,p);
	else if (l.pTail->Score < p->Score )
	{
		l.pTail->pNext = p;
		p->pNext = NULL;
	}
	else
	{
		NodeStudent *q = new NodeStudent;
		NodeStudent *r = new NodeStudent;
	for (r = l.pHead , q = (l.pHead)->pNext; q != NULL  ;r = r->pNext, q = q->pNext)
		if ( q->Score > p->Score)
			{
				p->pNext = q;
				r->pNext = p;
			}
	}
	
	
	
	cout<<"Danh sach sinh vien sau khi chen la: "<<endl;
	PrintInfo(l);

}

int main()
{
	int n;
	ListStudent ListStudents;
	cout<<"Nhap so luong sinh vien: ";
	cin>>n;
	getchar();
	InputInfo(ListStudents,n);
	int choice;
	cout<<"Nhap vao lua chon cua ban: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			PrintInfo(ListStudents);
			break;
		case 2:
			PrintMaxScores(ListStudents);
			break;
		case 3:
			cout<<"So sinh vien co diem trung binh >= 5 la: "<<AboveMedium(ListStudents);
			break;
		case 4:
			FindSV(ListStudents);
			break;
		case 5:
			DeleteInfo(ListStudents);
			break;
		case 6:
			SortStudent(ListStudents);
			break;
		case 7:
			InsertSV(ListStudents);
			break;
	}
	return 0;
}