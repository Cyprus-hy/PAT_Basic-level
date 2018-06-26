#include<iostream>
#include<string>

using namespace std;

int main()
{
	int max=0,count[26] = { 0 };//对26个英文字母计数
	char ch;
	string s;
	getline(cin, s);//getline可以读入空格
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] - 'a' >= 0 && s[i] - 'z' <= 0)//计数英文字母
			count[s[i] - 'a']++;
		else if (s[i] - 'A' >= 0 && s[i] - 'Z' <= 0)
			count[s[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++)//寻找出现次数最大的字母
	{
		if (count[i] > max)
		{
			max = count[i];
			ch = 'a' + i;
		}
	}
	cout << ch << " " << max << endl;

	return 0;
}

