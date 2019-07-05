#include <iostream>
#include "XeBuyt.h"
#include "XeCon.h"
#include "XeTai.h"
#include "Xe.h"
using namespace std;

int main()
{
	int n;
	cout << "Nhap so luong xe: ";
	cin >> n;
	Xe** List = new Xe*[n];
	int Choice;
	for (int i = 0; i < n; i++)
	{
		cout << "Chon loai xe: "<<endl;
		cout<< "1/ Xe buyt." << endl;
		cout << "2/Xe con." << endl;
		cout << "3/ Xe tai." << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
			case 1: 
				List[i] = new XeBuyt;
				break;
			case 2:
				List[i] = new XeCon;
				break;
			case 3:
				List[i] = new XeTai;
				break;
		}
		List[i]->InputInfo();
		List[i]->TinhPhi();
	}
	cout << "In thong tin" << endl;
	for (int i = 0 ; i < n ; i++)
		List[i]->PrintInfo();
	return 0;
}