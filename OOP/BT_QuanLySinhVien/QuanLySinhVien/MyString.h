#pragma once
class MyString
{
private:
	char buffer[256];
	int size;
	int Limit = 255;
public:
	MyString();
	~MyString();
	void GetString();
	void PrintString();
};

