#include<iostream>

using namespace std;

int main()
{
	int n,real=1,row=3;
	char c;
	cin >> n >> c;
	for (;real<=n; row += 2)
		real += row * 2;
	real -= (row-2) * 2;//实际打印的符号数
	row -= 4;//打印的行数
	for (int i = row; i >=3; i -=2 )//打印上半部分
	{
		for (int j = 0; j < (row - i) / 2; j++)//空格
			cout << " ";
		for (int j = 0; j < i; j++)
			cout << c;
		cout << endl;
	}
	for (int i = 1; i <= row; i += 2)//下半部分
	{
		for (int j = 0; j < (row - i) / 2; j++)
			cout << " ";
		for (int j = 0; j < i; j++)
			cout << c;
		cout << endl;
	}
	cout << n - real << endl;
	return 0;
}