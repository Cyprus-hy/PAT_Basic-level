#include<iostream>
#include<math.h>

using namespace std;

void search(int *a, int num)
{
	int flag = 1,k=0;
	for (int i = 2; i <= num; i++)//��2������numѰ������
	{
		for (int j = 2; j <=(int) sqrt(i); j++)
		{
			if (i%j == 0)
				flag = 0;//����
		}
		if (flag)
		{
			a[k] = i;//�洢����
			k++;
		}
		flag = 1;
	}
}

int main()
{
	int i_num, count = 0, a[10000] = { 0 };
	cin >> i_num;
	search(a, i_num);//Ѱ������
	for (int i = 0; a[i+1] != 0; i++)//ע����a[i+1]������0
	{
		if (a[i + 1] - a[i] == 2)//����Ҫ���������
			count++;
	}
	cout << count << endl;
	return 0;
}