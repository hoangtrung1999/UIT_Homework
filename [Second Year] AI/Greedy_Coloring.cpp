#include <iostream>
#include <fstream>

using namespace std;

void InputMatrix (int DT[100][100], int& n, ifstream& input);
void CalculateDeg (int DT[100][100], int Deg[100], int n);


int main()
{
	ifstream input;
	input.open("ToMau_input.txt", ios::app);

	if (input.is_open())
	{
		int n;
		int DT[100][100];
		int Deg[100];

		input >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				input >> DT[i][j];


	}
	else
		cout<<"Failed to open file."<<endl;

	return 0;
}