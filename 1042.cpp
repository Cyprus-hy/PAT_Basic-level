#include<iostream>
#include<string>

using namespace std;

int main()
{
	int max=0,count[26] = { 0 };//��26��Ӣ����ĸ����
	char ch;
	string s;
	getline(cin, s);//getline���Զ���ո�
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] - 'a' >= 0 && s[i] - 'z' <= 0)//����Ӣ����ĸ
			count[s[i] - 'a']++;
		else if (s[i] - 'A' >= 0 && s[i] - 'Z' <= 0)
			count[s[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++)//Ѱ�ҳ��ִ���������ĸ
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

