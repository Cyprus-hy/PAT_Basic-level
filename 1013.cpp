#include<iostream>
#include<cmath>

using namespace std;

void FindNum(int *n)//寻找2到1000000内的素数
{
	int count = 0,flag=1;
	for (int i=2; i <= 1000000; i++)
	{
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)//flag标志是否为素数
		{
			*(n+count) = i;
			count++;
		}
		if (count == 10000)//只需要求前10000个素数
			break;
		flag = 1;//重置，一定要记得重置
	}
}

int main()
{
	int m, n,count2=0;
	cin >> m >> n;
	int num[10000] = { 0 };//求出前10000个素数
	int count = 0, flag = 1;
	FindNum(num);
	for (int i = m - 1; i < n; i++)
	{
		cout << num[i];
		count2++;
		if (count2 % 10 == 0||i==n-1)//控制格式输出
			cout << endl;
		else
			cout << " ";
	}
	return 0;
}

