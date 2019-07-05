#pragma once
#include "Xe.h"
class XeCon : public Xe
{
private:
	int ChoNgoi;
	int Phi;
public:
	XeCon();
	~XeCon();
	virtual void InputInfo();
	virtual void PrintInfo();
	virtual void TinhPhi();
};

