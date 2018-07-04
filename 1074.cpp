#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string s, a, b,res;
	cin >> s >> a >> b;

	reverse(a.begin(), a.end());//将两个加数与进制表反转
	reverse(b.begin(), b.end());
	reverse(s.begin(), s.end());
	//对于两个加数长度不等的情况，加0进行补齐
	if (a.length() < b.length())
		a.append(b.length() - a.length(), '0');
	else
		b.append(a.length() - b.length(), '0');
	
	int len = (a.length() > b.length()) ? a.length() : b.length();
	//carry为进制，sum为每一位的结果
	int carry = 0,sum=0,i=0;

	for (; i < len; i++)
	{
		if (s[i] == '0')//分类，0代表十进制
		{
			sum = (a[i] - '0' + b[i] - '0' + carry) % 10;
			carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
		}

		else
		{
			sum = (a[i] - '0' + b[i] - '0' + carry) % (s[i] - '0');
			carry = (a[i] - '0' + b[i] - '0' + carry) / (s[i] - '0');
		}
		
		res += sum + '0';
	}

	while(carry)//最高位的进位，一定要记得处理
	{
		if (s[i]!='0')
		{
			sum = carry % (s[i] - '0');
			carry = carry / (s[i] - '0');
		}
		
		else
		{
			sum = carry % 10;
			carry = carry / 10;
		}

		i++;
		res += sum + '0';
	}

	reverse(res.begin(), res.end());//将结果反转

	int k = 0;
	//由于之前进行了补0，结果的前几位可能是0，而这部分0无须输出
	while (res[k] == '0'&&k<res.size())
		k++;
	//可能出现和为0的情况，需要单独输出，不然最后一个测试点过不了
	if (k == res.size())
		cout << "0";
	else
	{
		for (; k < res.size(); k++)
			cout << res[k];
	}

	cout << endl;
	return 0;
}
