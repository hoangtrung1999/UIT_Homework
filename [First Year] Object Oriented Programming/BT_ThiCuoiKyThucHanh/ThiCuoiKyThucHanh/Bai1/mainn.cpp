#include <iostream>
#include "LopHoc.h"
using namespace std;

int main()
{
	LopHoc A3;
	A3.Nhap();
	A3.Xuat();
	A3.NhomDongTVNhat();
	A3.NhomDiemDanhGiaCaoNhat();
	A3.LopVanNgheNhieuHoatDongNhat();
	cout << "Tong so hoat dong cua lop: " << A3.TongHoatDong()<<endl;
	A3.LoaiHoatDongCoNhieuNhomNhat();
	cout << "Danh gia lop: ";
	A3.DanhGiaLop();
	getchar();
	return 0;
}