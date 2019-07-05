#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void DrawMatrix(int Board[][3], int size);
void ClearScreen();
int Calculate(int Board[][3], int x_Player, int y_Player, int x_AI, int y_AI);
bool CheckWin (int Board[][3], int x, int y, int size, int point);
int ProbWin (int Board[][3], int x, int y, int size, int point);
int main()
{
	int size = 3;
	int Board[3][3];
	int x_Player, y_Player;
	int x_AI, y_AI;
	int point_Player;
	int point_AI;
	// Init
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			Board[i][j] = 0;
	point_AI = -1;
	point_Player = 1;
	DrawMatrix(Board,size);
	
	while(1)
	{
		//Player
		cout<<"Nhap toa do diem muon danh: ";
		cin>>x_Player>>y_Player;
		Board[y_Player][x_Player] = point_Player;
		if (CheckWin(Board, x_Player, y_Player,size,point_Player))
		{
			DrawMatrix(Board, size);
			cout<<"Player wins";
			break;
		}
		DrawMatrix(Board, size);
		// AI
		/*
		Calculate(Board,x_Player,y_Player,x_AI,y_AI);
		Board[y_AI][x_AI] = point_AI;
		DrawMatrix(Board);
		if (CheckWin(Board, x_AI, y_AI,size,point_AI))
		{
			cout<<"AI wins";
			break;
		}
		*/
	}
	
	return 0;
}
int Calculate(int Board[][3], int x_Player, int y_Player, int x_AI, int y_AI)
{
	
}

int ProbWin (int Board[][3], int x, int y, int size, int point)
{
	int res = 0;
	int count = 0;
	bool check = true;
	// Check ngang
	for (int i = 0; i < size; i++)
		if (Board[y][i] == -point)
			check = false;
	if (check)
		res++;
	// Check doc
	for (int i = 0; i < size; i++)
		if (Board[i][x] == -point)
			check = false;
	if (check)
		res++;
	// Loai bo diem bia
	if ((x == 0 && y > 0 && y < size-1) || (x == size-1 && y > 0 && y < size-1) 
		|| (y == 0 && x > 0 && x < size-1) || (y == size-1 && x > 0 && x < size-1))
		return res;	
	// Check duong cheo
	// Danh rieng cho truong hop 3x3
	int Cheotrai = Board[0][0] + Board[2][2] + Board[1][1];
	int Cheophai = Board[0][2] + Board[2][0] + Board[1][1]

	if (abs(Cheotrai) == 1 || abs(Cheotrai) == 2)
		res++;
	else if (abs(Cheophai) == 1 || abs(Cheophai) == 2)
		res++;
	return res;
}

bool CheckWin (int Board[][3], int x, int y, int size, int point)
{
	// Check ngang
	int count = 0;
	for (int i = 0; i < size; i++)
		if (Board[y][i] == point)
			count++;
	if (count == 3)
		return true;
	// Check doc
	count = 0;
	for (int i = 0; i < size; i++)
		if (Board[i][x] == point)
			count++;
	if (count == 3)
		return true;
	// Loai bo truong hop de xet
	// Diem bia, da xet het truong hop nhung van ko thang nen return false
	// Xem xet rut gon
	if ((x == 0 && y > 0 && y < size-1) || (x == size-1 && y > 0 && y < size-1) 
		|| (y == 0 && x > 0 && x < size-1) || (y == size-1 && x > 0 && x < size-1))
		return false;
	// Check duong cheo
	// Danh rieng cho truong hop 3x3
	if ((Board[0][0] == Board[2][2] && Board[0][0] == Board[1][1] && Board[1][1] == point) 
		|| (Board[0][2] == Board[2][0] && Board[0][2] == Board[1][1]  && Board[1][1] == point))
			return true;
	return false;
}

void ClearScreen()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}

void DrawMatrix(int Board[][3], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout<<Board[i][j]<<" ";
		cout<<endl;
	}

}
//int Calculate(int Board[][3], int x_Player, int y_Player, int x_AI, int y_AI);
//bool CheckWin (int Board[][3], int x, int y);