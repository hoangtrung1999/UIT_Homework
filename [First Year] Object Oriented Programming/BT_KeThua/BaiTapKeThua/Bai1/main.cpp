#include <iostream>
#include "Employee.h"
#include "Officer.h"
#include "ProductionStaff.h"
using namespace std;

int main()
{
	Employee** People;
	People = new Employee*[2];
	Officer employee1;
	ProductionStaff employee2;

	employee1.InputName();
	employee1.InputDate();
	employee1.GetWorkdays();

	employee2.InputName();
	employee2.InputDate();
	employee2.GetInfo();
	
	cout << "Infomation" << endl;
	People[0] = &employee1;
	People[0]->PrintInfo();
	People[1] = &employee2;
	People[1]->PrintInfo();
	return 0;
}