#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int count[6] = { 0 };
	for (int i = 0; i < s.length(); i++)//记录六个字符的个数
	{
		if (s[i] == 'P')
			count[0]++;
		else if (s[i] == 'A')
			count[1]++;
		else if (s[i] == 'T')
			count[2]++;
		else if (s[i] == 'e')
			count[3]++;
		else if (s[i] == 's')
			count[4]++;
		else if(s[i]=='t')
			count[5]++;
	}

	do//按照PATest的顺序输出，每输出一个总数就减一，如果个数为0就不输出了
	{
		if (count[0] != 0)
		{
			cout << "P";
			count[0]--;
		}
		if (count[1] != 0)
		{
			cout << "A";
			count[1]--;
		}
		if (count[2] != 0)
		{
			cout << "T";
			count[2]--;
		}
		if (count[3] != 0)
		{
			cout << "e";
			count[3]--;
		}
		if (count[4] != 0)
		{
			cout << "s";
			count[4]--;
		}
		if (count[5] != 0)
		{
			cout << "t";
			count[5]--;
		}
	} while (count[0] != 0 || count[1] != 0 || count[2] != 0 || count[3] != 0 || count[4] != 0 || count[5] != 0);
	cout << endl;

	return 0;
}