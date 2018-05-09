#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Mystruct
{
	int a;
	int b[100];//存放每个数字能被覆盖的数字
	int sum;//能覆盖的数字的个数
	int flag;//标记是否为关键数,1就是关键数
}Num;

int search(int *n,int a)//寻找数字a能覆盖的数
{
	int i = 0,b=a;//防止a的改变
	for (; b != 1; i++)
	{
		if (b % 2 == 0)
		{
			b = b / 2;
			n[i] = b;//能覆盖的数字存入数组中
		}
		else
		{
			b = (3 * b + 1) / 2;
			n[i] = b;//能覆盖的数字存入数组中
		}
	}
	return i;//返回能覆盖的个数
}

int main()
{
	int i_num, count=0, c[100] = { 0 };
	cin >> i_num;
	Num *tem = new Num[i_num];
	for (int i = 0; i < i_num; i++)
	{
		cin >> tem[i].a;
		tem[i].sum = search(tem[i].b, tem[i].a);//能覆盖的数字存入数组中
		tem[i].flag = 1;//初始化为1
	}
	for (int i = 0; i < i_num; i++)
	{
		for (int j = 0; j < tem[i].sum; j++)//每个数的覆盖数的数组
		{
			for (int k = 0; k<i_num; k++)//待验证的数组
			{
				if (tem[i].b[j] == tem[k].a)
					tem[k].flag = 0;
			}
		}	
	}
	for (int i = 0; i < i_num; i++)
	{
		if (tem[i].flag == 1)//标记为0代表为关键数
		{
			c[count] = tem[i].a;//将关键数存入数组c
			count++;
		}
	}
	sort(c, c + count);
	for (int j = count-1 ; j >0; j--)
		cout << c[j]<<" ";//从大到小逆序输出
	cout << c[0] << endl;//输出格式
	delete []tem;
	return 0;
}