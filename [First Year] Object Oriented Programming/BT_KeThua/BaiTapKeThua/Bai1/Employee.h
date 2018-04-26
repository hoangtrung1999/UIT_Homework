#pragma once
#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
	string Name;
	string Date;
	float Salary;
public:
	Employee();
	~Employee();
	virtual int Calculate();
	virtual void PrintInfo();
	void InputName();
	void InputDate();
};

