/*Heristic implement of postman problem*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int NextDes (int Matrix[100][100],int Path[100], int S, int n); //Tim dinh di ke tiep sau dinh S
int Find (int Matrix[100][100],int Path[100], int S, int n, vector<int> &result); // Tim duong di bat dau tu S
void InputMatrix (int Matrix[100][100], int n, ifstream& input);
void PrintPath (int S, int n, vector<int> result);
void PrintMatrix (int Matrix[100][100], int n);
void PresetPath (int Path[100], int n);
int main ()
{
	int n; // n dinh
	int Matrix[100][100]; // Do thi duoi dang ma tran
	int Path[100]; // Dinh i se di den dinh Path[i]
	vector <int> result;

	ifstream input;
	input.open("Dothi.txt", ios::app);
	input>>n;
	InputMatrix(Matrix, n, input);
	PrintMatrix(Matrix, n);
	for (int i = 0; i < n; i++)
	{
		PresetPath(Path,n);
		Find (Matrix,Path,i,n,result);
		PrintPath(i,n,result);
	}
	return 0;
}

void PresetPath (int Path[100], int n)
{
	for (int i = 0; i < n; i++)
		Path[i] = -1;
}

void PrintMatrix (int Matrix[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout<<Matrix[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void PrintPath(int S, int n, vector<int> result)
{
	cout<<"Path starts from "<<S<<":";
	for (int i = 0; i < n; i++)
		cout<<result[i]<<" ";
	cout<<endl;
}

int Find (int Matrix[100][100],int Path[100], int S, int n, vector<int> &result)
{
	cout<<"Finding Path for "<<S<<endl;
	result.push_back(S);
	int count = 0;
	do
	{
		cout<<"Dinh dang xet :"<<S<<endl;
		int k = NextDes(Matrix,Path,S,n);
		if (k > -1)
		{
			cout<<"Next Destination is "<<k<<endl;
			Path[S] = k;
			S = k;
			result.push_back(S);
			count++;
		}
		else
		{
			S++;
			count++;
		}

	}while (count < n);
	return 0;
}

int NextDes (int Matrix[100][100],int Path[100], int S, int n)
{
	int min;
	bool Check = false;
	for (int i = 0; i < n; i++)
		if (Matrix[S][i] > 0 && Path[i] < 0)
		{
			min = i;
			Check = true;
			break;
		}
	cout<<"First min: "<<min<<endl;
	for (int i = min + 1; i < n; i++)
		if (Matrix[S][i] < Matrix[S][min] && Matrix[S][i] > 0 && Path[i] < 0)
			min = i;
	cout<<"Final min: "<<min<<endl;
	if (Check)
		return min;
	else
		return -1;
}

void InputMatrix (int Matrix[100][100], int n, ifstream& input)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			input>>Matrix[i][j];
}

