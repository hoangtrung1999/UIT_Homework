#include <iostream>
#include <cmath>
using namespace std;

struct Oxy
{
	int x;
	int y;
};

void Input (Oxy &point)
{
	cout<<"Nhap toa do x: ";
	cin>>point.x;
	cout<<"Nhap toa do y: ";
	cin>>point.y;
}

float Distance (Oxy &pointA , Oxy &pointB)
{
	return sqrt((pointA.x - pointB.x)*(pointA.x - pointB.x)+(pointA.y - pointB.y)*(pointA.y - pointB.y));
}

int main()
{
	Oxy pointA, pointB;
	cout<<"Nhap toa do diem A: "<<endl;
	Input(pointA);
	cout<<"Nhap toa do diem B: "<<endl;
	Input(pointB);
	cout<<"Khoang cach giua hai diem: "<<endl;
	cout<<Distance(pointA,pointB);
	return 0;
}