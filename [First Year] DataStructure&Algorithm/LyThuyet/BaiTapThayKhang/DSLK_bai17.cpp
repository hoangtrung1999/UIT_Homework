#include <iostream>
using namespace std;
#define MaxLine 3
#define MaxSizeOfLine 80
struct Node
{
	char* Line;
	Node* pNext;
};

struct List
{
	Node* pHead;
	Node* pTail;
};

int NumberOfLine;
int NumberOfColumn;
int TotalLine;
Node* Cursor = nullptr;

void Init (List &l);
void AddTail (List &l , Node* p);
Node* GetNode();
void Input (List &l);
void Output (List l);
void Menu (List &l);
void AddCharacterInLine(List &l);
void MoveCursor(List l);
Node* SearchLine (List l);
void ShowCursor(List l);
int main()
{
	List l;
	Input(l);
	Output(l);
	Menu(l);
	return 0;
}

void Init (List &l)
{
	l.pHead = nullptr;
}

void AddTail (List &l , Node* p)
{
	if (l.pHead == nullptr)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

Node* GetNode()
{
	char* InputLine = new char [MaxSizeOfLine];
	cin.getline(InputLine,MaxSizeOfLine);
	Node* p = new Node;
	p->Line = InputLine;
	p->pNext = nullptr;
	return p;
}

void Input (List &l)
{
	cout<<"\tType your document here"<<endl;
	Init(l);
	for (int i = 0 ; i < MaxLine ; i++)
	{
		Node* p;
		p = GetNode();
		AddTail(l,p);
		TotalLine++;
	}
}

void Output (List l)
{
	Node* p = l.pHead;
	cout<<"\tPrint Document"<<endl;
	do 
	{
		cout<<p->Line<<endl;
		p = p->pNext;
	}while (p);
}

void Menu (List &l)
{

	int choice;
	do
	{
		cout<<"\tSelect one function"<<endl;
		cout<<"1/ Move cursor in this document"<<endl;
		cout<<"2/ Add 1 character in 1 line"<<endl;
		cout<<"3/ Delete 1 character in 1 line"<<endl;
		cout<<"4/ Edit 1 character in 1 line"<<endl;
		cout<<"5/ Add 1 line"<<endl;
		cout<<"6/ Delete 1 line"<<endl;
		cout<<"7/ Mark and copy a group"<<endl;
		cout<<"8/ Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		getchar();
		switch (choice)
		{
			case 1:
				MoveCursor(l);
				break;
			case 2:
				AddCharacterInLine(l);
				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			case 8:
				cout<<"Exiting..."<<endl;
				break;
		}
	}while (choice != 8);

}

Node* SearchLine (List l)
{
	Node *p = l.pHead;
	for (int i = 0 ; i < NumberOfLine ; i++)
		p = p->pNext;
	return p;
}

char SearchColumn ()
{
	return Cursor->Line[NumberOfColumn];
}
	
void MoveCursor (List l)
{
	char c;
	char* Move = new char[MaxSizeOfLine];
	int i = 0;
	int MaxMove = 0;
	
	ShowCursor(l);
	cout<<"Enter the move of the cursor you want to: "<<endl;
	cout<<"(L = Left / R = Right / U = Up / D = Down)"<<endl;
	
	do
	{
		c = getchar();
		Move[i++] = c;
		MaxMove++;
	}while ( c != '\n' || i > MaxSizeOfLine - 1);

	for (int i = 0 ; i < MaxMove ; i++)
	{
			switch(Move[i])
			{
				case 'U':
					NumberOfLine--;
					break;
				case 'D':
					NumberOfLine++;
					break;
				case 'R':
					NumberOfColumn++;
					break;
				case 'L':
					NumberOfColumn--;
					break;
			}
	}
	Cursor = SearchLine(l);
	c = SearchColumn();
	ShowCursor(l);
	delete[] Move;
}

void ShowCursor (List l)
{
	if (Cursor == nullptr)
	{
		cout<<"The cursor is pointing at "<<NumberOfLine<<" line."<<endl;
		cout<<"The cursor is pointing at "<<NumberOfColumn<<"th character in line."<<endl;
		cout<<"The Cursor is pointing at "<<l.pHead->Line[0]<<endl;
	}
	else
	{
		cout<<"The cursor is pointing at "<<NumberOfLine<<" line."<<endl;
		cout<<"The cursor is pointing at "<<NumberOfColumn<<"(th) character in line."<<endl;
		cout<<"The Cursor is pointing at "<<Cursor->Line[NumberOfColumn]<<endl;
	}
}

void AddCharacterInLine (List &l)
{
	MoveCursor(l);
	char c;
	cout<<"Input the character that you want to insert: ";
	cin>>c;
	
}
