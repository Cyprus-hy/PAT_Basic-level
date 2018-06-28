#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string answer;
	char tem[4] = { '1','2','3','4' };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			string s;
			cin >> s;
			if (s[2] == 'T')//正确答案
				answer += tem[s[0] - 'A'];//选项对应的数字
		}
	}

	cout << answer << endl;
	return 0;
}