#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void cal(string &s)//�����ӷ�
{
	string tem, res;
	int carry=0;//��λ
	tem = s;
	reverse(tem.begin(), tem.end());//reverse�������Խ��з�ת

	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] - '0' + tem[i] - '0' + carry < 10)//�������С��10
		{
			res += s[i] - '0' + tem[i] - '0' + carry + '0';
			carry = 0;//��λΪ0
		}
		else//������Ӵ���10
		{
			res += s[i] - '0' + tem[i] - '0' + carry-10 + '0';
			carry = 1;//��λΪ1
		}
	}

	if (carry == 1)//���λ�Ľ�λ
		res += '1';

	reverse(res.begin(), res.end());//��ת��Ĳ��������ĺ�
	cout << s << " + " << tem << " = " << res << endl;
	s = res;
}

bool IsHuiwen(string s)//�ж��Ƿ����
{
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

int main()
{
	string s;
	cin >> s;
	int count = 0;
	while (!IsHuiwen(s) && count < 10)//���Ѿ�ת�ɻ��Ļ������10��ʱ�˳�
	{
		cal(s);
		count++;
	}

	if (IsHuiwen(s))
		cout << s << " is a palindromic number.\n";
	else
		cout << "Not found in 10 iterations.\n";
	return 0;
}