#include<iostream>
#include<string>

using namespace std;

int main()
{
	string error, s1, s2;
	getline(cin, error);
	getline(cin, s1);

	//�ϵ���û�л���
	if (error.find('+') == error.npos)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			char c = s1[i];
			//ʵ�����
			if (error.find(toupper(c)) == error.npos)
				s2 += c;
		}
	}

	//�ϵ���������
	else
	{
		for (int i = 0; i < s1.length(); i++)
		{
			char c = s1[i];
			//ʵ�������ע���ʱ�ж��Ƿ��Ǵ�д��ĸ
			if (error.find(toupper(c)) == error.npos&&(c<65||c>90))
				s2 += c;
		}
	}
	cout << s2 << endl;
	return 0;
}