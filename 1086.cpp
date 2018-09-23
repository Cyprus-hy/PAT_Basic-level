#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
	int a, b, i_res,i;
	cin >> a >> b;
	i_res = a * b;

	stringstream ss;
	string s_res;
	ss << i_res;
	ss >> s_res;//数字到字符串的转化
	
	for (i=s_res.length()-1; i >= 0; i--)//跳过前面的0
	{
		if (s_res[i] != '0')
			break;
	}

	for(;i>=0;i--)
		cout << s_res[i];

	cout << endl;
	return 0;
}
