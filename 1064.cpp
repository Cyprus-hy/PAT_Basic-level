#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, num=0,count[100] = { 0 };
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		int sum = 0;
		cin >> s;
		for (int j = 0; j < s.length(); j++)//求各位数字的和
			sum += s[j] - '0';

		if (!count[sum])//如果之前已经出现过就不计数了
			num++;
		count[sum]++;//出现的次数
	}

	cout << num<<endl;

	for (int i = 0; i < 100; i++)
	{
		if (count[i])//出现过
		{
			num--;
			cout << i;
			if (num)//最后一个元素不能输出空格
				cout << " ";
			else
				cout << endl;
		}
	}

	return 0;
}