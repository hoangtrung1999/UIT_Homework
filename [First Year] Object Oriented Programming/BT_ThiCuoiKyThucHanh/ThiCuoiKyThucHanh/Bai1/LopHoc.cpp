#include "LopHoc.h"

int SoNhomHocTap = 0;
int SoNhomVanNghe = 0;
int SoNhomTheThao = 0;
LopHoc::LopHoc()
{
}


LopHoc::~LopHoc()
{
}

void LopHoc::Nhap()
{
	cout << "Nhap vao so luong sinh vien: ";
	cin >> this->SoSV;
	cout << "Nhap vao so luong nhom: ";
	cin >> this->SoNhom;
	for (int i = 0; i < this->SoNhom; i++)
	{
		int Choice;
		cout << "Chon loai nhom can nhap"<<endl;
		cout << "1/Nhom Hoc Tap" << endl;
		cout << "2/Nhom Van Nghe" << endl;
		cout << "3/Nhom The Thao" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			DSNhom[i] = new NhomHocTap;
			SoNhomHocTap++;
			break;
		case 2:
			DSNhom[i] = new NhomVanNghe;
			SoNhomTheThao++;
			break;
		case 3:
			DSNhom[i] = new NhomTheThao;
			SoNhomVanNghe++;
			break;
		}
		DSNhom[i]->LayLoaiNhom();
		DSNhom[i]->Nhap();
	}
}

void LopHoc::Xuat()
{
	for (int i = 0; i < this->SoNhom; i++)
	{
		DSNhom[i]->Xuat();
		cout << "Xep loai: ";
		DSNhom[i]->XepLoai();
	}

}

void LopHoc::DanhGia()
{
}

void LopHoc::NhomDongTVNhat()
{
	string Name;
	int Max = DSNhom[0]->LayGiaTriSoTV();
	for (int i = 1; i < this->SoNhom; i++)
		if (DSNhom[i]->LayGiaTriSoTV() > Max)
		{
			Max = DSNhom[i]->LayGiaTriSoTV();
			Name = DSNhom[i]->LayTenNhom();
		}

	cout << "Nhom co dong thanh vien nhat: " << Name << endl;
}

void LopHoc::NhomDiemDanhGiaCaoNhat()
{
	string Name;
	int Max = DSNhom[0]->TinhDiem();
	for (int i = 1; i < this->SoNhom; i++)
		if (DSNhom[i]->TinhDiem() > Max)
		{
			Max = DSNhom[i]->TinhDiem();
			Name = DSNhom[i]->LayTenNhom();
		}
	cout << "Nhom co diem danh gia cap nhat: " << Name << endl;
}

void LopHoc::LopVanNgheNhieuHoatDongNhat()
{
	string LopVanNghe;
	int MaxHoatDong = DSNhom[0]->LaySoHD();
	for (int i = 1; i < this->SoNhom; i++)
	{
		if (DSNhom[i]->LayLoaiNhom() == 2 && DSNhom[i]->LaySoHD() > MaxHoatDong)
		{
			MaxHoatDong = DSNhom[i]->LaySoHD();
			LopVanNghe = DSNhom[i]->LayTenNhom();
		}
	}
	cout << "Lop van nghe co nhieu hoat dong nhat la: " << LopVanNghe << endl;
}

int LopHoc::TongHoatDong()
{
	int count = 0;
	for (int i = 0; i < SoNhom; i++)
		count += DSNhom[i]->LaySoHD();
	return count;
}

void LopHoc::LoaiHoatDongCoNhieuNhomNhat()
{
	if (SoNhomHocTap >= SoNhomTheThao && SoNhomHocTap >= SoNhomVanNghe)
		cout << "Co nhieu nhom hoc tap nhat trong 3 loai hoat dong." << endl;
	else if (SoNhomTheThao >= SoNhomHocTap && SoNhomTheThao >= SoNhomVanNghe)
		cout << "Co nhieu nhom the thao nhat trong 3 loai hoat dong." << endl;
	else if (SoNhomVanNghe >= SoNhomHocTap && SoNhomVanNghe >= SoNhomTheThao)
		cout << "Co nhieu nhom van nghe nhat trong 3 loai hoat dong" << endl;
}

void LopHoc::DanhGiaLop() // Khong kip thoi gian nen thieu dieu kien
{
	if (SoNhomHocTap >= 1 && SoNhomTheThao >= 1 && SoNhomVanNghe >= 1)
	{
		for (int i = 0; i < SoNhom; i++)
		{
			if (DSNhom[i]->TinhDiem() < 80)
			{
				cout << "Khong Tot" << endl;
				return;
			}
		}
		double Count = 0;
		for (int i = 0; i < SoNhom; i++)
		{
			Count += DSNhom[i]->LaySoNhomKhongDat();
		}
		cout << Count / SoNhom << endl;
		if (Count / SoNhom > 0.2)
		{
			cout << "Khong Tot";
			return;
		}
		cout << "Tot" << endl;
	}
}
