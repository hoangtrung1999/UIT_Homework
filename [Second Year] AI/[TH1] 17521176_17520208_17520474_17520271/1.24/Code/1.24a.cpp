#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;

void Input(vector<vector<int>>&, int&);
void degree_count(vector<vector<int>>, vector<int>&);
int highest_vertex(vector<vector<int>>, vector<int>);
void colour_choosing(int, vector<int>&, vector<vector<int>>, vector<int>&);
void del_vertex(int, vector<vector<int>>, vector<int>&);
void Output(vector<int>, int);
void Output(vector<vector<int>>);
void Output(vector<int>);

int main()
{
	int n;
	vector<vector<int>> G;
	Input(G, n);
	Output(G);
	cout << endl;
	vector<int> Colour(n, 0);
	vector<int> Degree(n, 0);
	degree_count(G, Degree);

	for (int i = 0; i < n; ++i)
	{
		int S = highest_vertex(G, Degree);
		colour_choosing(S, Colour, G, Degree);
		del_vertex(S, G, Degree);
	}

	Output(Colour, n);

	return 0;
}

void degree_count(vector<vector<int>> G, vector<int> &Degree)
{
	for (int i = 0; i < G.size(); ++i)
		for (int j = 0; j < G.size(); ++j)
			if (G[i][j])
				++Degree[i];
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

int all_coloured(vector<int> Colour)
{
	for (int i = 0; i < Colour.size(); ++i)
		if (Colour[i])
			return 1;
	return 0;
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

void colour_choosing(int S, vector<int> &Colour, vector<vector<int>> G, vector<int> &Degree)
{

	for (int colour = 1; colour < 5; ++colour)
	{
		bool uncoloured = 1;
		for (int j = 0; j < G.size(); ++j)
		{
			if (G[S][j] && Colour[j] == colour)
			{
				uncoloured = 0;
				break;
			}
		}
		if (uncoloured)
		{
			Colour[S] = colour;
			Degree[S] = -1;
			break;
		}
	}
}

void del_vertex(int S, vector<vector<int>> G, vector<int> &Degree)
{
	for (int i = 0; i < G.size(); ++i)
	{
		if (G[S][i])
			--Degree[i];
	}
}

int highest_vertex(vector<vector<int>> G, vector<int> Degree)
{
	int max = -1, imax = 0;
	for (int i = 0; i < G.size(); ++i)
	{
		if (max < Degree[i])
		{
			max = Degree[i];
			imax = i;
		}
	}
	return imax;
}

void Output(vector<int> Colour, int n)
{
	int max = 0;
	for (int i = 0; i < n; ++i)
		if (Colour[i] > max)
			max = Colour[i];
	for (int i = 0; i < max; ++i)
	{
		cout << "Cac dinh mau " << i + 1 << ": ";
		for (int j = 0; j < Colour.size(); ++j)
			if (Colour[j] == i + 1)
				cout << j << " ";
		cout << endl;
	}
}