#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, m, score[100] = { 0 };
	string answer;//正确答案
	cin >> n >> m;

	for (int i = 0; i < m; i++)//输入每一道题的分数
		cin >> score[i];

	for (int j = 0; j < m; j++)
	{
		char c;
		cin >> c;
		answer += c;//正确答案用字符串存储
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;//每一位学生的成绩
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == answer[j])//判断答案是否正确
				sum += score[j];
		}
		cout << sum<<endl;
	}
	return 0;
}