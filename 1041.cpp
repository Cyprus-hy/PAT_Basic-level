#include<iostream>
#include<string>

using namespace std;

typedef struct Mystruct
{
	string ID;//准考证号
	int i_try;//试机座位号
	int i_test;//考试座位号
}Stu;

int main()
{
	int n, m;
	Stu temp[1000];
	cin >> n;
	for (int i = 0; i < n; i++)//输入每个学生的信息
		cin >> temp[i].ID >> temp[i].i_try >> temp[i].i_test;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < n; j++)//遍历寻找该学生的准考证号以及考试座位号
		{
			if (temp[j].i_try == a)
			{
				cout << temp[j].ID <<" "<<temp[j].i_test << endl;
				break;
			}
		}
	}

	return 0;
}