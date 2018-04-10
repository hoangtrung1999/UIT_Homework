#include <iostream>
using namespace std;

struct SoPhuc
{
	int PhanThuc;
	int PhanAo;
};

void Input (SoPhuc &sp)
{
	cout<<"Nhap phan thuc cua so phuc: ";
	cin>>sp.PhanThuc;
	cout<<"Nhap phan ao cua so phuc: ";
	cin>>sp.PhanAo;
}

void PrintSP (SoPhuc sp)
{
	if (sp.PhanAo > 0)
	{
		cout<<sp.PhanThuc<<"+"<<sp.PhanAo<<"i"<<endl;
	}
	else if (sp.PhanAo == 0)
		cout<<sp.PhanThuc<<endl;
	else
		cout<<sp.PhanThuc<<sp.PhanAo<<"i"<<endl;
}

SoPhuc Calculate(SoPhuc sp1, SoPhuc sp2)
{
	SoPhuc sp;
	sp.PhanThuc = sp1.PhanThuc*sp2.PhanThuc - sp1.PhanAo*sp2.PhanAo;
	sp.PhanAo = sp1.PhanThuc*sp2.PhanAo + sp1.PhanAo*sp2.PhanThuc;
	return sp;
}


int main(int argc, char const *argv[])
{
	SoPhuc sp1, sp;
	int n;
	cout<<"Nhap so phuc 1: "<<endl;
	Input(sp1);
	cout<<"Nhap so bac n: "<<endl;
	cin>>n;
	cout<<"Luy thua bac n cua so phuc: "<<endl;
	for (int i = 0 ; i < n ; i++)
	sp = Calculate(sp1,sp2);
	PrintSP(sp);
	return 0;
}