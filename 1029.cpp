#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1, s2,res;
	getline(cin, s1);
	getline(cin, s2);

	//s2ȫת�ɴ�д
	for (int i = 0; i < s2.length(); i++)
		s2[i] = toupper(s2[i]);

	for (int i = 0; i < s1.length(); i++)
	{
		char c = toupper(s1[i]);//ת���ɴ�д
		if (s2.find(c) == s2.npos&&res.find(c) == res.npos)//���δ��s2�Լ�res�г���
			res += c;
	}
	cout << res << endl;
	return 0;
}
