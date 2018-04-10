#include "Candidate.h"
#include <iostream>
using namespace std;

Candidate::Candidate()
{
}


Candidate::~Candidate()
{
}

void Candidate::GetInfo()
{
	cout << "Input ID: ";
	ID.GetString();
	cout << "Input name: ";
	Name.GetString();
	cout << "Input birthday" << endl;
	BirthDay.GetDate();
	cout << "Input Math mark: ";
	cin >> this->Math;
	cout << "Input Literature mark: ";
	cin >> this->Literature;
	cout << "Input English mark: ";
	cin >> this->English;
	this->SumMark = this->Math + this->Literature + this->English;
	getchar();
}

void Candidate::PrintInfo()
{
	cout << "*** Infomation ***"<<endl;
	cout << "ID: ";
	ID.PrintString();
	cout << "Name: ";
	Name.PrintString();
	cout << "Birthday" << endl;
	BirthDay.PrintDate();
	cout << "Math mark: ";
	cout<< this->Math <<endl;
	cout << "Literature mark: ";
	cout << this->Literature << endl;
	cout << "English mark: ";
	cout << this->English <<endl;
}
