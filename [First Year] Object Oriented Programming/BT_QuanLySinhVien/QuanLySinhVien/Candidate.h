#pragma once
#include "MyString.h"
#include "Date.h"
class Candidate
{
private:
	MyString ID;
	MyString Name;
	Date BirthDay;
	int Math;
	int Literature;
	int English;
	int SumMark;
public:
	Candidate();
	~Candidate();
	void GetInfo();
	void PrintInfo();
	friend class TestCandidate;
};

