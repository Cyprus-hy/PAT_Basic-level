#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int flag = 0,count=0;//指数正负标记,记录要移动的位数
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'E')
		{
			for (int j = i+2; j <s.length(); j++)//移动的位数
				count = count * 10 + s[j] - '0';
			if (s[i + 1] == '-')//指数小于0
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
		if (flag)//指数为负数
		{
			cout << "0.";
			for (int i = 0; i < count - 1; i++)//前面添0
				cout << "0";
			for (int j = 1; s[j] != 'E'; j++)
			{
				if (s[j] != '.')
					cout << s[j];
			}
			cout << endl;
		}
		else//指数为正
		{
			int tem=0;
			for (int i=3; s[i] != 'E'; i++)
				tem++;//小数位数
			if (count < tem)//存在小数点
			{
				cout << s[1];
				for (int i = 3; i < 3 + count; i++)
					cout << s[i];//输出小数点前的
				cout << ".";
				for (int j = 3 + count; j < 3 + tem; j++)//小数点后的
					cout << s[j];
			}
			else
			{
				for (int i = 1; s[i] != 'E'; i++)//先输出前面的，后面添0
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
	else//指数为0需要单独判断
	{
		for (int i = 1; s[i] != 'E'; i++)
			cout << s[i];
		cout << endl;
	}
	return 0;
}