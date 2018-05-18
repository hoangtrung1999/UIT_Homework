#include "Novel.h"



Novel::Novel()
{
}


Novel::~Novel()
{
}

void Novel::InputInfo()
{
	cout << "Title: ";
	getline(cin, this->Title);
	cout << "Author: ";
	getline(cin, this->Author);
	cout << "Type: ";
	getline(cin, Type);
	cout << "Publication Year: ";
	cin >> this->PulicationYear;
	cout << "Price: ";
	cin >> this->Price;
	getchar();
}

void Novel::PrintInfo()
{
	cout << "\n Novel" << endl;
	cout << "Title: " << this->Title << endl;
	cout << "Author: " << this->Author << endl;
	cout << "Type: " << this->Type << endl;
	cout << "Publication Year: " << this->PulicationYear << endl;
	cout << "Price: " << this->Price << "\n";
}
