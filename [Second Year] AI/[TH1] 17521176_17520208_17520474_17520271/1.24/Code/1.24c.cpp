#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;

void Input(vector<vector<int>>&, int&);
void Output(vector<int>, int);
void Output(vector<vector<int>>);
void Output(vector<int>);
bool all_coloured(vector<int>);
bool colour_check(vector<vector<int>>, vector<int>, int, int);
void degree_count(vector<vector<int>>, vector<int>&);
void sort(vector<int>&, vector<int>&);

int main()
{
	int n;
	vector<vector<int>> G;
	Input(G, n);
	Output(G);
	vector<int> Colour(n, 0);
	int colour = 1;
	cout << endl;
	vector<int> Degree(n, 0);
	degree_count(G, Degree);
	vector<int> loc;
	for (int i = 0; i < n; ++i)
		loc.push_back(i);
	sort(Degree, loc);
	Colour[loc[0]] = 1;
	for (; ; ++colour)
	{
		for (int i = 1; i < n; ++i)
			if (!Colour[loc[i]] && colour_check(G, Colour, loc[i], colour))
				Colour[loc[i]] = colour;
		if (all_coloured(Colour))
			break;
	}
	Output(Colour, colour);

	return 0;
}

void sort(vector<int> &Degree, vector<int> &loc)
{
	for (int i = 0; i < loc.size(); ++i)
	{
		for (int j = 1; j < loc.size() - i; ++j)
			if (Degree[j - 1] < Degree[j])
			{
				swap(Degree[j - 1], Degree[j]);
				swap(loc[j - 1], loc[j]);
			}
	}
}

void degree_count(vector<vector<int>> G, vector<int> &Degree)
{
	for (int i = 0; i < G.size(); ++i)
		for (int j = 0; j < G.size(); ++j)
			if (G[i][j])
				++Degree[i];
}

bool colour_check(vector<vector<int>> G, vector<int> Colour, int S, int colour)
{
	for (int i = 0; i < G.size(); ++i)
	{
		if (G[S][i] && Colour[i] == colour)
			return 0;
	}
	return 1;
}

bool all_coloured(vector<int> Colour)
{
	for (int i = 0; i < Colour.size(); ++i)
		if (!Colour[i])
			return 0;
	return 1;
}

void Input(vector<vector<int>> &G, int &n)
{
	ifstream input;
	input.open("input.txt", ios::app);
	input >> n;
	for (int i = 0; i < n; ++i)
	{
		vector<int> temp;
		for (int j = 0; j < n; ++j)
		{
			int a;
			input >> a;
			temp.push_back(a);
		}
		G.push_back(temp);
	}
	input.close();
}

void Output(vector<vector<int>> G)
{
	for (int i = 0; i < G.size(); ++i)
	{
		for (int j = 0; j < G.size(); ++j)
			cout << G[i][j] << " ";
		cout << endl;
	}
}

void Output(vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void Output(vector<int> Colour, int colour)
{
	for (int i = 0; i < colour; ++i)
	{
		cout << "Cac dinh mau " << i + 1 << ": ";
		for (int j = 0; j < Colour.size(); ++j)
			if (Colour[j] == i + 1)
				cout << j << " ";
		cout << endl;
	}
}