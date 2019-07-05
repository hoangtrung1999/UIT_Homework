#pragma once
#include "Xe.h"
class XeBuyt : public Xe
{
private:
	int SoTuyen;
	int QuangDuong;
	int Phi;
public:
	XeBuyt();
	~XeBuyt();
	void InputInfo();
	void PrintInfo();
	void TinhPhi();
};

