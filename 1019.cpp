#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string s;
	cin >> s;

	//不足四位时前面添0
	while (s.length() < 4)
	{
		s.append("0");
	}

	//四位均相等
	if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3])
	{
		cout<<s<<" - "<<s<<" = "<<"0000\n";
	}

	else
	{
		int num1 = 0, num2 = 0;
		do {
			sort(s.begin(), s.end());//从小到大排序
			string temp = s;
			reverse(s.begin(),s.end());//反转
			
			//字符串转int
			stringstream ss;
			ss << s;
			ss >> num1;
			ss.clear();
			ss << temp;
			ss >> num2;
			ss.clear();

			printf("%04d - %04d = %04d\n", num1, num2,num1-num2);

			ss << (num1 - num2);
			ss >> s;
			s.insert(0, 4 - s.length(), '0');//注意每次更新的时候也要补0
			ss.clear();//更新s
		} while (num1 - num2!=6174);
	}
}