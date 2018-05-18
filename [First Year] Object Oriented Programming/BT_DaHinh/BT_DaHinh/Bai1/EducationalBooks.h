#pragma once
#include "Books.h"
#include<string>
class EducationalBooks:public Books
{
private:
	string Subject;
public:
	EducationalBooks();
	~EducationalBooks();
	void InputInfo();
	void PrintInfo();
};

