#include<iostream>
using namespace std;

int main()
{
	int count = 0, flag = 1, tem, a[10] = { 0 }, b[50] = { 0 };
	for (int i = 0; i<10; i++)
	{
		cin >> a[i];
		if (i != 0 && a[i] != 0 && flag == 1)//找到第一个不为0的数，将其作为首位 
		{
			a[i]--;
			tem = i;
			flag = 0;
		}
		for (int j = 0; j<a[i]; j++)
		{
			b[count] = i;
			count++;//计数 
		}
	}
	cout << tem;
	for (int k = 0; k<count; k++)
	{
		cout << b[k];
	}

}