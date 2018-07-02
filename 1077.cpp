#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int count = 0, score=0, a, num[100] = { 0 };
		double  res=0;//先将结果存为小数再转化成整数，避免精度错误
		cin >> a;

		for (int j = 1; j < n; j++)
		{
			int b;
			cin >> b;
			if (0 <=b &&b<= m)
				num[count++] = b;//将符合条件的分数存入数组
		}

		sort(num, num + count);//排序

		for (int k = 1; k < count - 1; k++)//舍去最大值与最小值
			res += num[k];

		res = (res / (count - 2) + a) / 2;
		score = res+0.5;//四舍五入小数转成整数，不能直接转成整数，这样就直接截取了
		cout << score << endl;
	}
	return 0;
}