#include <iostream>
#include "MyString.h"
using namespace std;

MyString::MyString()
{
	this->size = 0;
}


MyString::~MyString()
{
}

void MyString::GetString()
{
	fflush(stdin);
	char c;
	do
	{
		if (this->size > this->Limit)
		{
			cout << "Out of buffer" << endl;
			break;
		}
		c = getchar();
		this->buffer[this->size] = c;
		this->size++;
	} while (c != '\n');
	
}

void MyString::PrintString()
{
	for (int i = 0; i < this->size; i++)
		cout << this->buffer[i];
}
