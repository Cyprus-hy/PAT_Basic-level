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
		sum[school] += score;//sum���ڴ洢ÿ��ѧУ���ܷ֣��±�ΪѧУ
	}
	for (int i = 1; i < num; i++)//Ѱ�����ֵ
	{
		if (sum[i] > sum[max])
			max = i;
	}
	cout << max <<" "<< sum[max] << endl;
	return 0;
}