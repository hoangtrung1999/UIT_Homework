#include "NhomTheThao.h"



NhomTheThao::NhomTheThao()
{
}


NhomTheThao::~NhomTheThao()
{
}

void NhomTheThao::Nhap()
{
	Nhom::Nhap();
	cout << "Nhap so mon the thao: ";
	cin >> this->SoMonTT;
	cout << "Nhap vao so danh hieu: ";
	cin >> this->SoDanhHieu;
	cout << "Nhap vao ti le thang: ";
	cin >> this->TiLeThang;
}

void NhomTheThao::Xuat()
{
	getchar();
	cout << endl << "Thong tin nhom the thao " << endl;
	Nhom::Xuat();
	cout << "So mon the thao: " << this->SoMonTT << endl;
	cout << "So danh hieu: " << this->SoDanhHieu << endl;
	cout << "Ti le thang: " << this->TiLeThang << endl;
}

double NhomTheThao::TinhDiem()
{
	return ((double)SoHD / TGHD) * 30 + ((double)SoMonTT / 15) * 20 + ((SoDanhHieu * 2) / (double)TGHD) * 30 + TiLeThang * 20;
}

int NhomTheThao::LayLoaiNhom()
{
	return 3;
}

void NhomTheThao::XepLoai()
{
	if (this->TinhDiem() >= 80 && TiLeThang >= 0.75)
		cout << "Dat" << endl;
	else
	{
		this->SoNhomKhongDat++;
		cout << "Khong dat" << endl;
	}
		
}
