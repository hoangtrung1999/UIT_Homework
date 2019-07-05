#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct work
{
	int desc;
	int time;
};

void inputFile(int &number_work, int &number_machine, vector<work> &list_work)
{
	ifstream file_input;
	file_input.open("110input.txt");
	if (!file_input)
	{
		cout << "Cant open file";
		return;
	}

	file_input >> number_work >> number_machine;
	list_work.resize(number_work);

	work temp;
	for (int i = 0; i < number_work; i++)
	{
		temp.desc = i;
		file_input >> temp.time;
		list_work[i] = temp;
	}

	file_input.close();
}

bool compareWork(work a, work b)
{
	return a.time > b.time;
}

void sortWorkList(vector<work> &list_work)
{
	sort(list_work.begin(), list_work.end(), compareWork);
}

int findMinLoc(vector<int> machine)
{
	int minLoc = 0;
	for (int i = 1; i < machine.size(); i++)
	{
		if (!machine[minLoc])
			return minLoc;
		if (machine[minLoc] > machine[i])
			minLoc = i;
	}
	return minLoc;
}

void assignWork(vector<work> list_work, vector<int> &machine, vector<int> &assign)
{
	sortWorkList(list_work);
	for (int i = 0; i < list_work.size(); i++)
	{
		int minLoc = findMinLoc(machine);
		machine[minLoc] += list_work[i].time;
		assign[list_work[i].desc] = minLoc;
	}
}

int main()
{
	int n, m;
	vector<work> list_work;
	inputFile(n, m, list_work);

	vector<int> machine(m, 0);
	vector<int> assign(n);

	assignWork(list_work, machine, assign);

	for (int i = 0; i < m; i++)
	{
		cout << "May " << i + 1 << " lam tong cong " << machine[i] << endl;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "Cong viec thu " << i + 1 << " do may " << assign[i] + 1 << " lam" << endl;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
