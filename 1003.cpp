#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct Mystruct
{
	string s;
	int countp;//P的个数
	int countt;//T的个数
	int counta1;//P左边A的个数
	int counta2;//P与T之间A的个数
	int counta3;//T右边A的个数
	int flag;//判断是否有其他字符
	int p;//P的位置
	int t;//T的位置
	int isTrue;//是否正确
}PAT;

int main()
{
	int n;
	cin >> n;
	vector<PAT>pp;

	for (int i = 0; i < n; i++)
	{
		PAT tem;
		//初始化
		tem.counta1 = 0;
		tem.counta2 = 0;
		tem.counta3 = 0;
		tem.countp = 0;
		tem.countt = 0;
		tem.flag = 1;
		tem.p = 0;
		tem.t = 0;
		tem.isTrue = 0;
		cin >> tem.s;

		for (int j = 0; j < tem.s.length(); j++)
		{
			//判断字符串中是否有其他字符
			if (tem.s[j] != 'P'&&tem.s[j] != 'A'&&tem.s[j] != 'T')
			{
				tem.flag = 0;
				break;
			}

			//计数
			if (tem.s[j] == 'P')
			{
				tem.countp++;
				tem.p = j;//记录P的位置
			}
			else if (tem.s[j] == 'T')
			{
				tem.countt++;
				tem.t = j;//记录T的位置
			}

		}

		pp.push_back(tem);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < pp[i].s.length(); j++)
		{
			if (pp[i].s[j] == 'A')
			{
				//P左边的A
				if (j < pp[i].p)
					pp[i].counta1++;
				//P与T之间的A
				else if (pp[i].p < j&&j < pp[i].t)
					pp[i].counta2++;
				//T右边的A
				else
					pp[i].counta3++;
			}
				
		}

		//注意P与T的个数必须为1，P与T之间的A的个数要大于等于1
		if (pp[i].countp != 1 || pp[i].countt != 1 || pp[i].counta2 < 1)
			pp[i].flag = 0;

		if (!pp[i].flag)
			cout << "NO\n";
		else
		{
			//注意规律：开头的A的个数 * 中间的A的个数 = 结尾的A的个数
			if (pp[i].counta1*pp[i].counta2 == pp[i].counta3)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}