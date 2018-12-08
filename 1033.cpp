#include<iostream>
#include<string>

using namespace std;

int main()
{
	string error, s1, s2;
	getline(cin, error);
	getline(cin, s1);

	//上档键没有坏掉
	if (error.find('+') == error.npos)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			char c = s1[i];
			//实际输出
			if (error.find(toupper(c)) == error.npos)
				s2 += c;
		}
	}

	//上档键坏掉了
	else
	{
		for (int i = 0; i < s1.length(); i++)
		{
			char c = s1[i];
			//实际输出，注意此时判断是否是大写字母
			if (error.find(toupper(c)) == error.npos&&(c<65||c>90))
				s2 += c;
		}
	}
	cout << s2 << endl;
	return 0;
}