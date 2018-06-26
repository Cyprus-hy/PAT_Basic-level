#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string a, b,c;
	cin >> a >> b;
	int len_a = a.length();
	int len_b = b.length();
	char str[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };//从数字到字符的转换

	for (int i = 0; i < len_a / 2; i++)//因为个位是第一位，所以我们可以先将字符串颠倒一下
		swap(a[i], a[len_a - 1 - i]);
	for (int i = 0; i < len_b / 2; i++)
		swap(b[i], b[len_b - 1 - i]);

	if (len_a < len_b)//对于长度更短的字符串，需要对其补0，注意append函数的用法
		a.append(len_b - len_a, '0');
	else
		b.append(len_a - len_b, '0');

	for (int i = 0; i < a.length(); i++)
	{
		int x = 0;
		if (i % 2 == 0)//因为不存在第0位，所以对奇偶的操作恰好相反
			x = (a[i] - '0' + b[i] - '0') % 13;
		else
			x = (b[i] - a[i] + 10) % 10;
		c += str[x];
	}

	for (int i = c.length() - 1; i >= 0; i--)//之前进行了颠倒，所以输出需要逆序
		cout << c[i];
	cout << endl;

	return 0;
}