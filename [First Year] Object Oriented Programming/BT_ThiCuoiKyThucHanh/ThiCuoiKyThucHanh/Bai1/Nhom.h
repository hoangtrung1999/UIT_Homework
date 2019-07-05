#pragma once
#include <iostream>
#include <string>
using namespace std;

class Nhom
{
protected:
	string Ten;
	int SoTV;
	int SoHD;
	int TGHD;
	int LoaiNhom;
	int SoNhomKhongDat;
public:
	Nhom();
	~Nhom();
	int LayGiaTriSoTV();
	string LayTenNhom();
	int LaySoHD();
	int LaySoNhomKhongDat();

	virtual int LayLoaiNhom();
	virtual void Nhap();
	virtual void Xuat();
	virtual double TinhDiem();
	virtual void XepLoai();
};

