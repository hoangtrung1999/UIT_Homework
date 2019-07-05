#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

void PrintVector (vector<int> A);
void InputFromFile (int &n, int DT[100][100], ifstream &input);
int FindLowest (vector<int> distance, vector<int> checkPos, int n);
void UpdateDistance(int n, int min, int DT[][100], vector<int> checkPos, vector<int> &distance, vector<int> &prev);
int main()
{
	int n;
	ifstream input;
	input.open("Dothi.txt", ios::app);
	int DT[100][100];

	InputFromFile(n, DT, input);

	vector<int> checkPos (n,0); // 1 = checked
	vector<int> distance (n,999); // Distance from startPos to vertex ith
	vector<int> prev (n,999);


	int startPos;
	int endPos;

	cout<<"Input startPos: ";
	cin>>startPos;
	cout<<"Input endPos: ";
	cin>>endPos;

	distance[startPos] = 0;
	prev[startPos] = startPos;

	cout<<"Start searching"<<endl;
	for (int i = 0; i < n; i++)
	{
		int min = FindLowest(distance,checkPos,n);
		if (min == endPos || min == -1)
			break;
		checkPos[min] = 1;
		UpdateDistance(n,min,DT,checkPos,distance,prev);
	}

	if (prev[endPos] == 999)
		cout<<"Can't find path"<<endl;
	else
	{
		int k = endPos;
		vector<int> Path;
		do
		{
			Path.push_back(k);
			k = prev[k];
		}while (k != startPos);
		Path.push_back(startPos);
		int Path_size = Path.size();
		reverse(Path.begin(), Path.end());
		for (int i = 0; i < Path_size; i++)
			cout<<Path[i]<<" ";
	}
	return 0;
}

void UpdateDistance(int n,int min, int DT[][100], vector<int> checkPos, vector<int> &distance, vector<int> &prev)
{
	for (int k = 0; k < n; k++)
		if (DT[min][k] > 0 && checkPos[k] == 0)
		{
			if (distance[k] > distance[min] + DT[min][k])
			{
				distance[k] = distance[min] + DT[min][k];
				prev[k] = min;	
			}
			else
				distance[k] = distance[k];
		}
}

int FindLowest(vector<int> distance, vector<int> checkPos, int n)
{
	int min = -1;
	int j = 0;
	for (; j < n; j++)
		if (checkPos[j] == 0)
		{
			min = j;
			break;
		}

	for (; j < n; j++)
		if (distance[j] < distance[min] && checkPos[j] == 0)
			min = j;
	return min;
}

void InputFromFile (int &n, int DT[100][100], ifstream &input)
{
	input>>n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			input>>DT[i][j];
}

void PrintVector (vector<int> A)
{
	for (int i = 0; i < A.size(); i++)
		cout<<A[i]<<" ";
	cout<<endl;
}