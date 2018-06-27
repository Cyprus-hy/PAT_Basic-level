#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

typedef struct Mystruct
{
	int ID;
	int rank;//����
	int flag;//flag�����Ƿ��Ѿ���ȡ����Ʒ
	int award;//0�������ش󽱣�1����С���ˣ�2�����ɿ���
}Team;

int main()
{
	int n, k;
	vector<Team> temp;
	cin >> n;
	int count[10001] = { 0 };
	string s[5] = { "Mystery Award","Minion","Chocolate","Are you kidding?","Checked" };//��Ӧ�ַ���

	for (int i = 2; i <= 10000; i++)//�õ�2��10000�ڵ���������
	{
		int flag = 1;
		for (int j = 2; j <= sqrt(i); j++)//������ƽ������ʡʱ��
		{
			if (i%j == 0)
			{
				flag = 0; 
				break;
			}
		}
		if (flag)//�������Ϊ1
			count[i] = 1;
	}

	for (int i = 0; i < n; i++)//��������
	{
		Team t;
		cin >> t.ID;
		t.flag = 0;
		t.rank = i + 1;
		if (t.rank == 1)//�ھ��õ����ش�
			t.award = 0;
		else if (count[t.rank] == 1)//����Ϊ�����ĵõ�С����
			t.award = 1;
		else//�����ӵõ��ɿ���
			t.award = 2;
		temp.push_back(t);
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int e,isFind=0;
		cin >> e;//���������

		for (int k = 0; k < n; k++)
		{
			if (temp[k].ID == e)
			{
				isFind = 1;//�ҵ��ö���
				if (!temp[k].flag)//��δ�����Ʒ
				{
					printf("%04d", e);//ע�����С��1000�ĶӺţ�ǰ��Ҫ��0��printf������%04dʵ��
					cout << ": " << s[temp[k].award] << endl;
					temp[k].flag = 1;
				}
				else//��ȡ����Ʒ��
				{
					printf("%04d", e);
					cout<< ": " << s[4] << endl;
				}
			}
		}

		if (!isFind)//δ�ҵ��ö���
		{
			printf("%04d", e);
			cout<< ": " << s[3] << endl;
		}
	}
	return 0;
}