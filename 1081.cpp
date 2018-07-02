#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();//在接收完n后要getchar()读取一下换行符才能用getline，否则换行符会被读进getline中

	for (int i = 0; i < n; i++)
	{
		string s;
		//flag1代表字符串中是否有不合法字符，flag2代表字符串中是否有密码，flag3代表字符串中是否有数字
		int flag1 = 1, flag2 = 0, flag3 = 0;
		getline(cin, s);

		if (s.length() >= 6)//字符串长度大于等于6
		{
			for (int j = 0; j < s.length(); j++)
			{
				if ((s[j] >= 'a'&&s[j] <= 'z') || (s[j] >= 'A'&&s[j] <= 'Z'))//字母
					flag2 = 1;
				else if (s[j] >= '0'&&s[j] <= '9')//数字
					flag3 = 1;
				else if (s[j] == '.')
					;
				else //非法字符
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
			if (flag1 == 0)//注意判断的优先级，先判断是否有非法字符
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

