#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void cal(string &s)//大数加法
{
	string tem, res;
	int carry=0;//进位
	tem = s;
	reverse(tem.begin(), tem.end());//reverse函数可以进行反转

	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] - '0' + tem[i] - '0' + carry < 10)//两者相加小于10
		{
			res += s[i] - '0' + tem[i] - '0' + carry + '0';
			carry = 0;//进位为0
		}
		else//两者相加大于10
		{
			res += s[i] - '0' + tem[i] - '0' + carry-10 + '0';
			carry = 1;//进位为1
		}
	}

	if (carry == 1)//最高位的进位
		res += '1';

	reverse(res.begin(), res.end());//反转后的才是真正的和
	cout << s << " + " << tem << " = " << res << endl;
	s = res;
}

bool IsHuiwen(string s)//判断是否回文
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
	while (!IsHuiwen(s) && count < 10)//当已经转成回文或步骤大于10步时退出
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