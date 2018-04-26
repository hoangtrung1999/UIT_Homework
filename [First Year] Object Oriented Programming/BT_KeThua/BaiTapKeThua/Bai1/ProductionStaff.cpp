#include "ProductionStaff.h"



ProductionStaff::ProductionStaff()
{
}


ProductionStaff::~ProductionStaff()
{
}

int ProductionStaff::Calculate()
{
	this->Salary = BasicSalary + Products * 5000;
	return this->Salary;
}

void ProductionStaff::GetInfo()
{
	cout << "Input Basic Salary: ";
	cin >> this->BasicSalary;
	cout << "Input number of products: ";
	cin >> this->Products;
}

void ProductionStaff::PrintInfo()
{
	cout << "Name: " << this->Name << endl;
	cout << "Birthday: " << this->Date << endl;
	cout << "Salary of Production Staff: " << Calculate() << endl;
}
