#include<iostream>

using namespace std;

int main()
{
	int m, n, a, b, t;
	cin >> m >> n >> a >> b >> t;
	for (int i = 0; i < m; i++)
	{
		int color[500] = { 0 };//存放每一组颜色数据

		for (int j = 0; j < n; j++)
		{
			cin >> color[j];
			if (a <= color[j] && b >= color[j])//在区间内的进行替换
				color[j] = t;
		}
		
		for (int k = 0; k < n-1; k++)
			printf("%03d ", color[k]);//每个灰度值占3位
		printf("%03d\n", color[n-1]);
	}
	return 0;
}