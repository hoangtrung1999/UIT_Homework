#include "Employee.h"



Employee::Employee()
{
}


Employee::~Employee()
{
}

int Employee::Calculate()
{
	return 0;
}

void Employee::PrintInfo()
{
}

void Employee::InputName()
{
	cout << "Input Name: ";
	getline(cin, this->Name);
}

void Employee::InputDate()
{
	cout << "Input Birthday: ";
	getline(cin, this->Date);
}


