#include<iostream>

using namespace std;

typedef struct Mystruct
{
	int score;//����
	int all;//����ѡ�����
	int right;//��ȷ��ѡ�����
	string option;//��ȷѡ��
}Test;

int main()
{
	int n, m;
	cin >> n >> m;
	Test temp[100];//��¼ÿ�������Ϣ
	int count[100] = { 0 };//��¼ÿ����Ĵ������

	for (int i = 0; i < m; i++)
	{
		cin >> temp[i].score >> temp[i].all >> temp[i].right;//����ÿ��������֡�ѡ�����Լ���ȷѡ����
		for (int j = 0; j < temp[i].right; j++)
		{
			char c;
			cin >> c;
			temp[i].option += c;//������ȷѡ��
		}
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;//�ܳɼ�
		for (int j = 0; j<m;j++)
		{
			int a, flag = 1;
			char c1,c2;
			string s;
			cin >> c1 >> a;//ѡ����
			for (int k = 0; k < a; k++)//ѡ�������
			{
				char c;
				cin >> c;
				s += c;
			}
			cin >> c2;

			if (a != temp[j].right)//��ѡ������������ȷѡ�����
				flag=0;

			else
			{
				for (int k = 0; k < a; k++)
				{
					if (s[k] != temp[j].option[k])//ѡ����
					{
						flag = 0;
						break;
					}
				}
			}

			if (flag)//flagΪ1��ʾ�������ȷ
				sum += temp[j].score;
			else//flag=0��ʾ����ѡ����
				count[j]++;
		}

		cout << sum << endl;
	}

	int max = 0;

	for (int i =0; i < m; i++)//�Ҵ����������
	{
		if (count[i] > max)
			max = count[i];
	}

	if (max == 0)//û�д�
		cout << "Too simple\n";
	else
	{
		cout << max;
		for (int i = 0; i < m; i++)
		{
			if (max == count[i])//Ѱ�Ҵ�������������
				cout << " " << i + 1;
		}
		cout << endl;
	}

	return 0;
}