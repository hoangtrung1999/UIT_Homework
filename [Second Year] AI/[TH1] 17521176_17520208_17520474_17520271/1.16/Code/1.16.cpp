#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void nhapDoThi(vector<vector<int>>& DoThi, fstream& input); // Ham nhap do thi
void tinhSoBac(const vector<vector<int>>& DoThi, vector<int>& BacCacDinh); // Ham tinh so bac cua moi dinh
int DinhBacCaoNhat(const vector<int>& BacCacDinh); // Tra ve dinh co bac lon nhat
void toMau(vector<vector<int>> DoThi, vector<int> BacCacDinh, vector<int>& DinhToMau, int& m); // Moi cong viec to mau dien ra o ham nay
int chonMau(vector<vector<int>> DoThi, vector<int> DinhToMau, int& m, const int& index); // Chon mau de to cho dinh duoc truyen vao (index)
void xuLy(vector<vector<int>>& DoThi, vector<int>& BacCacDinh, int index_max); // Xu ly sau khi to mau xong


int main()
{
	// Mo file test de doc va nhap do thi
	// Khoi tao cac bien can thiet
	fstream input;
	input.open("test.txt", fstream::in);
	int n; input >> n; // So dinh cua do thi
	vector<vector<int>> DoThi(n, vector<int>(n, 0));
	vector<int> BacCacDinh(n, 0);
	vector<int> DinhToMau(n, 0);
	int m = 1; // So mau

	nhapDoThi(DoThi, input);
	input.close();
	tinhSoBac(DoThi, BacCacDinh);
	toMau(DoThi, BacCacDinh, DinhToMau, m);

	cout << "Mau tuong ung voi cac dinh la: " << endl;
	for (int i = 0; i < DinhToMau.size(); ++i)
		cout << "Dinh thu " << i << " co mau: " << DinhToMau[i] << endl;
	cout << "So mau can dung la: " << m << endl;

	system("pause");
	return 0;
}

void nhapDoThi(vector<vector<int>>& DoThi, fstream& input)
{
	// Kiem tra xem file co dang duoc mo hay chua
	if (input.is_open())
	{
		for (int i = 0; i < DoThi.size(); ++i)
		{
			for (int j = 0; j < DoThi[i].size(); ++j)
			{
				input >> DoThi[i][j];
			}
		}
	}
}

void tinhSoBac(const vector<vector<int>>& DoThi, vector<int>& BacCacDinh)
{
	for (int i = 0; i < DoThi.size(); ++i)
	{
		for (int j = 0; j < DoThi[i].size(); ++j)
		{
			if (DoThi[i][j] != 0)
				++BacCacDinh[i];
		}
	}
}

int DinhBacCaoNhat(const vector<int>& BacCacDinh)
{
	int index_max = 0;
	for (int i = 1; i < BacCacDinh.size(); ++i)
	{
		if (BacCacDinh[i] > BacCacDinh[index_max])
			index_max = i;
	}
	return index_max;
}

void toMau(vector<vector<int>> DoThi, vector<int> BacCacDinh, vector<int>& DinhToMau, int& m)
{
	// Moi vong lap chon ra dinh co bac lon nhat de to mau cho dinh do
	// Lap lai den khi het tat ca cac dinh
	int index_max = 0;
	for (int i = 0; i < DoThi.size(); ++i)
	{
		index_max = DinhBacCaoNhat(BacCacDinh);
		DinhToMau[index_max] = chonMau(DoThi, DinhToMau, m, index_max);
		xuLy(DoThi, BacCacDinh, index_max);
	}
}

int chonMau(vector<vector<int>> DoThi, vector<int> DinhToMau, int & m, const int & index)
{
	int color = -1;
	bool ok = true;
	for (color = 1; color <= m; ++color)
	{
		ok = true;
		for (int i = 0; i < DoThi.size(); ++i)
		{
			if (DoThi[index][i] != 0 and DinhToMau[i] == color)
			{
				ok = false;
				break;
			}
		}
		if (ok)
			return color;
	}
	++m;
	return color;
}

void xuLy(vector<vector<int>>& DoThi, vector<int>& BacCacDinh, int index_max)
{
	// Bac cua dinh da to mau se duoc gan = -1
	// Cac dinh ke voi no se giam bac xuong 1
	BacCacDinh[index_max] = -1;
	for (int j = 0; j < DoThi[index_max].size(); ++j)
	{
		if (DoThi[index_max][j] != 0)
		{
			BacCacDinh[j] -= 1;
		}
	}
}
