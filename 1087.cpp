#include<iostream>

using namespace std;

const int MAX = 11000;

int main()
{
	int n,count=0;
	cin >> n;
	int sum[MAX] = { 0 };//结果数组用于记录有多少个不同的值

	for (int i = 1; i <= n; i++)//1到n的遍历
	{
		int res = 0;
		res = i / 2 + i / 3 + i / 5;
		sum[res]++;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (sum[i])
			count++;
	}

	cout << count << endl;
	return 0;
}