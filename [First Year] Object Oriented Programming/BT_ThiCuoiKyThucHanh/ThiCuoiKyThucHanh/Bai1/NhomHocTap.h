#pragma once
#include "Nhom.h"
class NhomHocTap : public Nhom
{
protected:
	int SoMonHoc;
	int SoHB;
public:
	NhomHocTap();
	~NhomHocTap();
	void Nhap();
	void Xuat();
	double TinhDiem();
	int LayLoaiNhom();
	void XepLoai();
};

