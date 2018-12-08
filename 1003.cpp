#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct Mystruct
{
	string s;
	int countp;//P�ĸ���
	int countt;//T�ĸ���
	int counta1;//P���A�ĸ���
	int counta2;//P��T֮��A�ĸ���
	int counta3;//T�ұ�A�ĸ���
	int flag;//�ж��Ƿ��������ַ�
	int p;//P��λ��
	int t;//T��λ��
	int isTrue;//�Ƿ���ȷ
}PAT;

int main()
{
	int n;
	cin >> n;
	vector<PAT>pp;

	for (int i = 0; i < n; i++)
	{
		PAT tem;
		//��ʼ��
		tem.counta1 = 0;
		tem.counta2 = 0;
		tem.counta3 = 0;
		tem.countp = 0;
		tem.countt = 0;
		tem.flag = 1;
		tem.p = 0;
		tem.t = 0;
		tem.isTrue = 0;
		cin >> tem.s;

		for (int j = 0; j < tem.s.length(); j++)
		{
			//�ж��ַ������Ƿ��������ַ�
			if (tem.s[j] != 'P'&&tem.s[j] != 'A'&&tem.s[j] != 'T')
			{
				tem.flag = 0;
				break;
			}

			//����
			if (tem.s[j] == 'P')
			{
				tem.countp++;
				tem.p = j;//��¼P��λ��
			}
			else if (tem.s[j] == 'T')
			{
				tem.countt++;
				tem.t = j;//��¼T��λ��
			}

		}

		pp.push_back(tem);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < pp[i].s.length(); j++)
		{
			if (pp[i].s[j] == 'A')
			{
				//P��ߵ�A
				if (j < pp[i].p)
					pp[i].counta1++;
				//P��T֮���A
				else if (pp[i].p < j&&j < pp[i].t)
					pp[i].counta2++;
				//T�ұߵ�A
				else
					pp[i].counta3++;
			}
				
		}

		//ע��P��T�ĸ�������Ϊ1��P��T֮���A�ĸ���Ҫ���ڵ���1
		if (pp[i].countp != 1 || pp[i].countt != 1 || pp[i].counta2 < 1)
			pp[i].flag = 0;

		if (!pp[i].flag)
			cout << "NO\n";
		else
		{
			//ע����ɣ���ͷ��A�ĸ��� * �м��A�ĸ��� = ��β��A�ĸ���
			if (pp[i].counta1*pp[i].counta2 == pp[i].counta3)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}