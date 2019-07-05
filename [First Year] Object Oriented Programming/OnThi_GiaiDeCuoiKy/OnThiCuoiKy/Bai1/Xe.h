#pragma once
#include <iostream>
#include <string>
using namespace std;

class Xe
{
protected:
	string BienSo;
	string MauXe;
	string NhanHieuXe;
public:
	Xe();
	~Xe();
	virtual void InputInfo();
	virtual void PrintInfo();
	virtual void TinhPhi();
};

