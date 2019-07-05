#include "XeTai.h"



XeTai::XeTai()
{
}


XeTai::~XeTai()
{
}

void XeTai::InputInfo()
{
	Xe::InputInfo();
	cout << "Nhap vao so tan: ";
	cin >> this->SoTan;
}

void XeTai::PrintInfo()
{
	Xe::PrintInfo();
	cout << "So tan:" << this->SoTan<<endl;
	cout << "Chi phi: " << this->Phi<<endl;
}

void XeTai::TinhPhi()
{
	if (this->SoTan > 3.5)
		this->Phi = 20000;
	else
		this->Phi = 10000;
}
