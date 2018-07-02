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
		getline(cin, s);//字符串带空格

		for (int i = 0; i < s.length(); )
		{
			int count = 0;
			char c = s[i];
			while (c == s[i])//记录相同的字符c有多少个
			{
				i++;
				count++;
			}

			if (count > 1)//整数型转化成字符串型
			{
				string t;
				while (count != 0)
				{
					t += count % 10 + '0';
					count /= 10;
				}
				reverse(t.begin(), t.end());//反转

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
			int count = 0;//相同字符的个数
			if (s[i] >= '0'&&s[i] <= '9')
			{
				while (s[i] >= '0'&&s[i] <= '9')//字符型转整数型
				{
					count = count * 10 + s[i] - '0';
					i++;
				}

				for (int j = 0; j < count; j++)
					cout << s[i];
				i++;//别忘i要后移
			}

			else//一个字符就直接输出
				cout << s[i++];
		}
	}

	return 0;
}