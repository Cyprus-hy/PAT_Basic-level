#include<iostream>
#include<string>

using namespace std;

typedef struct Mystruct
{
	int team;//�Ӻ�
	int team_mem;//��Ա���
	int num;//�ɼ�
}Grade;

int main()
{
	int max=1,n, sum[1001] = { 0 };
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		Grade g;
		scanf("%d-%d %d", &g.team, &g.team_mem, &g.num);//����scanf���������򵥺ܶ�
		sum[g.team] += g.num;//�öӵ��ܳɼ�
	}

	for (int i = 2; i < 1001; i++)//Ѱ���ܳɼ������ֵ
	{
		if (sum[i] > sum[max])
			max = i;
	}

	cout << max << " " << sum[max] << endl;

	return 0;
}