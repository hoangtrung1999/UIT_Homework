#include <iostream>
#include "EducationalBooks.h"
#include "Novel.h"
#include "Magazines.h"
using namespace std;

int main()
{
	int n;
	cout << "Number of books" << endl;
	cin >> n;
	getchar();
	int choice;

	EducationalBooks* b1 = new EducationalBooks;
	Novel* b2 = new Novel;
	Magazines* b3 = new Magazines;

	Books** ListBooks = new Books*[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Type of books" << endl;
		cout << "1/ Educational Books" << endl;
		cout << "2/ Novels" << endl;
		cout << "3/ Magazines" << endl;
		cin >> choice;
		getchar();
		if (choice == 1)
			ListBooks[i] = b1;
		else if (choice == 2)
			ListBooks[i] = b2;
		else
			ListBooks[i] = b3;
		ListBooks[i]->InputInfo();
	}
	cout << "Infomation" << endl;
	for (int i = 0; i < n; i++)
	{
		ListBooks[i]->PrintInfo();
	}
	getchar();
	return 0;
}