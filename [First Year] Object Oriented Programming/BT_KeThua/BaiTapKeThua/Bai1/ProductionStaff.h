#pragma once
#include "Employee.h"
class ProductionStaff : public Employee
{
private:
	int Products;
	float BasicSalary;
public:
	ProductionStaff();
	~ProductionStaff();
	int Calculate();
	void GetInfo();
	void PrintInfo();
};

