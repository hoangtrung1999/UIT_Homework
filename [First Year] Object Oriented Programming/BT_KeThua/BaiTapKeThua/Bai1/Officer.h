#pragma once
#include "Employee.h"
class Officer : public Employee
{
private:
	int Workdays;
public:
	Officer();
	~Officer();
	int Calculate();
	void GetWorkdays();
	void PrintInfo();
};

