#include<iostream>

using namespace std;

int main()
{
	int i_num, a[3] = { 0 };
	cin >> i_num;
	for (int i = 2; i_num != 0; i--)//逆序得到三位数的每一位
	{
		a[i] = i_num % 10;
		i_num /= 10;
	}
	for (int j = 0; j < a[0]; j++)//百位输出
		cout << "B";
	for (int j = 0; j < a[1]; j++)//十位输出
		cout << "S";
	for (int j = 1; j <= a[2]; j++)//个位输出
		cout << j;
	cout << endl;
	return 0;
}