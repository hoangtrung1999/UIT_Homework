#include "Xe.h"



Xe::Xe()
{
}


Xe::~Xe()
{
}

void Xe::InputInfo()
{
	cout << "Nhap bien so xe: ";
	getline(cin, this->BienSo);
	cout << "Nhap mau xe: ";
	getline(cin, this->MauXe);
	cout << "Nhap nhan hieu xe: ";
	getline(cin, this->NhanHieuXe);
}

void Xe::PrintInfo()
{
	cout << "Bien so xe: " << this->BienSo<<endl;
	cout << "Mau xe: " << this->MauXe<<endl;
	cout << "Nhan hieu xe: " << this->NhanHieuXe<<endl;
}

void Xe::TinhPhi()
{
}
