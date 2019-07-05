#include "XeBuyt.h"



XeBuyt::XeBuyt()
{
}


XeBuyt::~XeBuyt()
{
}

void XeBuyt::InputInfo()
{
	Xe::InputInfo();
	cout << "Nhap so tuyen: ";
	cin >> this->SoTuyen;
	cout << "Nhap do dai quang duong: ";
	cin >> this->QuangDuong;
}

void XeBuyt::PrintInfo()
{
	Xe::PrintInfo();
	cout << "So tuyen: " << this->SoTuyen << endl;
	cout << "Do dai quang duong: " << this->QuangDuong << endl;
	cout << "Phi xe: " << this->Phi<<endl;
}

void XeBuyt::TinhPhi()
{
	if (this->QuangDuong > 31)
		this->Phi = 5000;
	else
		this->Phi = 3000;
}
