#pragma once
#include "Books.h"
#include <iostream>
#include <string>
using namespace std;
class Magazines:public Books
{
private:
	int issue;
public:
	Magazines();
	~Magazines();
	void InputInfo();
	void PrintInfo();
};

