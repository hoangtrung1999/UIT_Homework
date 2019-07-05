#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

typedef vector<vector<bool>> square_matrix;
struct vertex
{
	int degree = 0;
	int x;
	int y;
};

//Xet dinh ke
bool checkIncidentVertex(vertex a, vertex b)
{
	return a.x == b.x || a.x == b.y || a.y == b.x || a.y == b.y;
}

void inputMatrix(square_matrix &m)
{
	ifstream file_input;
	file_input.open("119input.txt");
	if (!file_input)
	{
		cout << "Cant open file";
		return;
	}

	int size, temp;
	file_input >> size;
	m.resize(size);

	for (int row = 0; row < size; row++)
	{
		m[row].resize(size);
		for (int col = 0; col < size; col++)
		{
			file_input >> temp;
			m[row][col] = temp;
		}
	}

	file_input.close();
}

vector<vertex> processRawData(square_matrix m)
{
	vector<vertex> map;
	vertex temp;

	//Cac cap dinh ke nhau la 1 tran can xep lich
	for (int i = 0; i < m.size(); i++)
		//a[i][j] va a[j][i] tuong duong nhau, xet 1 nua ma tran theo duong cheo
		for (int j = i + 1; j < m.size(); j++)
			if (m[i][j])
			{
				temp.x = i;
				temp.y = j;
				map.push_back(temp);
			}

	//Tinh bac cho dinh
	for (int i = 0; i < map.size(); i++)
		for (int j = 0; j < map.size(); j++)
			if (i != j && checkIncidentVertex(map[i], map[j]))
				map[i].degree++;

	return map;
}

bool compare(vertex a, vertex b)
{
	return a.degree > b.degree;
}

void sortVertex(vector<vertex> &map)
{
	sort(map.begin(), map.end(), compare);
}

vector<int> chooseColor(square_matrix m, vector<vertex> map)
{
	vector<int> color_table(map.size(), 0);
	vector<vertex> same_colored;

	for (int i = 0, color = 1; i < map.size(); i++)
		//Xet dinh chua duoc to mau
		if (!color_table[i])
		{
			color_table[i] = color;
			same_colored.push_back(map[i]);

			//Tim cac dinh co the to mau giong voi i
			for (int j = i + 1; j < map.size(); j++)
			{
				if (!color_table[j])
				{
					bool colorable = true;

					//Kiem tra ke voi cac dinh da duoc to mau
					for (int k = 0; k < same_colored.size(); k++)
						if (checkIncidentVertex(map[j], same_colored[k]))
						{
							colorable = false;
							break;
						}

					//Khong ke la to mau duoc
					if (colorable)
					{
						color_table[j] = color;
						//Dinh tiep theo phai khong ke voi dinh vua duoc to
						same_colored.push_back(map[j]);
					}
				}
			}

			//Doi mau to
			color++;
			same_colored.clear();
		}

	return color_table;
}

string outputCountry(int country)
{
	string a;

	switch(country)
	{
	case 0: a = "Duc";
		break;
	case 1: a = "My";
		break;
	case 2: a = "Ao";
		break;
	case 3: a = "Viet Nam";
		break;
	case 4: a = "Y";
		break;
	case 5: a = "Singapore";
		break;
	case 6: a = "Trung Quoc";
		break;
	case 7: a = "Nga";
		break;
	}

	return a;
}

int main()
{
	//Nhap du lieu goc
	square_matrix m;
	inputMatrix(m);

	//Xu ly thanh tap cac dinh can to
	vector<vertex> map = processRawData(m);
	sortVertex(map);
	vector<int> color_table = chooseColor(m, map);

	for (int day = 1, count = 0; count < color_table.size(); day++)
	{
		cout << "Ngay " << day << endl;

		for (int i = 0; i < map.size(); i++)
			if (color_table[i] == day)
			{
				cout << outputCountry(map[i].x) << " danh " << outputCountry(map[i].y) << endl;
				count++;
			}
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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
