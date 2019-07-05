#pragma once
#include "NhomHocTap.h"
#include "NhomTheThao.h"
#include "NhomVanNghe.h"
#include "Nhom.h"
#define SoNhomToiDa 100
class LopHoc
{
protected:
	int SoSV;
	int SoNhom;
	Nhom* DSNhom[SoNhomToiDa];
public:
	LopHoc();
	~LopHoc();
	void Nhap();
	void Xuat();
	void DanhGia();
	void NhomDongTVNhat();
	void NhomDiemDanhGiaCaoNhat();
	void LopVanNgheNhieuHoatDongNhat();
	int TongHoatDong();
	void LoaiHoatDongCoNhieuNhomNhat();
	void DanhGiaLop();
};

