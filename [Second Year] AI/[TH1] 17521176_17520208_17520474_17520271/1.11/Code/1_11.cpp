/*
	Đề bài: Có n công việc được phân cho m máy thực hiện, mỗi việc được phân cho một máy. Giả sử ta biết thời gian
	Tij cần để người thứ i thực hiện công việc thứ j, Hãy tìm một phương án phân công sao cho thời gian hoàn thành 
	tất cả các công việc là thấp nhất (tính từ khi mọi người cùng bắt đầu thực hiện các công việc được phân công cho tới khi
	tất cả công việc đều được thực hiện xong)
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int SelectHuman (vector<int> &workTime, vector<int> &position)
{
	int min = workTime[position[0]];
	int id = 0;
	for (int i = 1; i < position.size(); i++)
	{
		//cout<<"Work: "<<workTime[position[i]]<<endl;
		if (workTime[position[i]] <= min)
		{
			min = workTime[position[i]];
			id  = position[i];
		}		
	}

	return id;
}

using namespace std;
int main()
{
	ifstream input;
	input.open("1_11_input.txt", ios::app);

	int n; // n cong viec
	int m; // m nguoi
	input>>n;
	input>>m;

	vector<int> workTime;
	vector<int> saveWork(n);
	vector<int> position(m);



	int temp;
	for (int i = 0; i < n*m; i++)
	{
		input >> temp;
		workTime.push_back(temp);
	}
	
	for (int i = 0; i < m; i++)
		position[i] = i*n;

	for (int i = 0; i < n; i++)
	{
		int human = SelectHuman(workTime, position) / n;
		saveWork[i] = human;
		for (int j = 0; j < m; j++)
				position[j] += 1;
	}	

	for (int i = 0; i < m; i++)
	{
		cout<<"Work of human "<<i+1<<": ";
			for (int j = 0; j < n ; j++)
				if (saveWork[j] == i)
					cout<<j+1<<" ";
		cout<<endl;
	}
	input.close();
	return 0;
}