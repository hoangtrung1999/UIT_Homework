#include <iostream>
#include <string>
using namespace std;
#define Max 100


class Stack
{
private:
	int n;
	double Array[Max];
public:
	void Push(double x);
	double Pop();
};

float Calculate (string s, Stack stack)
{
	for (int i = 0 ; i < s.size() ; i++)
	{
		if ((int)s[i] >= 48)
			stack.Push(s[i] - '0');	
		else
		{
			double x = stack.Pop();
			double y = stack.Pop();
			switch(s[i])
			{
				case '+':
					stack.Push(x+y);
					break;
				case '-':
					stack.Push(x-y);
					break;
				case '%':
					stack.Push(x / y);
					break;
				case '*':
					stack.Push(x*y);
					break;
			}
		}
	}
	return stack.Pop();
}

int main()
{
	string s;
	Stack stack;
	cout<<"Nhap bieu thuc hau to: ";
	getline (cin,s);
	cout<<Calculate(s,stack);
	return 0;
}

void Stack::Push (double x)
{
	Array[n++] = x;
}

double Stack::Pop()
{
	double c = this->Array[--n];
	return c;
}
