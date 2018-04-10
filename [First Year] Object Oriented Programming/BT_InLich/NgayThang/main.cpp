#include <iostream>
#include "Ngay.h"
using namespace std;

int main()
{
	Ngay n1;
	cout << "Nhap ngay/thang/nam can xem lich" << endl;
	n1.NhapNgay();
	n1.XuatNgay();
	n1.InLich();

	system("pause");
	return 0;
}