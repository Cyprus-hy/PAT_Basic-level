#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Mystruct
{
	int a;
	int b[100];//���ÿ�������ܱ����ǵ�����
	int sum;//�ܸ��ǵ����ֵĸ���
	int flag;//����Ƿ�Ϊ�ؼ���,1���ǹؼ���
}Num;

int search(int *n,int a)//Ѱ������a�ܸ��ǵ���
{
	int i = 0,b=a;//��ֹa�ĸı�
	for (; b != 1; i++)
	{
		if (b % 2 == 0)
		{
			b = b / 2;
			n[i] = b;//�ܸ��ǵ����ִ���������
		}
		else
		{
			b = (3 * b + 1) / 2;
			n[i] = b;//�ܸ��ǵ����ִ���������
		}
	}
	return i;//�����ܸ��ǵĸ���
}

int main()
{
	int i_num, count=0, c[100] = { 0 };
	cin >> i_num;
	Num *tem = new Num[i_num];
	for (int i = 0; i < i_num; i++)
	{
		cin >> tem[i].a;
		tem[i].sum = search(tem[i].b, tem[i].a);//�ܸ��ǵ����ִ���������
		tem[i].flag = 1;//��ʼ��Ϊ1
	}
	for (int i = 0; i < i_num; i++)
	{
		for (int j = 0; j < tem[i].sum; j++)//ÿ�����ĸ�����������
		{
			for (int k = 0; k<i_num; k++)//����֤������
			{
				if (tem[i].b[j] == tem[k].a)
					tem[k].flag = 0;
			}
		}	
	}
	for (int i = 0; i < i_num; i++)
	{
		if (tem[i].flag == 1)//���Ϊ0����Ϊ�ؼ���
		{
			c[count] = tem[i].a;//���ؼ�����������c
			count++;
		}
	}
	sort(c, c + count);
	for (int j = count-1 ; j >0; j--)
		cout << c[j]<<" ";//�Ӵ�С�������
	cout << c[0] << endl;//�����ʽ
	delete []tem;
	return 0;
}