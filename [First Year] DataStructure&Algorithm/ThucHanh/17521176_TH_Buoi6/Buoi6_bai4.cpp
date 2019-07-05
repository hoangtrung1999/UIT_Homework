#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream File;
	File.open("Database.txt");
	File.close();
	return 0;
}