#include<iostream>
#include<cmath>

using namespace std;

void FindNum(int *n)//Ѱ��2��1000000�ڵ�����
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
		if (flag == 1)//flag��־�Ƿ�Ϊ����
		{
			*(n+count) = i;
			count++;
		}
		if (count == 10000)//ֻ��Ҫ��ǰ10000������
			break;
		flag = 1;//���ã�һ��Ҫ�ǵ�����
	}
}

int main()
{
	int m, n,count2=0;
	cin >> m >> n;
	int num[10000] = { 0 };//���ǰ10000������
	int count = 0, flag = 1;
	FindNum(num);
	for (int i = m - 1; i < n; i++)
	{
		cout << num[i];
		count2++;
		if (count2 % 10 == 0||i==n-1)//���Ƹ�ʽ���
			cout << endl;
		else
			cout << " ";
	}
	return 0;
}

