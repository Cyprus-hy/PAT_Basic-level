#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char c;
	string s;
	cin >> c;
	getchar();

	if (c == 'C')
	{
		string tem;
		getline(cin, s);//�ַ������ո�

		for (int i = 0; i < s.length(); )
		{
			int count = 0;
			char c = s[i];
			while (c == s[i])//��¼��ͬ���ַ�c�ж��ٸ�
			{
				i++;
				count++;
			}

			if (count > 1)//������ת�����ַ�����
			{
				string t;
				while (count != 0)
				{
					t += count % 10 + '0';
					count /= 10;
				}
				reverse(t.begin(), t.end());//��ת

				for (int k = 0; k < t.size(); k++)
					tem += t[k];
			}
			
			tem += c;
		}
		cout << tem<<endl;
	}

	else
	{
		getline(cin, s);
		for (int i = 0; i < s.size(); )
		{
			int count = 0;//��ͬ�ַ��ĸ���
			if (s[i] >= '0'&&s[i] <= '9')
			{
				while (s[i] >= '0'&&s[i] <= '9')//�ַ���ת������
				{
					count = count * 10 + s[i] - '0';
					i++;
				}

				for (int j = 0; j < count; j++)
					cout << s[i];
				i++;//����iҪ����
			}

			else//һ���ַ���ֱ�����
				cout << s[i++];
		}
	}

	return 0;
}