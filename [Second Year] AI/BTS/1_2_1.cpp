#include <iostream>
#include <fstream>
using namespace std;

void SortTime (int Time[], int ID[], int n)
{
	for (int i = n-1; i > 0 ; i--)
		for (int j = 0; j < i ; j++)
			if (Time[j] < Time[i])
			{
				swap(Time[i], Time[j]);
				swap(ID[i], ID[j]);
			}
}

int SelectMachine (int machineWork[], int m)
{
	int min;
	min = machineWork[0];
	int id = 0;
	for (int i = 1 ; i < m ; i++)
		if (machineWork[i] < min)
		{
			min = machineWork[i];
			id = i;
		}
	return id;
}

int main()
{
	int n; // n cong viec
	int m; // m machines
	int ID[50]; //Work ID
	int Time[50]; //Work time
	int tempTime[50];

	int machineWork[50]; // Machine Work Time
	int save[50]; // The work j will be taken
	ifstream input;
	input.open ("input.txt", ios::in);
	input >> n;
	input >> m;
	
	// Initial ID
	for (int i = 0; i < n; i++)
		ID[i] = i;
	// Initial work time
	for (int i = 0; i < n; i++)
		input >> Time[i];
	// Initial machineWork
	for (int i = 0; i < m ; i++)
		machineWork[i] = 0;
	copy(Time,Time+n,tempTime);
	SortTime(Time, ID, n);

	int pivot = 0;
	for (int i = 0; i < n ; i++)
	{
		int t = Time[pivot]; // Get the biggest time
		int id = ID[pivot]; // Get the work's ID
		int machine = SelectMachine(machineWork, m); // Get the machine
		machineWork[machine] += t;
		save[id] = machine;

		pivot++;
	}
	for (int i = 0; i < m ; i++)
	{
		cout<<"Jobs of machine "<<i+1<<" : ";
		for (int j = 0 ; j < n ; j++)
			if (save[j] == i)
				cout<<tempTime[j]<<" ";
		cout<<endl;
	}
	cout<<"Sum of all work time"<<endl;
	for (int i = 0; i < m ; i++)
		cout<<machineWork[i]<<" ";
	return 0;
}