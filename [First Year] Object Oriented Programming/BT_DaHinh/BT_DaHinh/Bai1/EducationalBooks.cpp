#include "EducationalBooks.h"

EducationalBooks::EducationalBooks()
{
}


EducationalBooks::~EducationalBooks()
{
}

void EducationalBooks::InputInfo()
{
	cout << "Title: ";
	getline(cin, this->Title);
	cout << "Author: ";
	getline(cin, this->Author);
	cout << "Subject: ";
	getline(cin, Subject);
	cout << "Publication Year: ";
	cin >> this->PulicationYear;
	cout << "Price: ";
	cin >> this->Price;
	getchar();
}

void EducationalBooks::PrintInfo()
{
	cout << "\n Educational Book" << endl;
	cout << "Title: " << this->Title << endl;
	cout << "Author: " << this->Author << endl;
	cout << "Subject: " << this->Subject << endl;
	cout << "Publication Year: " << this->PulicationYear << endl;
	cout << "Price: " << this->Price <<"\n";
}

