#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct CongViec
{
	int M1;
	int M2;
};

void nhapCongViec(vector<CongViec>& D, int& n);
void chiaNhomCongViec(vector<CongViec>& D, int& chiaNhomCongViec);
void sapXepCongViec(vector<CongViec>& D, int& chiaNhomCongViec);
int tinhThoiGian(vector<CongViec> D);

int main()
{
	int n;
	vector<CongViec> D;
	int nhomCongViec;
	nhapCongViec(D, n);
	chiaNhomCongViec(D, nhomCongViec);
	sapXepCongViec(D, nhomCongViec);
	int time = tinhThoiGian(D);
	cout << "Tong thoi gian can thiet: " << time << endl;
	system("pause");
	return 0;
}

void nhapCongViec(vector<CongViec>& D, int& n)
{
	fstream input;
	input.open("test.txt", fstream::in);
	input >> n;
	D.resize(n);
	for (int i = 0; i < D.size(); ++i)
		input >> D[i].M1 >> D[i].M2;
	input.close();
}

void chiaNhomCongViec(vector<CongViec>& D, int& chiaNhomCongViec)
{
	// Chia cong viec thanh 2 nhom
	// Nhom 1: Cac cong viec D[i] sao cho D[i].M1 <= D[i].M2
	// Nhom 2: Cac cong viec D[i] sao cho D[i].M1 > D[i].M2
	for (int i = 0; i < D.size(); ++i)
		for (int j = D.size() - 1; j > i; --j)
		{
			if (D[j].M1 < D[j].M2)
				if (D[j - 1].M1 > D[j - 1].M2)
				{
					swap(D[j], D[j - 1]);
					chiaNhomCongViec = j - 1;
				}
		}
}

void sapXepCongViec(vector<CongViec>& D, int & chiaNhomCongViec)
{
	// Sap xe Nhom 1 sao cho D[i + 1].M1 > D[i].M1
	for (int i = chiaNhomCongViec; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
			if (D[j].M1 > D[j + 1].M1)
				swap(D[j], D[j + 1]);
	}
	// Sap xep Nhom 2 sao cho D[i].M2 > D[i + 1].M2
	for (int i = D.size() - 1; i >= 0; --i)
	{ 
		for (int j = chiaNhomCongViec + 1; j < i; ++j)
			if (D[j].M2 < D[j + 1].M2)
				swap(D[j], D[j + 1]);
	}
}

int tinhThoiGian(vector<CongViec> D)
{
	int time = D[0].M1;
	int sum = 0;
	int j = 0;
	for (int i = 1; i < D.size(); ++i)
	{
		// Neu D[i].M1 be hon D[i].M2, cong gia tri cua D[i + 1].M1 sang cho D[i].M1
		// den khi D[i].M1 = D[i].M2
		for(sum = D[i].M1, j = i; D[i - 1].M2 > sum and j + 1 != D.size(); ++j)
		{
			sum += D[j + 1].M1;

			if (sum >= D[i - 1].M2)
			{
				D[j + 1].M1 = sum - D[i - 1].M2;
				D[i].M1 = D[i - 1].M2;
			}
			else D[j + 1].M1 = 0;
		}
		if (D[i].M1 == 0)
			time += D[i - 1].M2;
		else time += D[i].M1;
	}
	time += D[D.size() - 1].M2;
	return time;
}
