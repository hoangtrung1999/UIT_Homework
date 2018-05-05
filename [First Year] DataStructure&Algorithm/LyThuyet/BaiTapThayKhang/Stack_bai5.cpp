#include <iostream>
#include <string>
using namespace std;
#define Max 100
struct  Stack
{
	int n;
	char Storage[Max];
};

void Push (Stack &s , char x)
{
	s.Storage[s.n++] = x;
}

char Pop (Stack &s)
{
	char c = s.Storage[s.n-1];
	s.n--;
	return c;
}

void Init (Stack &s)
{
	s.n = 0;
}

bool IsEmpty (Stack s)
{
	if ( s.n == 0)
		return true;
	return false;
}

bool IsFull (Stack s)
{
	if ( s.n == Max )
		return true;
	return false;
}

bool CheckPair (char a , char b)
{
	//cout<<a<<" "<<b<<endl;
	if ( (a == '(') && (b != ')'))
		return false;
	else if ( (a == '[') && (b != ']'))
		return false;
	else if ( (a == '{') && (b != '}'))
		return false;
	return true;
}

void PrintStack(Stack s)
{
	for (int i = 0 ; i < s.n ; i++)
		cout<<s.Storage[i];
	cout<<endl;
}

bool Input (Stack &s, string S)
{
	bool flag = false;
	for (unsigned int i = 0 ; i < S.size() ; i++)
	{
		if (S[i] == '(' || S[i] == '[' || S[i] == '{')
			Push(s,S[i]);
		else if (S[i] == ')' || S[i] == ']' || S[i] == '}')
			{
				flag = true;
				if ( !CheckPair(Pop(s),S[i]) )
					return false;
			}
	}
	if (!flag || IsEmpty(s) == false)
		return false;
	return true;
}



int main()
{
	string S;
	cout<<"Nhap vao van ban can kiem tra:"<<endl;
	getline (cin,S);
	Stack s;
	Init(s);
	Input(s,S);
	//PrintStack(s);
	if (Input(s,S) == true)
		cout<<"Cac dau ngoac hop le"<<endl;
	else
		cout<<"Cac dau ngoac khong hop le"<<endl;
	return 0;
}