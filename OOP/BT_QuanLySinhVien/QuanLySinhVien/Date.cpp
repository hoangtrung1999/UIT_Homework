#include "Date.h"
#include <iostream>
using namespace std;

Date::Date()
{
}


Date::~Date()
{
}

void Date::GetDate()
{
	cout << "Input date with format: dd/mm/yyyy: ";
	cin >> this->Day;
	cin.ignore(10, '/');
	cin >> this->Month;
	cin.ignore(10, '/');
	cin >> this->Year;
}

void Date::PrintDate()
{
	cout << "Date: " << this->Day << "/" << this->Month << "/" << this->Year << endl;
}
