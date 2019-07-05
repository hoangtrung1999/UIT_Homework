#include <iostream>
#include <fstream>

using namespace std;

void printMatrix (int DT[100][100], int n);
void CalculateDeg (int DT[100][100], int Deg[100], int n);
int chooseColor (int DT[100][100], int Colors[100], int n, int vertex, int &numColors);
int  chooseVertex(int Deg[100], int n);
void DownDeg (int Deg[100], int DT[100][100], int n, int vertex);
void printResult (int Colors[100], int n, int numColors);
void printDeg (int Deg[100], int n);

int main()
{
	ifstream input;
	input.open("1_23_input.txt", ios::app);

	if (input.is_open())
	{
		int n; // n dinh
		int numColors; // so mau
		int DT[100][100]; // ma tran bieu dien do thi
		int Deg[100]; // so bac cua dinh
		int Colors[100]; // Đỉnh thứ i được tô màu Colors[i]

		input>>n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				input >> DT[i][j];		
	
		input.close();

		CalculateDeg(DT,Deg,n);
/*
		for (int i = 0; i < n; i++)
			cout<<Deg[i]<<" ";
*/

		numColors = 1;
		int vertex = 0;
		int col = 0;
		for (int i = 0; i < n; i++)
		{
			vertex = chooseVertex (Deg,n);
			col    = chooseColor (DT,Colors,n, vertex, numColors);
			Colors[vertex] = col;
			DownDeg(Deg,DT,n,vertex);
		}
		printResult(Colors,n,numColors);

	}
	else
		cout<<"Can't open input file!!!";

	return 0;
}

void printDeg (int Deg[100], int n)
{
	for (int i = 0; i < n; i++)
		cout<<Deg[i]<<" ";
	cout<<endl;
}

void printResult (int Colors[100], int n, int numColors)
{
	for (int j = 1; j <= numColors; j++)
	{
		cout<<"Mau thu "<<j<<" co cac dinh: ";
		for (int i = 0; i < n; i++)
		{
			if (Colors[i] == j)
				{
					switch(i)
					{
						case 0:
							cout<<"AB ";
							break;
						case 1:
							cout<<"AC ";
							break;
						case 2:
							cout<<"AD ";
							break;
						case 3:
							cout<<"AE";
							break;
						case 4:
							cout<<"BA ";
							break;
						case 5:
							cout<<"BC ";
							break;
						case 6:
							cout<<"BD ";
							break;
						case 7:
							cout<<"BE ";
							break;
						case 8:
							cout<<"CA ";
							break;
						case 9:
							cout<<"CB ";
							break;
						case 10:
							cout<<"CD ";
							break;
						case 11:
							cout<<"CE ";
							break;
					}
				}
		}
		cout<<endl;
	}
}

int chooseColor (int DT[100][100], int Colors[100], int n, int vertex, int &numColors)
{
	bool check = true;
	int color = 0;
	for (color = 1; color <= numColors; color++)
	{
		check = true;
		for (int i = 0; i < n; i++)
		{
			if (DT[vertex][i] != 0 && Colors[i] == color)
			{
				check = false;
				break;	
			}
		}
		if (check)
			return color;
	}
	++numColors;
	return color;
}

void CalculateDeg (int DT[100][100], int Deg[100], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (DT[i][j] == 1)
				Deg[i] += 1;
}

void DownDeg (int Deg[100], int DT[100][100], int n, int vertex)
{
	Deg[vertex] = -1;
	for (int i = 0; i < n; i++)
		if(DT[vertex][i] != 0)
			Deg[i] -= 1;
}

int chooseVertex(int Deg[100], int n)
{
	int id_max = 0;
	for (int i = 1; i < n; i++)
		if (Deg[i] > Deg[id_max])
			id_max = i;
	return id_max;
}

void printMatrix (int DT[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout<<DT[i][j]<<" ";
		cout<<endl;
	}
}