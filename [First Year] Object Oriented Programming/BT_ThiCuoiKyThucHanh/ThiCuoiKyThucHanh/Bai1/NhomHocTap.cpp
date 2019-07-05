#include "NhomHocTap.h"



NhomHocTap::NhomHocTap()
{
}


NhomHocTap::~NhomHocTap()
{
}

void NhomHocTap::Nhap()
{
	Nhom::Nhap();
	cout << "Nhap so mon: ";
	cin >> this->SoMonHoc;
	cout << "Nhap so hoc bong: ";
	cin >> this->SoHB;
	getchar();
}

void NhomHocTap::Xuat()
{
	cout <<endl<<"Thong tin nhom hoc tap"<<endl;
	Nhom::Xuat();
	cout << "So mon hoc: " << this->SoMonHoc<<endl;
	cout << "So hoc bong: " << this->SoHB<<endl;
}

double NhomHocTap::TinhDiem()
{
	return ((double)SoHD / TGHD) * 30 + ((double)SoMonHoc / 10) * 50 + ((double)SoHB / SoTV) * 20;
}

int NhomHocTap::LayLoaiNhom()
{
	return 1;
}

void NhomHocTap::XepLoai()
{
	if (this->TinhDiem() >= 80 && (double)SoHB / SoTV >= 0.5)
		cout << "Dat" << endl;
	else
	{
		this->SoNhomKhongDat++;
		cout << "Khong dat" << endl;
	}
}
