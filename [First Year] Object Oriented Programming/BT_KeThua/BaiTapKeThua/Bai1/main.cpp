#include <iostream>
#include "Employee.h"
#include "Officer.h"
#include "ProductionStaff.h"
using namespace std;

int main()
{
	Employee* People; 
	Officer employee1;
	ProductionStaff employee2;

	employee1.InputName();
	employee1.InputDate();
	employee1.GetWorkdays();

	employee2.InputName();
	employee2.InputDate();
	employee2.GetInfo();
	
	cout << "Infomation" << endl;
	People = &employee1;
	People->PrintInfo();
	People = &employee2;
	People->PrintInfo();
	return 0;
}