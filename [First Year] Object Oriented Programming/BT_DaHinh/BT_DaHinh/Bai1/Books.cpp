#include "Books.h"

Books::Books()
{

}

void Books::InputInfo()
{
	cout<< "Title: ";
	getline(cin,this->Title);
	cout << "Author: ";
	getline(cin,this->Author);
	cout << "Publication Year: ";
	cin >> this->PulicationYear;
	cout << "Price: ";
	cin >> this->Price;
}


void Books::PrintInfo()
{
	cout << "Title: "<<this->Title<<endl;
	cout << "Author: " << this->Author << endl;
	cout << "Publication Year: "<<this->PulicationYear<<endl;
	cout << "Price: "<<this->Price<<endl;
}

Books::~Books()
{
}
