#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int n;
	cin >> s >> n;

	for (int i = 0; i < n-1; i++)
	{
		string tem ;//用于存放变换后的数字
		for (int j = 0; j < s.length(); )
		{
			tem += s[j];//首先存放前一项的某位数字
			int count = 0;
			//计数该数字有多少个
			while (s[j] == tem[tem.length()-1])//出现新的数字时退出计数
			{
				j++;
				count++;
			}
			tem += count + '0';//该数字的个数
		}
		s = tem;
	}

	cout << s << endl;
	return 0;
}