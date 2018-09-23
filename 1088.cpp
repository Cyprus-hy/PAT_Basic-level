#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int M, X, Y,flag=0;
	cin >> M >> X >> Y;
	vector<int> res;

	for (int i = 10; i <= 99; i++)
	{
		int a = i / 10;
		int b = i-a*10;
		int c = b * 10 + a;
		if ((double)abs(i - c) / X == (double)c / Y)//寻找符合条件的解，丙的分数可能是小数
		{
			res.push_back(i);
			flag = 1;
		}
	}

	if (!flag)//解不存在
		cout << "No Solution\n";
	else
	{
		double score[3] = { 0 };
		score[0] = res[res.size() - 1];//甲的分数
		int a = score[0] / 10;
		int b = score[0] - a * 10;
		score[1] = b * 10 + a;//乙的分数
		score[2] =(double) score[1] / Y;//丙的分数，其分数可能为浮点数！！！

		cout << score[0];
		for (int i = 0; i < 3; i++)
		{
			if (score[i] > M)
				cout << " Cong";
			else if (score[i] == M)
				cout << " Ping";
			else
				cout << " Gai";
		}
	}
	return 0;
}