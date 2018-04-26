#include "Officer.h"



Officer::Officer()
{
}


Officer::~Officer()
{
}

int Officer::Calculate()
{
	this->Salary = Workdays * 100000;
	return this->Salary;
}

void Officer::GetWorkdays()
{
	cout << "Input WorkDays: ";
	cin >> this->Workdays;
	getchar();
}

void Officer::PrintInfo()
{
	cout << "Name: " << this->Name << endl;
	cout << "Birthday: " << this->Date << endl;
	cout << "Salary of Officer is: "<<Calculate()<<endl;
}
