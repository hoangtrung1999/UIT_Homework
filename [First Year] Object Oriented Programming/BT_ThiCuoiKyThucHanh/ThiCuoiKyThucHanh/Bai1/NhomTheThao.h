#pragma once
#include "Nhom.h"
class NhomTheThao : public Nhom
{
protected:
	int SoMonTT;
	int SoDanhHieu;
	double TiLeThang;
public:
	NhomTheThao();
	~NhomTheThao();
	void Nhap();
	void Xuat();
	double TinhDiem();
	int LayLoaiNhom();
	void XepLoai();
};

