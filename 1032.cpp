#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
	int num, sum[100001] = { 0 },max=1;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int school, score;
		cin >> school >> score;
		sum[school] += score;//sum用于存储每个学校的总分，下标为学校
	}
	for (int i = 1; i < num; i++)//寻找最大值
	{
		if (sum[i] > sum[max])
			max = i;
	}
	cout << max <<" "<< sum[max] << endl;
	return 0;
}