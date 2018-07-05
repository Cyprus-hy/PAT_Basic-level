#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	//s用于存放手眼口对应的符号集，注意每个符号包含1到4个非空字符，所以s是二维的vector变量
	vector<vector<string>> s;
	int k;

	for (int i = 0; i < 3; i++)
	{
		string ss;
		getline(cin, ss);
		vector<string> tem;
		int k = 0;
		for (int j = 0; j < ss.length();j++)
		{
			if (ss[j] == '[')
			{
				while (k++ < ss.length())
				{
					if (ss[k] == ']')
						break;
				}
				//将左括号与右括号之间的字符串（即符号）存入tem中，substr第一个参数是起始位置，
				//第二个参数是长度
				tem.push_back(ss.substr(j + 1, k - j - 1));
			}
		}
		s.push_back(tem);
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		//注意对输入数据是否合法的判断
		if (a > s[0].size() || a <= 0 || b > s[1].size() || b <= 0 || c > s[2].size() || c <= 0 ||
			d > s[1].size() || d <= 0 || e > s[0].size() || e <= 0)
		{
			cout<<"Are you kidding me? @\\/@" << endl; 
		}
		else//注意输出有括号
		{
			cout << s[0][a-1] << "(" << s[1][b-1] << s[2][c-1] << s[1][d-1] << ")" << s[0][e-1] << endl;
		}
	}
	return 0;
}