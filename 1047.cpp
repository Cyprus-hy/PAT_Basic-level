#include<iostream>
#include<string>

using namespace std;

typedef struct Mystruct
{
	int team;//队号
	int team_mem;//队员编号
	int num;//成绩
}Grade;

int main()
{
	int max=1,n, sum[1001] = { 0 };
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		Grade g;
		scanf("%d-%d %d", &g.team, &g.team_mem, &g.num);//利用scanf进行输入会简单很多
		sum[g.team] += g.num;//该队的总成绩
	}

	for (int i = 2; i < 1001; i++)//寻找总成绩的最大值
	{
		if (sum[i] > sum[max])
			max = i;
	}

	cout << max << " " << sum[max] << endl;

	return 0;
}