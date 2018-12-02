#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();
	string low[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };//低位
	string high[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };//进位高位
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		if (s[0] >= '0'&&s[0] <= '9')//地球文转火星文
		{
			int a = 0;
			vector<int>b;

			stringstream ss;//字符串转换成的十进制数
			ss << s;
			ss >> a;
			ss.clear();

			do//转换成13进制
			{
				int temp = a % 13;
				a /= 13;
				b.push_back(temp);
			} while (a != 0);

			if (b[0] == 0)
			{
				if (b.size() == 2)
					cout << high[b[1] - 1] << endl;
				else
					cout << "tret\n";
			}
			else
			{
				for (int j = b.size() - 1; j >= 1; j--)//反序输出
				{
					cout << high[b[j] - 1] << " ";
				}
				cout << low[b[0]] << endl;
			}
			
		}

		else//火星文转地球文
		{
			if (s == "tret")//0要单独讨论
				cout << "0\n";

			else if(s.length()==3)//一位的火星文
			{
				for (int j = 1; j < 13; j++)
				{
					if (low[j] == s)
					{
						cout << j << endl;
						break;
					}
				}

				for (int j = 0; j < 13; j++)//注意这里很坑
				{
					if (high[j] == s)
					{
						cout << (j+1)*13 << endl;
						break;
					}
				}
			}

			else//一位以上火星文
			{
				int sum = 0;
				for (int j = 0; j < s.length(); j = j + 4)
				{
					if (j + 4 >= s.length())//最低位
					{
						for (int k = 0; k < 13; k++)
						{
							if (s[j] == low[k][0] && s[j + 1] == low[k][1] && s[j + 2] == low[k][2])//寻找相等的字符串
							{
								sum = sum*13+k;
								break;
							}
						}
					}

					else//高位
					{
						for (int k = 0; k < 12; k++)
						{
							if (s[j] == high[k][0] && s[j + 1] == high[k][1] && s[j + 2] == high[k][2])//寻找相等的字符串
							{
								sum = sum * 13 + k + 1;
								break;
							}
						}
					}
				}
				cout << sum << endl;
			}
		}
	}
	return 0;
}