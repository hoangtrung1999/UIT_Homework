#include <iostream>
#include <string>
using namespace std;

struct Student
{	
	string Name;
	string MSSV;
	int Score;
};

void InputInfo (Student ListStudents[100], int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		cout<<"Nhap thong tin sinh vien "<<i<<endl;
		cout<<"Ten sinh vien: ";
		getline(cin,ListStudents[i].Name);
		cout<<"Ma so sinh vien: ";
		getline(cin,ListStudents[i].MSSV);
		cout<<"Diem so sinh vien: ";
		cin>>ListStudents[i].Score;
	}

}

void PrintInfo (Student ListStudents[100], int n)
{
	cout<<"Danh sach sinh vien"<<endl;
	for (int i = 0 ; i < n ; i++)
		cout<<ListStudents[i].Name<<endl;
}

void PrintMaxScores (Student ListStudents[100], int n)
{
	int Max = ListStudents[0].Score;
	cout<<"Nhung sinh vien co diem trung binh cao nhat la"<<endl;
	for (int i = 1 ; i < n ; i++)
		if ( Max < ListStudents[i].Score)
			Max = ListStudents[i].Score;
	for (int j = 0 ; j < n ; j++)
		if (Max == ListStudents[j].Score)
			cout<<ListStudents[j].Name<<endl;
}

int AboveMedium (Student ListStudents[100], int n)
{
	int count = 0;
	for (int i = 0 ; i < n ; i++)
		if ( ListStudents[i].Score >= 5 )
		count++;
	if (count == 0)
		cout<<"Khong co sinh vien nao tren 5"<<endl;
	else
		return count;
}

void FindSV (Student ListStudents[100], int n)
{
	string NameToFind;
	getline(cin,NameToFind);
	for (int i = 0 ; i < n ; i++)
		if ( NameToFind == ListStudents[i].Name)
		{
			cout<<"Sinh vien co ten trong danh sach"<<endl;
			return;
		}
	cout<<"Khong tim thay sinh vien"<<endl;
}

void DeleteInfo (Student ListStudents[100], int &n)
{
	string Index;
	bool flag = false;
	cout<<"Nhap MSSV can xoa"<<endl;
	getline(cin,Index);
	int i;
	for (i = 0 ; i < n ; i++)
		if (ListStudents[i].MSSV == Index)
		{
			flag = true;
			break;
		}
	if (flag == false)
		cout<<"Khong tim thay sinh vien"<<endl;
		else
		{
			for (int j = i ; j < n - 1 ; j ++)
				ListStudents[j] = ListStudents[j+1];
			n--;
		}
	cout<<"Danh sach sinh vien sau khi xoa la: "<<endl;
	PrintInfo(ListStudents,n);	
}

void SortStudent(Student ListStudents[100], int n)
{
	cout<<"Sap xep danh sach diem sinh vien"<<endl;
	int temp;
	for (int i = 0 ; i < n - 1 ; i++)
		for (int j = i + 1 ; j < n ; j++)
			if (ListStudents[j].Score < ListStudents[i].Score)
			{
				temp = ListStudents[j].Score;
				ListStudents[j].Score = ListStudents[i].Score;
				ListStudents[i].Score = temp;
			}
	cout<<"Danh sach sau khi duoc sap xep la: "<<endl;
	PrintInfo(ListStudents,n);
}

void InsertSV (Student ListStudents[100], int &n)
{
	Student StudentA;
	cout<<"Nhap thong tin sinh vien "<<endl;
	cout<<"Ten sinh vien: ";
	getline(cin,StudentA.Name);
	cout<<"Ma so sinh vien: ";
	getline(cin,StudentA.MSSV);
	cout<<"Diem so sinh vien: ";
	cin>>StudentA.Score;
	int i;
	for (int i = 0 ; i < n ; i++)
		if ( ListStudents[i].Score > StudentA.Score)
			break;
	i--;
	n++;
	for (int j = n - 1; j > i ; j-- )
		ListStudents[j] = ListStudents[j-1];
	ListStudents[i] = StudentA;
	cout<<"Danh sach sinh vien sau khi chen la: "<<endl;
	PrintInfo(ListStudents,n);

}

int main()
{
	int n;
	Student ListStudents[100];
	cout<<"Nhap so luong sinh vien: ";
	cin>>n;
	InputInfo(ListStudents,n);

	int choice;
	cout<<"Nhap vao lua chon cua ban: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			PrintInfo(ListStudents,n);
			break;
		case 2:
			PrintMaxScores(ListStudents,n);
			break;
		case 3:
			cout<<"So sinh vien co diem trung binh >= 5 la: "<<AboveMedium(ListStudents,n);
			break;
		case 4:
			FindSV(ListStudents,n);
			break;
		case 5:
			DeleteInfo(ListStudents,n);
			break;
		case 6:
			SortStudent(ListStudents,n);
			break;
		case 7:
			InsertSV(ListStudents,n);
			break;
	}
	return 0;
}