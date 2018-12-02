#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s;
	int sum = 0;
	getline(cin, s);

	//记录每个A之前有多少个P，每个T之前有多少个A
	int p = 0, a=0, t = 0;
	vector<int>pbeforea;
	vector<int>abeforet;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'T')
			t++;
	}

	//对于每一个A，记录它前面有多少个P，后面有多少个T，两者相乘即为这个A能组成的PAT个数，最后累加即可
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'P')
			p++;
		else if (s[i] == 'A')
		{
			a++;
			sum += p * t % 1000000007;
			sum %= 1000000007;
		}
		else
		{
			t--;
		}
	}

	cout << sum << endl;
	return 0;
}