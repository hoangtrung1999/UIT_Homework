#include "XeCon.h"



XeCon::XeCon()
{
}


XeCon::~XeCon()
{
}

void XeCon::InputInfo()
{
	Xe::InputInfo();
	cout << "Nhap so cho ngoi: ";
	cin >> this->ChoNgoi;
}

void XeCon::PrintInfo()
{
	Xe::PrintInfo();
	cout << "So cho ngoi: " << this->ChoNgoi << endl;
	cout << "Chi phi: " << this->Phi << endl;
}

void XeCon::TinhPhi()
{
	if (this->ChoNgoi > 4)
		this->Phi = 20000;
	else
		this->Phi = 15000;
}
