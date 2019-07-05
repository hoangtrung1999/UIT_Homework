#include "Nhom.h"



Nhom::Nhom()
{
}


Nhom::~Nhom()
{
}

int Nhom::LayGiaTriSoTV()
{
	return SoTV;
}

string Nhom::LayTenNhom()
{
	return Ten;
}

int Nhom::LaySoHD()
{
	return SoHD;
}

int Nhom::LaySoNhomKhongDat()
{
	return SoNhomKhongDat;
}

int Nhom::LayLoaiNhom()
{
	return LoaiNhom;
}

void Nhom::Nhap()
{
	cout << "Nhap ten nhom: ";
	getline(cin, this->Ten);
	cout << "Nhap so luong thanh vien: ";
	cin >> this->SoTV;
	cout << "Nhap so luong cac hoat dong: ";
	cin >> this->SoHD;
	cout << "Nhap thoi gian hoat dong: ";
	cin >> this->TGHD;
}

void Nhom::Xuat()
{
	cout << "Ten Nhom: " << this->Ten<<endl;
	cout << "So luong thanh vien: " << this->SoTV << endl;
	cout << "So luong cac hoat dong: " << this->SoHD << endl;
	cout << "Thoi gian hoat dong: " << this->TGHD << endl;
}

double Nhom::TinhDiem()
{
	return 1;
}

void Nhom::XepLoai()
{
}
