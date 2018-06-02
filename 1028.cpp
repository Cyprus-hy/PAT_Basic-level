#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct Mystruct
{
	char name[20];//scanf输入字符串要求用char数组而不是string定义
	int year;
	int month;
	int day;
}Peo;

bool cmp(Peo a, Peo b)//从年纪最大到年纪最小
{
	if (a.year < b.year)
		return true;
	else if (a.year == b.year&&a.month < b.month)
		return true;
	else if (a.year == b.year&&a.month == b.month&&a.day < b.day)
		return true;
	else
		return false;
}

int main()
{
	vector<Peo> p;//vector存
	int n, count=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Peo temp;
		char s[11];
		scanf("%s %s",temp.name,s);//用scanf和printf，cin和cout会超时
		temp.year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + s[3] - '0';
		temp.month = (s[5] - '0') * 10 + s[6] - '0';
		temp.day = (s[8] - '0') * 10 + s[9] - '0';//字符串转化成整数
		if (temp.year > 1814 && temp.year < 2014)
		{
			p.push_back(temp);
			count++;
		}
		else if((temp.year==1814&&temp.month>9)|| (temp.year == 1814 && temp.month==9&&temp.day>=6))
		{
			p.push_back(temp);
			count++;
		}
		else if ((temp.year == 2014 && temp.month<9) || (temp.year == 2014 && temp.month == 9 && temp.day <= 6))
		{
			p.push_back(temp);
			count++;
		}
	}
	if (count > 0)
	{
		sort(p.begin(), p.end(), cmp);
		printf("%d %s %s\n", count, p[0].name, p[count - 1].name);
	}
	else//考虑全是无效数据的情况
		cout << "0" << endl;
	return 0;
}