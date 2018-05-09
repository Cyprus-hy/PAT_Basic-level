#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a;//大数用字符串表示
	int b, num[1000] = { 0 }, count = 0, res[1000] = { 0 };
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
		num[i] = a[i] - '0';//将字符串每一位转化成数字
	if (a.length() != 1)
	{
		for (int j = 0; j < a.length() - 1; )//注意是小于a.length()-1
		{
			if (num[j] >= b)//不需要借位
			{
				res[count] = num[j] / b;//结果
				num[j] = num[j] % b;//余数留在那位
				count++;//商的位数
			}
			else//借位
			{
				res[count] = (10 * num[j] + num[j + 1]) / b;
				num[j + 1] = (10 * num[j] + num[j + 1]) % b;
				count++;
				j++;//需要借位时才移向下一位
			}
		}
	}
	else//一位数时需要单独判断
	{
		res[count] = num[0]/b;
		count++;
		num[0] = num[0] % b;
	}
	for (int k = 0; k < count; k++)
		cout << res[k];//输出结果
	cout << " " << num[a.length() - 1] << endl;
	return 0;
}