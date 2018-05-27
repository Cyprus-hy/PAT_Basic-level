#include<string>
#include<iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int count[10] = { 0 };
	for (int i = 0; i < s.length(); i++)
		count[s[i] - '0']++;
	for (int j = 0; j < 10; j++)
	{
		if (count[j] > 0)
			cout << j << ":" << count[j] << endl;
	}
	return 0;
}