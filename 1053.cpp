#include<iostream>

using namespace std;

int main()
{
	double n, e, D,count1=0,count2=0;
	cin >> n >> e >> D;
	for (int i = 0; i < n; i++)
	{
		double a,d,count=0;
		cin >> d;
		for (int j = 0; j < d; j++)
		{
			cin >> a;
			if (a < e)//�����ж�����ĵ�����С����ֵ��
				count++;
		}
		if (count > d / 2&&d<=D)//Ҫô�ǿ�������Ҫô������
			count1++;
		if (d > D&&count > d / 2)
			count2++;
	}
	printf("%.1f%% ", count1 / n*100);//�ٷֺ�Ҫת��
	printf("%.1f%%\n", count2 / n * 100);
	return 0;
}