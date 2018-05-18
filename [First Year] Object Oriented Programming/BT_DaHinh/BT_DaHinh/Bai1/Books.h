#pragma once
#include <iostream>
#include <string>
using namespace std;
class Books
{
protected:
	int Price;
	int PulicationYear;
	string Author;
	string Title;

public:
	Books();
	virtual void InputInfo();
	virtual void PrintInfo();
	~Books();
};

