#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int i_num, tem[1000] = { 0 }, count[5] = { 0 };//计数器
	double b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0,sum4=0,mean4,max;
	cin >> i_num;
	for (int i = 0; i < i_num; i++)
	{
		cin >> tem[i];
		if (tem[i] % 5 == 4)
			max = tem[i];//先得到对5取模为4的数
	}
	for (int j = 0; j < i_num; j++)
	{
		if (tem[j] % 10 == 0)
			b1 += tem[j];
		else if (tem[j] % 5 == 1)
		{
			b2 += pow(-1, count[1])*tem[j];//混合运算
			count[1]++;
		}
		else if (tem[j] % 5 == 2)
			count[2]++;
		else if (tem[j] % 5 == 3)
		{
			sum4 += tem[j];//和
			count[3]++;
		}
		else if (tem[j] % 5 == 4)
		{
			if (max < tem[j])
				max = tem[j];
			count[4]++;
		}
	}
	mean4 = sum4 / count[3];//平均值
	if (b1 == 0)//一直判断
		cout << "N ";
	else
		cout << b1 << " ";
	if (count[1] == 0)
		cout << "N ";
	else
		cout << b2 << " ";
	if (count[2] == 0)
		cout << "N ";
	else
		cout << count[2] << " ";
	if (count[3] == 0)
		cout << "N ";
	else
		printf("%.1f ", mean4);
	if (count[4] == 0)
		cout << "N";
	else
		cout << max;
	cout << endl;
	return 0;
}
