#pragma once
#include "Nhom.h"
class NhomVanNghe : public Nhom
{
protected:
	int SoTheLoai;
	int SoGiaiThuong;
public:
	NhomVanNghe();
	~NhomVanNghe();
	void Nhap();
	void Xuat();
	double TinhDiem();
	int LayLoaiNhom();
	void XepLoai();
};

