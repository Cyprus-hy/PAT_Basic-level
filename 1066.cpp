#include<iostream>

using namespace std;

int main()
{
	int m, n, a, b, t;
	cin >> m >> n >> a >> b >> t;
	for (int i = 0; i < m; i++)
	{
		int color[500] = { 0 };//���ÿһ����ɫ����

		for (int j = 0; j < n; j++)
		{
			cin >> color[j];
			if (a <= color[j] && b >= color[j])//�������ڵĽ����滻
				color[j] = t;
		}
		
		for (int k = 0; k < n-1; k++)
			printf("%03d ", color[k]);//ÿ���Ҷ�ֵռ3λ
		printf("%03d\n", color[n-1]);
	}
	return 0;
}