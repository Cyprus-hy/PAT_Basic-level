#include<iostream>

using namespace std;

int main()
{
	double a, b,time;
	int h, m, s;
	cin >> a >> b;
	time = (b - a) / 100;//用double型，保证数据精度
	h = time / 3600;//小时
	m = (time - 3600 * h) / 60;
	s = (time - 3600 * h - m * 60) + 0.5;//四舍五入
	if (h < 10)//一位数需要进行补全
		cout << "0";
	cout << h << ":";
	if (m < 10)
		cout << "0";
	cout << m << ":";
	if (s < 10)
		cout << "0";
	cout << s << endl;
	return 0;
}