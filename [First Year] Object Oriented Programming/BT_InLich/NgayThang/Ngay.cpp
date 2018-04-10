#include "Ngay.h"
#include <iostream>
using namespace std;


Ngay::Ngay()
{
}


Ngay::~Ngay()
{
}

void Ngay::NhapNgay()
{
	cout << "Nhap vao ngay: ";
	cin >> ngay;
	cout << "Nhap vao thang: ";
	cin >> thang;
	cout << "Nhap vao nam: ";
	cin >> nam;
}
void Ngay::XuatNgay()
{
	cout << "Ngay: " << ngay << "/" << thang << "/" << nam<<endl;
}

void Ngay::NgayTiepTheo()
{
	if (ngay < 28)
		 ngay += 1;
	else
	{
		switch (thang)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (ngay < 31)
				ngay += 1;
			else
			{
				ngay = 1;
				if (thang == 12)
				{
					thang = 1;
					nam += 1;
				}
				else
					thang += 1;
			}
			break;
		case 4: case 6: case 9: case 11:
			if (ngay < 30)
				ngay += 1;
			else
			{
				ngay = 1;
				thang += 1;
			}
			break;
		case 2:
			if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0)
				ngay += 1;
			else
			{
				ngay = 1;
				thang += 1;
			}
			break;
		}
	}
}

void Ngay::MaxDay()
{
	switch (thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		maxDay = 31;
		break;
	case 4: case 6: case 9: case 11:
		maxDay = 30;
		break;
	case 2:
		if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0)
		{
			maxDay = 29;
			break;
		}
		maxDay = 28;
		break;
	}
}

void Ngay::InLich()
{
	MaxDay();
	cout << "Sun" << "\t" << "Mon" << "\t" << "Tue" << "\t" << "Wed" << "\t" << "Thu" << "\t" << "Fri" << "\t" << "Sat" << endl;
	if (thang < 3)
	{
		thang += 12;
		nam -= 1;
	}
	int thu = (1 + 2 * thang + (3 * (thang + 1)) / 5 + nam + (nam / 4)) % 7 + 1;
	int ngaytrongthang = 1;
	for (int i = 0; i < thu-1; i++)
		cout << "\t";
	for (int i = 0; i < 7 - thu  + 1; i++)
	{
		cout << ngaytrongthang << "\t";
		ngaytrongthang++;
	}
	cout << endl;
	int jumpWeek = 0;
	while (ngaytrongthang <= maxDay)
	{
		if (jumpWeek == 6)
		{
			cout << ngaytrongthang <<endl;
			jumpWeek = 0;
			ngaytrongthang++;
		}
		else
		{
			cout << ngaytrongthang << "\t";
			ngaytrongthang++;
			jumpWeek++;
		}
	}
}
