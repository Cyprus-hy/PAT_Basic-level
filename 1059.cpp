#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

typedef struct Mystruct
{
	int ID;
	int rank;//排名
	int flag;//flag代表是否已经领取过奖品
	int award;//0代表神秘大奖，1代表小黄人，2代表巧克力
}Team;

int main()
{
	int n, k;
	vector<Team> temp;
	cin >> n;
	int count[10001] = { 0 };
	string s[5] = { "Mystery Award","Minion","Chocolate","Are you kidding?","Checked" };//对应字符串

	for (int i = 2; i <= 10000; i++)//得到2到10000内的所有素数
	{
		int flag = 1;
		for (int j = 2; j <= sqrt(i); j++)//遍历到平方根节省时间
		{
			if (i%j == 0)
			{
				flag = 0; 
				break;
			}
		}
		if (flag)//素数标记为1
			count[i] = 1;
	}

	for (int i = 0; i < n; i++)//输入数据
	{
		Team t;
		cin >> t.ID;
		t.flag = 0;
		t.rank = i + 1;
		if (t.rank == 1)//冠军得到神秘大奖
			t.award = 0;
		else if (count[t.rank] == 1)//排名为素数的得到小黄人
			t.award = 1;
		else//其他队得到巧克力
			t.award = 2;
		temp.push_back(t);
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int e,isFind=0;
		cin >> e;//输入队伍编号

		for (int k = 0; k < n; k++)
		{
			if (temp[k].ID == e)
			{
				isFind = 1;//找到该队伍
				if (!temp[k].flag)//还未领过奖品
				{
					printf("%04d", e);//注意对于小于1000的队号，前面要补0，printf可以用%04d实现
					cout << ": " << s[temp[k].award] << endl;
					temp[k].flag = 1;
				}
				else//领取过奖品了
				{
					printf("%04d", e);
					cout<< ": " << s[4] << endl;
				}
			}
		}

		if (!isFind)//未找到该队伍
		{
			printf("%04d", e);
			cout<< ": " << s[3] << endl;
		}
	}
	return 0;
}