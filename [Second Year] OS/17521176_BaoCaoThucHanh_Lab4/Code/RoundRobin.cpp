#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
using namespace std;

struct Process
{
	int ID;
	int BurstTime;
	int StartTime = 0;
	int StopTime = 0;
	int FinishTime = 0;
	int WaitTime = 0;
	bool Started = false;
};

void PrintQueue(queue <Process> Q)
{
	cout<<"Test Case:"<<endl;
	do
	{
		Process p = Q.front();
		cout<<"Process's ID: "<<p.ID<<", BurstTime: "<<p.BurstTime<<", Arrival Time: "<<"0"<<endl;
		Q.pop();
	}while (!Q.empty());
	cout<<"--------------------Solving--------------------"<<endl;
}

void PrintResult(vector <int> W, queue <Process> Q, int n)
{
	int i = 0;
	float sumWait = 0;
	float sumFinish = 0;
	do
	{
		Process p = Q.front();
		cout<<"Process's ID: "<<p.ID<<", Start Time: "<<p.StartTime<<", Stop Time: "<<p.FinishTime<<", Wait Time: "<<W[i]<<endl;
		sumFinish += p.FinishTime;
		sumWait += W[i];
		Q.pop();
		i++;
	}while (!Q.empty());
	cout<<"Average waiting time: "<< sumWait/n <<endl;
	cout<<"Average turnaround tine: "<< sumFinish/n <<endl;
}

void Calculate (queue<Process> &Q, int qt, queue<Process> &Result,vector <int> &W)
{
	int TimeMark = 0;
	int temp = qt;

	do
	{
		Process currentP;

		currentP.ID = Q.front().ID;
		currentP.BurstTime = Q.front().BurstTime;
		int deltaTime = Q.front().BurstTime - qt;

		if (Q.front().Started == false)
		{
			currentP.StartTime = TimeMark;
			currentP.Started = true;
		}
		else
			currentP.StartTime = Q.front().StartTime;
		if (deltaTime > 0)
		{
			W[currentP.ID-1] += TimeMark - Q.front().StopTime;
			currentP.BurstTime -= qt;
			TimeMark += qt;
			currentP.StopTime = TimeMark;
			Q.push(currentP);
			Q.pop();
			qt = temp;
		}
		else
		{
			if (qt > currentP.BurstTime)
				qt -= currentP.BurstTime;
			W[currentP.ID-1] += TimeMark - Q.front().StopTime;
			TimeMark += currentP.BurstTime;
			currentP.BurstTime = 0;
			currentP.FinishTime = TimeMark;
			Result.push(currentP);
			Q.pop();
		}
	}
	while (!Q.empty());
}

int main()
{
	ifstream file;
	file.open("testcase.txt", ios::in|ios::app|ios::binary);

	int n;
	file>>n;

	int QuantumTime;
	file>>QuantumTime;

	queue<Process> QueueP;
	queue<Process> Result;
	vector<int> WaitP(n,0);
	for (int i = 1; i <= n; i++)
	{
		Process newP;
		newP.ID = i;
		file>>newP.BurstTime;
		QueueP.push(newP);
	}
	file.close();

	cout<<"We assume these processes arrived at the same time."<<endl;
	cout<<"Users can change test case in file testcase.txt"<<endl;
	cout<<"Number of test case: "<<n<<endl;
	cout<<"Quantum time: "<<QuantumTime<<endl;
	PrintQueue(QueueP);
	Calculate(QueueP,QuantumTime,Result,WaitP);
	PrintResult(WaitP,Result,n);
	return 0;
}
