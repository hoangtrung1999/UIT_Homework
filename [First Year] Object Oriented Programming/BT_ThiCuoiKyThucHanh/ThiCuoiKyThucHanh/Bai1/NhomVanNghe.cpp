#include "NhomVanNghe.h"



NhomVanNghe::NhomVanNghe()
{
}


NhomVanNghe::~NhomVanNghe()
{
}

void NhomVanNghe::Nhap()
{
	Nhom::Nhap();
	cout << "Nhap so the loai van nghe: ";
	cin >> this->SoTheLoai;
	cout << "Nhap vao so giai thuong: ";
	cin >> this->SoGiaiThuong;
	getchar();
}

void NhomVanNghe::Xuat()
{
	cout << endl << "Thong tin nhom van nghe" << endl;
	Nhom::Xuat();
	cout << "So the loai van nghe: " << this->SoTheLoai << endl;
	cout << "So giai thuong: " << this->SoGiaiThuong << endl;
}

double NhomVanNghe::TinhDiem()
{
	return ((double)SoHD / TGHD) * 30 + ((double)SoTheLoai / 20) * 40 + ((SoGiaiThuong * 3) / (double)TGHD) * 30;
}

int NhomVanNghe::LayLoaiNhom()
{
	return 2;
}

void NhomVanNghe::XepLoai()
{
	if (this->TinhDiem() >= 80 && SoGiaiThuong >= SoHD)
		cout << "Dat" << endl;
	else
	{
		this->SoNhomKhongDat++;
		cout << "Khong dat" << endl;
	}
}
