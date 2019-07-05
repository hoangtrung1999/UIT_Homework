/*
Nguyen Hoang Trung
MSSV: 17521176
*/
#include <stdio.h>

int main()
{
	int processID[10];
	int arriveTime[10], burstTime[10], startTime[10]
		, finishTime[10], turnAroundTime[10], waitingTime[10], n;

	int totalWaitingTime = 0;
	int totalTurnAroundTime = 0;
	printf("Enter the number of the processes: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Enter the Process ID, Arrival Time & Burst Time\n");
		scanf("%d%d%d",&processID[i],&arriveTime[i],&burstTime[i]);
	}

	// Init the first value
	startTime[0] = arriveTime[0];
	waitingTime[0] = 0;
	finishTime[0] = startTime[0] + burstTime[0];
	turnAroundTime[0] = finishTime[0] - arriveTime[0];

	for (int i = 1; i < n; i++)
	{
		startTime[i] = finishTime[i-1];
		waitingTime[i] = startTime[i] - arriveTime[i];
		finishTime[i] = startTime[i] + burstTime[i];
		turnAroundTime[i] = finishTime[i] - arriveTime[i];
	}

	printf("ProcessID ArriveTime BurstTime \tStart\t TAT\tFinishTime\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%6d\t\t%6d\t%6d\t%6d\t%6d\n",processID[i], arriveTime[i], burstTime[i], startTime[i], turnAroundTime[i], finishTime[i]);
		totalWaitingTime += waitingTime[i];
		totalTurnAroundTime += turnAroundTime[i];
	}

	return 0;
}