#include<iostream>
using namespace std;

int main()
{
	int count = 0, flag = 1, tem, a[10] = { 0 }, b[50] = { 0 };
	for (int i = 0; i<10; i++)
	{
		cin >> a[i];
		if (i != 0 && a[i] != 0 && flag == 1)//�ҵ���һ����Ϊ0������������Ϊ��λ 
		{
			a[i]--;
			tem = i;
			flag = 0;
		}
		for (int j = 0; j<a[i]; j++)
		{
			b[count] = i;
			count++;//���� 
		}
	}
	cout << tem;
	for (int k = 0; k<count; k++)
	{
		cout << b[k];
	}

}