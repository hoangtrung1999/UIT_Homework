#pragma once
#include "Candidate.h"
class TestCandidate
{
private:
	int number;
	Candidate *List;
public:
	TestCandidate();
	~TestCandidate();
	void InputInfos();
	void PrintCandidates();
};

