#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int sum = 0,count1=0,count2=0;
	getline(cin, s);//用getline输入
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a'&&s[i] <= 'z')//不区分大小写计算英文字母序号和
			sum += s[i] - 'a'+1;
		else if(s[i] >= 'A'&&s[i] <= 'Z')
			sum += s[i] - 'A' + 1;
	}

	while (sum != 0)//十进制转成二进制
	{
		if (sum % 2 == 0)
			count1++;
		else
			count2++;
		sum /= 2;
	}

	cout << count1 << " " << count2 << endl;

	return 0;
}
