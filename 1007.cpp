#include<iostream>
#include<math.h>

using namespace std;

void search(int *a, int num)
{
	int flag = 1,k=0;
	for (int i = 2; i <= num; i++)//从2遍历到num寻找素数
	{
		for (int j = 2; j <=(int) sqrt(i); j++)
		{
			if (i%j == 0)
				flag = 0;//合数
		}
		if (flag)
		{
			a[k] = i;//存储素数
			k++;
		}
		flag = 1;
	}
}

int main()
{
	int i_num, count = 0, a[10000] = { 0 };
	cin >> i_num;
	search(a, i_num);//寻找素数
	for (int i = 0; a[i+1] != 0; i++)//注意是a[i+1]不等于0
	{
		if (a[i + 1] - a[i] == 2)//满足要求的素数对
			count++;
	}
	cout << count << endl;
	return 0;
}