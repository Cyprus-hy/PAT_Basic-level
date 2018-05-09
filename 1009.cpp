#include<iostream>
#include<string>

using namespace std;

int main()
{
	int count=1, a[80] = { 0 };//标记空格位置
	string s;
	getline(cin, s);
	a[0] = -1;//字符串开始位置
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			a[count] = i;//空格位置
			count++;//空格个数
		}
	}
	a[count] = s.length();//最后记录下字符串末尾的位置
	for (int j = count -1; j >= 0; j--)//从倒数第二个空格位置开始
	{
		for (int k = a[j] + 1; k < a[j + 1]; k++)//输出两个空格间的内容
			cout << s[k];
		if (j != 0)
			cout << " ";//末尾无空格
		else
			cout << endl;
	}
	return 0;
}