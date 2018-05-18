#include "Magazines.h"



Magazines::Magazines()
{
}


Magazines::~Magazines()
{
}

void Magazines::InputInfo()
{	
	cout << "Issue: ";
	cin>>issue;
	Books::InputInfo();
	getchar();
}

void Magazines::PrintInfo()
{
	cout << "\n Magazines" << endl;
	cout << "Issue: " << this->issue << endl;
	Books::PrintInfo();
}
