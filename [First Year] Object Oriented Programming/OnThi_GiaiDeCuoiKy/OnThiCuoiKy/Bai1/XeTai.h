#pragma once
#include "Xe.h"
class XeTai : public Xe
{
private:
	int SoTan;
	double Phi;
public:
	XeTai();
	~XeTai();
	void InputInfo();
	void PrintInfo();
	void TinhPhi();
};

