#include "TestCandidate.h"
#include <iostream>
using namespace std;
TestCandidate::TestCandidate()
{
}


TestCandidate::~TestCandidate()
{
}

void TestCandidate::InputInfos()
{
	cout << "Input number of candidates: ";
	cin>>this->number;
	getchar();
	this->List = new Candidate[this->number];
	for (int i = 0; i < this->number; i++)
	{
		List[i].GetInfo();
	}
}

void TestCandidate::PrintCandidates()
{
	cout << "Candidates who have marks of 3 subjects greater than 15" << endl;
	for (int i = 0; i < this->number; i++)
		if (List[i].SumMark > 15)
			List[i].PrintInfo();
}
