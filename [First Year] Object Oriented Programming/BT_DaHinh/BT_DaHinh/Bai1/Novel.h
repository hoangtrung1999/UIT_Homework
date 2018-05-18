#pragma once
#include <iostream>
#include <string>
#include "Books.h"
using namespace std;

class Novel:public Books
{
private:
	string Type;
public:
	Novel();
	~Novel();
	void InputInfo();
	void PrintInfo();
};

