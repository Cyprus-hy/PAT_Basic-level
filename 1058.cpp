#include<iostream>

using namespace std;

typedef struct Mystruct
{
	int score;//满分
	int all;//所有选项个数
	int right;//正确的选项个数
	string option;//正确选项
}Test;

int main()
{
	int n, m;
	cin >> n >> m;
	Test temp[100];//记录每道题的信息
	int count[100] = { 0 };//记录每道题的错误次数

	for (int i = 0; i < m; i++)
	{
		cin >> temp[i].score >> temp[i].all >> temp[i].right;//输入每道题的满分、选项数以及正确选项数
		for (int j = 0; j < temp[i].right; j++)
		{
			char c;
			cin >> c;
			temp[i].option += c;//输入正确选项
		}
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;//总成绩
		for (int j = 0; j<m;j++)
		{
			int a, flag = 1;
			char c1,c2;
			string s;
			cin >> c1 >> a;//选项数
			for (int k = 0; k < a; k++)//选项的输入
			{
				char c;
				cin >> c;
				s += c;
			}
			cin >> c2;

			if (a != temp[j].right)//所选个数不等于正确选项个数
				flag=0;

			else
			{
				for (int k = 0; k < a; k++)
				{
					if (s[k] != temp[j].option[k])//选项不相等
					{
						flag = 0;
						break;
					}
				}
			}

			if (flag)//flag为1表示这道题正确
				sum += temp[j].score;
			else//flag=0表示该题选错了
				count[j]++;
		}

		cout << sum << endl;
	}

	int max = 0;

	for (int i =0; i < m; i++)//找错误次数最多的
	{
		if (count[i] > max)
			max = count[i];
	}

	if (max == 0)//没有错
		cout << "Too simple\n";
	else
	{
		cout << max;
		for (int i = 0; i < m; i++)
		{
			if (max == count[i])//寻找错误次数最大的题号
				cout << " " << i + 1;
		}
		cout << endl;
	}

	return 0;
}