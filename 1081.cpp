#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();//�ڽ�����n��Ҫgetchar()��ȡһ�»��з�������getline�������з��ᱻ����getline��

	for (int i = 0; i < n; i++)
	{
		string s;
		//flag1�����ַ������Ƿ��в��Ϸ��ַ���flag2�����ַ������Ƿ������룬flag3�����ַ������Ƿ�������
		int flag1 = 1, flag2 = 0, flag3 = 0;
		getline(cin, s);

		if (s.length() >= 6)//�ַ������ȴ��ڵ���6
		{
			for (int j = 0; j < s.length(); j++)
			{
				if ((s[j] >= 'a'&&s[j] <= 'z') || (s[j] >= 'A'&&s[j] <= 'Z'))//��ĸ
					flag2 = 1;
				else if (s[j] >= '0'&&s[j] <= '9')//����
					flag3 = 1;
				else if (s[j] == '.')
					;
				else //�Ƿ��ַ�
				{
					flag1 = 0;
					break;
				}
			}
		}

		if (s.length() < 6)
			cout << "Your password is tai duan le.\n";
		else
		{
			if (flag1 == 0)//ע���жϵ����ȼ������ж��Ƿ��зǷ��ַ�
				cout << "Your password is tai luan le.\n";
			else
			{
				if (flag2 == 0 && flag3 == 1)
					cout << "Your password needs zi mu.\n";
				if (flag2 == 1 && flag3 == 0)
					cout << "Your password needs shu zi.\n";
				if (flag2 == 1 && flag3 == 1)
					cout << "Your password is wan mei.\n";
			}
		}
	}
	return 0;
}

