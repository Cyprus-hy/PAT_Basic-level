#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int flag = 0,count=0;//ָ���������,��¼Ҫ�ƶ���λ��
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'E')
		{
			for (int j = i+2; j <s.length(); j++)//�ƶ���λ��
				count = count * 10 + s[j] - '0';
			if (s[i + 1] == '-')//ָ��С��0
			{
				flag = 1;
			}
			break;
		}
	}
	if (s[0] == '-')
		cout << "-";
	if (count)
	{
		if (flag)//ָ��Ϊ����
		{
			cout << "0.";
			for (int i = 0; i < count - 1; i++)//ǰ����0
				cout << "0";
			for (int j = 1; s[j] != 'E'; j++)
			{
				if (s[j] != '.')
					cout << s[j];
			}
			cout << endl;
		}
		else//ָ��Ϊ��
		{
			int tem=0;
			for (int i=3; s[i] != 'E'; i++)
				tem++;//С��λ��
			if (count < tem)//����С����
			{
				cout << s[1];
				for (int i = 3; i < 3 + count; i++)
					cout << s[i];//���С����ǰ��
				cout << ".";
				for (int j = 3 + count; j < 3 + tem; j++)//С������
					cout << s[j];
			}
			else
			{
				for (int i = 1; s[i] != 'E'; i++)//�����ǰ��ģ�������0
				{
					if (s[i] != '.')
						cout << s[i];
				}
				for (int j = 0; j < count - tem; j++)
					cout << "0";
			}
			cout << endl;
		}
	}
	else//ָ��Ϊ0��Ҫ�����ж�
	{
		for (int i = 1; s[i] != 'E'; i++)
			cout << s[i];
		cout << endl;
	}
	return 0;
}